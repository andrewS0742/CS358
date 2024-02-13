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

	bool operator>(Candidate& other);
};

class UniqueCandidateList
{
	std::vector<Candidate> cList;
	bool isSorted = false;

public:
	UniqueCandidateList() {};

	void tryAddCandidate(std::string candidateName);
	void sortByVote();

	Candidate get(int index);
	int getSize();
	Candidate getMostVoted();

};

