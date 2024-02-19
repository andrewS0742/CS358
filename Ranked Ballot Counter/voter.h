#pragma once
#include <string>

class Voter
{
	//list of three votes as strings
	
	//get candidate (index) to access candidate list after construction

	std::string csvString;

	//easier to keep votes as 3 vars
	std::string firstVote;
	std::string secondVote;
	std::string thirdVote;
	std::string id;

public:
	Voter (std::string firstVote, std::string secondVote, std::string thirdVote, std::string id);

	std::string getId();
	std::string getFirstVote();
	std::string getSecondVote();
	std::string getThirdVote();

};

