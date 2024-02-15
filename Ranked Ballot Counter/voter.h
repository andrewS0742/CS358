#include "main.hpp"

class Voter
{
	//list of three votes as strings
	
	//get candidate (index) to access candidate list after construction

	std::string csvString;

	//TODO: turn votes into list to simplify logic
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

