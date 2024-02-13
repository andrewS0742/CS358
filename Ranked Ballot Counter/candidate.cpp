#include "main.hpp"

Candidate::Candidate(std::string name)
{
	this->name = name;
	numVotes = 0;
}

std::string Candidate::getName()
{
	return name;
}

int Candidate::getNumVotes()
{
	return numVotes;
}

void Candidate::addVote()
{
	numVotes++;
}

void UniqueCandidateList::tryAddCandidate(std::string candidateName)
{
	for (auto c : cList)
	{
		if (candidateName == c.getName())
		{
			c.addVote();
		}
		else
		{
			cList.push_back(Candidate(candidateName));
		}
	}
}

Candidate UniqueCandidateList::get(int index)
{
	//exception if out of bounds
	return cList[index];
}

int UniqueCandidateList::getSize()
{
	return cList.size();
}
