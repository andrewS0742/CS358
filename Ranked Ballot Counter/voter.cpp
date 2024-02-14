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

Voter::Voter(std::string firstVote, std::string secondVote, std::string thirdVote, std::string id)
	:firstVote(firstVote), secondVote(secondVote), thirdVote(thirdVote), id(id)
{
}

std::string Voter::getId()
{
	return id;
}

/*

	If the first slot doesn’t have a candidate selected, then the second choice is used in the “first round”.
	If the second slot also doesn’t have a candidate selected, then the third choice is used in the first round.  
	If no slot if filled, then it is a no vote.

*/

std::string Voter::getFirstVote()
{
	if (firstVote != "") return firstVote;
	else if (secondVote != "") return secondVote;
	else if (thirdVote != "") return thirdVote;
	else return "ERROR";
}

std::string Voter::getSecondVote()
{
	if (firstVote != "" && secondVote != "") return secondVote;
	else if (secondVote != "" && thirdVote != "") return thirdVote;
	else return "ERROR";
}

std::string Voter::getThirdVote()
{
	if (firstVote != "" && secondVote != "" && thirdVote != "") return thirdVote;
	else return "ERROR";
}
