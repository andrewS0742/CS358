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

		https://philippegroarke.com/posts/2018/c++_ui_solutions/
		https://github.com/ocornut/imgui
		https://github.com/Immediate-Mode-UI/Nuklear
*/

int main()
{
	Ballot b;
	bool showResults = false;
	std::vector<ResultWindow> rdList;

	n::init();
	n::Screen* s = new n::Screen(n::Vector2i(500, 500), "TEST");
	n::FormHelper* gui = new n::FormHelper(s);

	int roundNumber = 0;
	std::string roundResult = "";
	std::string roundWinner = "";
	int numVotes = 0;

	n::ref<n::Window> resultWindow = gui->add_window(n::Vector2i(0, 0), "Election Results");
	gui->add_group("Round Results");
	gui->add_variable("Round Number", roundNumber, false)->set_fixed_width(200);
	gui->add_variable("Result", roundResult, false);
	gui->add_variable("Winner", roundWinner, false);
	gui->add_variable("Vote Count", numVotes, false);

	n::ref<n::Window> window = gui->add_window(n::Vector2i(0, 0), "Ballot Counter");
	gui->add_group("File Selection");
	gui->add_button("Select Files", [&]() 
		{
			rdList.clear();
			b.loadBallotFromFile(n::file_dialog({ { "csv", "Comma Seperated Spreadsheet" } }, false, true)); 
			b.runRound(); 

			RoundData rd = b.getResults()[0];
			roundNumber = rd.roundNumber;
			roundResult = "SOMETHING";
			roundWinner = rd.getMostVoted()[0].getName();
			numVotes = rd.getMostVoted()[0].getNumVotes();

			showResults = true;
			resultWindow->set_visible(showResults);
			gui->refresh(); 
		});

	s->set_visible(true);
	s->perform_layout();

	window->center();
	resultWindow->set_visible(showResults);
	resultWindow->center();
	
	n::mainloop();
	
	n::shutdown();

	delete s;
	delete gui;
	return 0;
}

