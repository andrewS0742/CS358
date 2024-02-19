#include <algorithm>
#include <iostream>
#include "candidate.h"

//
// CANDIDATE
//
Candidate::Candidate(std::string name)
{
	//if candidate created it already has one vote
	numVotes = 1;
	this->name = name;
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

//
// UNIQUE CANDIDATE LIST
//
void UniqueCandidateList::tryAddCandidate(std::string candidateName)
{
	isSorted = false;
	if (cList.size() == 0) cList.push_back(Candidate(candidateName));
	else
	{
		bool match = false;
		int matchIndex;
		for (int i = 0; i < cList.size(); i++)
		{
			if (candidateName == cList[i].getName())
			{
				matchIndex = i;
				match = true;
			}
		}
		//add if unique, otherwise add vote
		if (match) cList[matchIndex].addVote();
		else cList.push_back(Candidate(candidateName));
	}
}

void UniqueCandidateList::sortByVote()
{
	if (!isSorted)
	{
		//sort by most voted for to least
		std::sort(cList.begin(), cList.end(), [](Candidate& a, Candidate& b) {return a.getNumVotes() > b.getNumVotes(); });
		isSorted = true;
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

Candidate UniqueCandidateList::getMostVoted()
{
	//TODO: might have to change in the event of a tie
	sortByVote();

	for (auto c : cList)
	{
		std::cout << c.getNumVotes() << "-> " << c.getName() << std::endl;
	}

	return cList[0];
}
