#pragma once
#include <string>

/// <summary>
/// A voter in an election ballot
/// </summary>
class Voter
{
	std::string firstVote;
	std::string secondVote;
	std::string thirdVote;
	std::string id;

public:
	/// <summary>
	/// Constructor for voter
	/// </summary>
	/// <param name="firstVote">Voter's first vote as their name string</param>
	/// <param name="secondVote">Voter's second vote as their name string</param>
	/// <param name="thirdVote">Voter's third vote as their name string</param>
	/// <param name="id">Voter's unique ID as a string</param>
	Voter (std::string firstVote, std::string secondVote, std::string thirdVote, std::string id);

	/// <returns>Returns ID as string</returns>
	std::string getId();

	/// <returns>Returns voter's first valid vote. Returns "ERROR" if no valid vote.</returns>
	std::string getFirstVote();

	/// <returns>Returns voter's second valid vote. Returns "ERROR" if no valid vote.</returns>
	std::string getSecondVote();

	/// <returns>Returns voter's third valid vote. Returns "ERROR" if no valid vote.</returns>
	std::string getThirdVote();

};

