#include "main.hpp"

class Voter
{
	//list of three votes as strings
	
	//get candidate (index) to access candidate list after construction
private:
	std::string csvString;

	std::string id;
	std::string firstVote;
	std::string secondVote;
	std::string thirdVote;

public:
	Voter(std::string csvLine);

	std::string getId();
	std::string getFirstVote();
	std::string getSecondVote();
	std::string getThirdVote();

};

