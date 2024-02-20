/*
	Andrew Schmidt
	2-18-24
	Ballot counting program for ranked ballots
*/

#pragma once
#include <string>
#include <vector>

/// <summary>
/// A candidate in an election ballot
/// </summary>
class Candidate
{
	std::string name;
	int numVotes;

public:
	/// <summary>
	/// Constructor for Candidate Class
	/// </summary>
	/// <param name="name">Name of voted for candidate</param>
	Candidate(std::string name);

	/// <summary>
	/// Adds a vote to the candidate's tally
	/// </summary>
	void addVote();

	/// <summary>
	/// Returns candidate name
	/// </summary>
	/// <returns>std::string candidate name</returns>
	std::string getName();

	/// <summary>
	/// Returns number of votes the candidate has
	/// </summary>
	/// <returns>int number of votes</returns>
	int getNumVotes();
};

/// <summary>
/// A vector of unique election candidates. 
/// Adds a vote to a candidate if it is already in the list.
/// </summary>
class UniqueCandidateList
{
	std::vector<Candidate> cList;
	bool isSorted = false;

public:
	//default constructor

	/// <summary>
	/// Tries to add candidate
	/// if candidate is unique in the list it is added,
	/// otherwise a vote is added to the existing candidate's
	/// vote count
	/// </summary>
	/// <param name="candidateName">std::string name of candidate to try add</param>
	void tryAddCandidate(std::string candidateName);

	/// <summary>
	/// Sorts candidate by vote count, most to least. Will only sort if the list is unsorted
	/// </summary>
	void sortByVote();

	/// <summary>
	/// Gets a candidate at the given index. Throws exception if out of bounds
	/// </summary>
	/// <param name="index">index to get candidate at</param>
	/// <returns>Candidate at index</returns>
	Candidate get(int index);

	/// <returns>Returns int size of candidate list</returns>
	int getSize();
};

