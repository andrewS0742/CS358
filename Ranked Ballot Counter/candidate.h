#include "main.hpp"

class Candidate
{
	//string for candidate name
	//int for number of votes gotten

	//get name
	//increment count
	//get count

	std::string name;
	int numVotes;

public:
	Candidate(std::string name);

	void addVote();

	std::string getName();
	int getNumVotes();
};

class UniqueCandidateList
{
	std::vector<Candidate> cList;

public:
	UniqueCandidateList() {};

	void tryAddCandidate(std::string candidateName);

	Candidate get(int index);
	int getSize();

};

