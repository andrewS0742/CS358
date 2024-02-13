#include "main.hpp"

/*

	Ranked Ballot Processing

	classes
		voter
		-> contains list of voted for candidates as list, "blank" for blank entry
		-> read from ballot csv

		candidate
		-> contains name of candidate, number of times voted

		ballot
		-> reads in csv
		-> generates list of voters
		-> generates candidates with appropriate number of times voted from voter list
		-> goes through rounds to determine winner
		-> displays election results

	considerations
		need to plan how to read through csv file effectively
		need to think of getting next vote for voter with blank vote
		eliminating candidates prior to a new round depending on conditions
		implement testing
*/

int main()
{
	//figure out a local path that works
	//Ballot b{ "C:\\Users\\pixture\\source\\repos\\CS358\\Ranked Ballot Counter\\SmallListBallots.csv" };
	Ballot b{ "C:\\Users\\pixtu\\Source\\Repos\\andrewS0742\\CS358\\Ranked Ballot Counter\\SmallListBallots.csv" };

	std::cout << b.runRound().getName();

	return 0;
}

