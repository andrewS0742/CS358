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

bool Candidate::operator>(Candidate& other)
{
	return (this->numVotes > other.numVotes) ? true : false;
}

void Candidate::addVote()
{
	numVotes++;
}

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
		if (match) cList[matchIndex].addVote();
		else cList.push_back(Candidate(candidateName));
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
	//might have to change in the event of a tie
	if (!isSorted)
	{
		isSorted = true;
		std::sort(cList.begin(), cList.end(), [](Candidate& a, Candidate& b) {return a.getNumVotes() > b.getNumVotes(); });
		//cList.sort();
	}

	for (auto c : cList)
	{
		std::cout << c.getNumVotes() << "-> " << c.getName() << std::endl;
	}

	return cList[0];
}
