#pragma once
#include "candidate.h"
#include "voter.h"

/*

	A class or set of classes that represents the round result shall have an interface that will
		Return the round number for which this is a round result
		Indicate if there is a winner or a tie
		Return the winner candidate round result if there is a winner
		Return the list of tied candidate round result if there is a tie
		Return the list of all candidate round results for the input indicating the round in ascending order for number of votes
		Each candidate round result shall have an interface that will :
			Return the candidates name
			Return the round number
			Return the number of votes received by the candidate in the round
			Return the percent of votes received by each candidate
			Return the indication if the candidate was eliminated

*/

enum class RoundResult {WINNER, TIED, NEWROUND};

//acts like an archive of a round, core of round processing is done by Ballot
class RoundData
{

	void processRound();

public:

	int roundNumber;
	RoundResult roundResult;
	UniqueCandidateList roundUCL;

	RoundData(int roundNum, UniqueCandidateList roundUcl);

	std::vector<Candidate> getMostVoted();
	RoundResult getRoundResult();
	
};


class Ballot
{
	//voter list
	//candidate list
	//way to keep track of rounds (recursive?)

	//constructor takes file path and reads file

	std::vector<Voter> voterList;
	UniqueCandidateList ucl;
	std::vector<RoundData> roundList;

public:
	std::string pathList;

	Ballot();


	void loadBallotFromFile(std::vector<std::string> ballotFilePaths);
	Candidate runRound();

	std::vector<RoundData> getResults();

};

