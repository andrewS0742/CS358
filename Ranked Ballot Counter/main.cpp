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
	Ballot b;
	bool showResults = false;

	n::init();
	n::Screen* s = new n::Screen(n::Vector2i(500, 500), "TEST");
	n::FormHelper* gui = new n::FormHelper(s);

	n::ref<n::Window> window = gui->add_window(n::Vector2i(0, 0), "Ballot Counter");
	gui->add_group("File Selection");
	gui->add_button("Select Files", [&]() 
		{
			b.loadBallotFromFile(n::file_dialog({ { "csv", "Comma Seperated Spreadsheet" } }, false, true)); 
			b.runRound(); 
			showResults = true; 
			gui->refresh(); 
		});
	gui->add_variable("Selected Files", b.pathList, false);

	n::ref<n::Window> resultWindow = gui->add_window(n::Vector2i(0, 0), "Election Results");
	gui->add_group("Round Results");
	gui->add_button("Recalculate Results", [&]()
		{
			b.runRound();
			std::vector<RoundData> rr = b.getResults();

			for (int i = 0; i < rr.size(); i++)
			{
				//cannot add lables at run time
				gui->add_variable("Round Number", rr[i].roundNumber, false);
			}

			gui->refresh();
		});
	

	s->set_visible(true);
	s->perform_layout();

	window->center();
	resultWindow->set_visible(true);
	resultWindow->center();
	
	n::mainloop();
	
	n::shutdown();

	delete s;
	delete gui;
	return 0;
}

