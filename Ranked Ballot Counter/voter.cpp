#include "main.hpp"

Voter::Voter(std::string csvLine)
{
	//read in csv line and assign id and votes
	//std::cout << csvLine << std::endl;
	csvString = csvLine;

	std::vector<std::string> splitString;
	int pos = 0;
	while (pos < csvLine.size())
	{
		pos = csvLine.find(",");
		splitString.push_back(csvLine.substr(0, pos));
		csvLine.erase(0, pos + 1);
	}
	//push back remaining entry from csvLine since it is ignored by find
	splitString.push_back(csvLine);

	//std::cout << splitString.size() << "-> ";
	//for (auto e : splitString)
	//{
	//	std::cout << e << " :: ";
	//}
	//std::cout << std::endl;

	try
	{
		firstVote =		splitString[0];
		secondVote =	splitString[1];
		thirdVote =		splitString[2];
		id =			splitString[3];
	}
	catch (...)
	{
		std::cout << "Could not read an entry in csv file" << std::endl;
	}
}

std::string Voter::getId()
{
	return id;
}

std::string Voter::getFirstVote()
{
	return firstVote;
}

std::string Voter::getSecondVote()
{
	return secondVote;
}

std::string Voter::getThirdVote()
{
	return thirdVote;
}
