#include "main.hpp"

class Ballot
{
	//voter list
	//candidate list
	//way to keep track of rounds (recursive?)

	//constructor takes file path and reads file

	std::vector<Voter> voterList;
	UniqueCandidateList ucl;

public:

	Ballot(std::string ballotFilePath);

	void loadBallotFromFile(std::string ballotFilePath);

	Candidate runFirstRound();

};

