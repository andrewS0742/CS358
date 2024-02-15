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
		
		TODO: need to think of getting next vote for voter with blank vote
		TODO: eliminating candidates prior to a new round depending on conditions
		TODO: implement testing
		TODO: gui interface

		https://philippegroarke.com/posts/2018/c++_ui_solutions/
		https://github.com/ocornut/imgui
		https://github.com/Immediate-Mode-UI/Nuklear
*/

int main()
{
	//TODO: figure out a local path that works
	//Ballot b{ "C:\\Users\\pixture\\source\\repos\\CS358\\Ranked Ballot Counter\\SmallListBallots.csv" };
	//Ballot b{ "C:\\Users\\pixtu\\Source\\Repos\\andrewS0742\\CS358\\Ranked Ballot Counter\\SmallListBallots.csv" };
	Ballot b{ "C:\\Users\\pixtu\\Source\\Repos\\andrewS0742\\CS358\\Ranked Ballot Counter\\LargeListBallots.csv" };

	std::cout << b.runRound().getName();

	return 0;
}

