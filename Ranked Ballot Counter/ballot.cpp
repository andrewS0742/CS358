/*
	Andrew Schmidt
	2-18-24
	Ballot counting program for ranked ballots
*/

#include "ballot.h"
#include "rapidcsv.h"

//
// ROUND DATA
//
void RoundData::processRound()
{
	std::vector<Candidate> winnerList = getMostVoted();
	if (winnerList.size() > 1)
	{
		roundResult = RoundResult::TIED;
	}
	else
	{
		Candidate potentialWinner = winnerList[0];
		if (potentialWinner.getNumVotes() / (float)roundUCL.getTotalVotes() > 0.5f)
		{
			roundResult = RoundResult::WINNER;
		}
		else roundResult = RoundResult::NEWROUND;
	}
}

RoundData::RoundData(int roundNum, UniqueCandidateList roundUcl)
	:roundNumber(roundNum), roundUCL(roundUcl)
{
	processRound();
}

std::vector<Candidate> RoundData::getMostVoted()
{
	roundUCL.sortByVote();
	std::vector<Candidate> mostVotedList;
	mostVotedList.push_back(roundUCL.get(0));

	for (int i = 1; i < roundUCL.getSize(); i++)
	{
		if (roundUCL.get(i).getNumVotes() == mostVotedList[0].getNumVotes())
		{
			mostVotedList.push_back(roundUCL.get(i));
		}
		else break;
	}
	return mostVotedList;
}

RoundResult RoundData::getRoundResult()
{
	return roundResult;
}

//
//	BALLOT
//
void Ballot::loadBallotFromFile(std::vector<std::string> ballotFilePaths)
{
	//join paths into one string for display
	pathList = "";
	for (const auto& path : ballotFilePaths)
	{
		pathList += (path + "\n");
	}

	//assumes voter IDs are unique across files
	for (const auto& file : ballotFilePaths)
	{
		rapidcsv::Document doc(file);

		//column lists will correctly include empty strings for blank entries
		std::vector<std::string> fvList = doc.GetColumn<std::string>("First Choice");
		std::vector<std::string> svList = doc.GetColumn<std::string>("Second Choice");
		std::vector<std::string> tvList = doc.GetColumn<std::string>("Third Choice");
		std::vector<std::string> idList = doc.GetColumn<std::string>("VoterID");

		if (fvList.size() == svList.size() && svList.size() == tvList.size() && tvList.size() == idList.size())
		{
			for (int i = 0; i < fvList.size(); i++)
			{
				voterList.push_back(Voter(fvList.at(i), svList.at(i), tvList.at(i), idList.at(i)));
			}
		}
		else std::cout << "ERROR" << std::endl;
	}
}

void Ballot::runRound()
{
	/*
	
		Each ballot�s first-choice vote is counted. This is the �first round� of vote counting.

		If one candidate has more than 50% in the first round, they win.
		If no candidate has more than 50% of the first round, a next round will be needed.

		Prior to the next round of counting,
		any candidate with zero votes is eliminated
		Of the candidates that did get first-choice votes, the candidate with the fewest first-choice votes is also eliminated.
		If there is a tie for the fewest votes received, then all the tied candidates are eliminated unless that eliminates all the candidates.
		If all the candidates would be eliminated due to a tie, announce the final results as the tie.
	
	*/

	for (auto voter : voterList)
	{
		ucl.tryAddCandidate(voter.getFirstVote());
	}

	RoundData r = RoundData(1, ucl);
	roundList.push_back(r);

	if (r.getRoundResult() == RoundResult::WINNER)
	{
		//return r.getMostVoted()[0];
		return;
	}
	else if (r.getRoundResult() == RoundResult::TIED)
	{
		//handle tie
	}
	else if (r.getRoundResult() == RoundResult::NEWROUND)
	{
		//handle new round
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}

std::vector<RoundData> Ballot::getResults()
{
	//stand in since gui does not work properly
	for (auto& round : roundList)
	{
		std::string result = "";
		switch (round.roundResult)
		{
		case RoundResult::WINNER:
			result = "Winner";
			break;
		case RoundResult::TIED:
			result = "Tie";
			break;
		case RoundResult::NEWROUND:
			result = "New Round";
			break;
		}

		std::cout << "Round Number: " << round.roundNumber << std::endl;
		std::cout << "Round Result: " << result << std::endl;
		std::cout << "Most Voted For: " << round.roundUCL.get(0).getName() << " with " << round.roundUCL.get(0).getNumVotes() << " votes" << std::endl;
		std::cout << "Candidate List: " << std::endl;
		for (int i = 0; i < round.roundUCL.getSize(); i++)
		{
			std::cout << round.roundUCL.get(i).getName() << ", " << round.roundUCL.get(i).getNumVotes() << " votes" << std::endl;
		}
		std::cout << std::endl;
	}


	return roundList;
}

ResultWindow::ResultWindow(n::FormHelper* g)
{
	gui = g;
	resultWindow = gui->add_window(n::Vector2i(0, 0), "Election Results");
	gui->add_group("Round Results");
	gui->add_variable("Round Number", this->roundNumber, false)->set_fixed_width(200);
	gui->add_variable("Result", roundResult, false);//set_callback([&](std::string s) {std::cout << s << "something"; });
	gui->add_variable("Most Voted", roundWinner, false);
	gui->add_variable("Vote Count", numVotes, false);
	resultWindow->set_visible(false);
}

void ResultWindow::loadData(RoundData rd)
{
	this->roundNumber = rd.roundNumber;

	switch (rd.roundResult)
	{
	case RoundResult::WINNER:
		roundResult = "Winner";
		break;
	case RoundResult::TIED:
		roundResult = "Tie";
		break;
	case RoundResult::NEWROUND:
		roundResult = "New Round";
		break;
	default:
		break;
	}

	roundWinner = rd.getMostVoted()[0].getName();
	numVotes = rd.getMostVoted()[0].getNumVotes();
	resultWindow->set_visible(true);
	gui->refresh();
}
