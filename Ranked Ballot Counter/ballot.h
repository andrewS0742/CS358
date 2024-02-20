/*
	Andrew Schmidt
	2-18-24
	Ballot counting program for ranked ballots
*/

#pragma once
#include "candidate.h"
#include "voter.h"
#include <nanogui/nanogui.h>
namespace n = nanogui;

/*

	A class or set of classes that represents the round result shall have an interface that will
		Return the round number for which this is a round result
		Indicate if there is a winner or a tie
		Return the winner candidate round result if there is a winner
		Return the list of tied candidate round result if there is a tie
		Return the list of all candidate round results for the input indicating the round in ascending order for number of votes
		Each candidate round result shall have an interface that will :
			Return the candidates name
			Return the round number
			Return the number of votes received by the candidate in the round
			Return the percent of votes received by each candidate
			Return the indication if the candidate was eliminated

*/

/// <summary>
/// The result of a round, ending with a winner, tie, or another round
/// </summary>
enum class RoundResult {WINNER, TIED, NEWROUND};

/// <summary>
/// Stores information about the result of an election round
/// </summary>
class RoundData
{
	/// <summary>
	/// Processes round information from a round candidate list. 
	/// Is called in the constructor
	/// </summary>
	void processRound();

public:

	/// <summary>
	/// ballot count round number
	/// </summary>
	int roundNumber;

	/// <summary>
	/// Result of the count round
	/// </summary>
	RoundResult roundResult;

	/// <summary>
	/// List of unique candidates that counts number of votes
	/// </summary>
	UniqueCandidateList roundUCL;

	/// <summary>
	/// Constructor for Round Data
	/// </summary>
	/// <param name="roundNum">Round Number</param>
	/// <param name="roundUcl">List of unique candidates</param>
	RoundData(int roundNum, UniqueCandidateList roundUcl);

	/// <summary>
	/// returns the most voted for candidate.
	/// If there is a tie, it returns all tied candidates
	/// </summary>
	/// <returns>vector of candidates</returns>
	std::vector<Candidate> getMostVoted();

	/// <returns>Round result</returns>
	RoundResult getRoundResult();
	
};

/// <summary>
/// A ballot of voters and their choices, loaded from a csv spreadsheet
/// </summary>
class Ballot
{
	std::vector<Voter> voterList;
	UniqueCandidateList ucl;
	std::vector<RoundData> roundList;

public:
	/// <summary>
	/// Joined list of paths of loaded csv files
	/// </summary>
	std::string pathList = "No files selected";

	/// <summary>
	/// Loads ballot from multiple formatted csv spreadsheet
	/// </summary>
	/// <param name="ballotFilePaths">vector of the full paths of csv files meaning to be loaded</param>
	void loadBallotFromFile(std::vector<std::string> ballotFilePaths);

	/// <summary>
	/// Runs rounds and adds to roundList
	/// </summary>
	void runRound();

	/// <returns>returns vector of round data</returns>
	std::vector<RoundData> getResults();

};

class ResultWindow
{
	int roundNumber = 0;
	std::string roundResult = "";
	std::string roundWinner = "";
	int numVotes = 0;

	n::Label* resultsBox;

	n::ref<n::Window> resultWindow;
	n::FormHelper* gui;

public:
	ResultWindow(n::FormHelper* g);

	void loadData(RoundData rd);
};