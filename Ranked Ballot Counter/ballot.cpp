#include "main.hpp"

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

Candidate Ballot::runFirstRound()
{
	for (auto voter : voterList)
	{
		ucl.tryAddCandidate(voter.getFirstVote());
	}
	return ucl.getMostVoted();
}
