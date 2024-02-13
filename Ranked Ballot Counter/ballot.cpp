#include "main.hpp"

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
		if (potentialWinner.getNumVotes() / (float)ucl.getSize() > 0.5f)
		{
			roundResult = RoundResult::WINNER;
		}
		else
		{
			roundResult = RoundResult::NEWROUND;
		}
	}
}

RoundData::RoundData(int roundNum, UniqueCandidateList roundUcl)
{
	roundNumber = roundNum;
	ucl = roundUcl;

	processRound();
}

std::vector<Candidate> RoundData::getMostVoted()
{
	std::vector<Candidate> mostVotedList;

	mostVotedList.push_back(ucl.get(0));
	for (int i = 1; i < ucl.getSize(); i++)
	{
		if (ucl.get(i).getNumVotes() == mostVotedList[0].getNumVotes())
		{
			mostVotedList.push_back(ucl.get(i));
		}
		else
		{
			break;
		}
	}
	return mostVotedList;
}

RoundResult RoundData::getRoundResult()
{
	return roundResult;
}

Ballot::Ballot(std::string ballotFilePath)
{
	loadBallotFromFile(ballotFilePath);
}

void Ballot::loadBallotFromFile(std::string ballotFilePath)
{
	std::ofstream of("test.csv");
	of << "test";
	of.close();

	std::ifstream f(ballotFilePath);
	std::string line;

	if (f.good())
	{
		//read and ignore first line
		std::getline(f, line);
		
		while (std::getline(f, line))
		{
			voterList.push_back(line);
		}

		std::cout << "Successfully read csv file" << std::endl;
	}
	else
	{
		std::cout << "Could not open file with path " << ballotFilePath << std::endl;
	}
}

Candidate Ballot::runRound()
{
	/*
	
		Each ballot’s first-choice vote is counted. This is the “first round” of vote counting.

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
		return r.getMostVoted()[0];
	}
	else if (r.getRoundResult() == RoundResult::TIED)
	{
		std::cout << "TIED" << std::endl;
	}
	else if (r.getRoundResult() == RoundResult::NEWROUND)
	{
		std::cout << "NEW ROUND" << std::endl;
	}
	else
	{
		std::cout << "Error" << std::endl;
	}

	
	//Candidate potentialWinner = ucl.getMostVoted();
	//if (potentialWinner.getNumVotes() / (float)ucl.getSize() > 0.5f)
	//{
	//	return potentialWinner;
	//}
	//else
	//{
	//	//preprocess round
	//	//run recursive until winner
	//	return runRound();
	//}
	
	//return ucl.getMostVoted();
}
