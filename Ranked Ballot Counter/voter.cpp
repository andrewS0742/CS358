/*
	Andrew Schmidt
	2-18-24
	Ballot counting program for ranked ballots
*/

#include "voter.h"

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
