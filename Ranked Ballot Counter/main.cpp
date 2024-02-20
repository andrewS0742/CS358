/*
	Andrew Schmidt
	2-18-24
	Ballot counting program for ranked ballots
*/

#include "ballot.h"

//https://github.com/d99kris/rapidcsv
#include "rapidcsv.h"

//https://github.com/wjakob/nanogui
#include <nanogui/nanogui.h>

namespace n = nanogui;

/*
	TODO: need to think of getting next vote for voter with blank vote
	TODO: eliminating candidates prior to a new round depending on conditions
	TODO: implement testing
*/

int main()
{
	Ballot b;
	bool showResults = false;
	//std::vector<ResultWindow> rdList;

	n::init();
	n::Screen* s = new n::Screen(n::Vector2i(500, 500), "Ranked Ballot Counter");
	n::FormHelper* gui = new n::FormHelper(s);

	std::vector<ResultWindow> rwList{};
	rwList.push_back(ResultWindow(gui));
	rwList.push_back(ResultWindow(gui));
	rwList.push_back(ResultWindow(gui));

	n::ref<n::Window> window = gui->add_window(n::Vector2i(0, 0), "Ballot Counter");
	gui->add_group("File Selection");
	gui->add_button("Select Files", [&]() 
		{
			//rdList.clear();
			b.loadBallotFromFile(n::file_dialog({ { "csv", "Comma Seperated Spreadsheet" } }, false, true)); 
			b.runRound(); 

			std::vector<RoundData> rd = b.getResults();
			//int minLength = (rwList.size() <= rd.size()) ? rwList.size() : rd.size();
			for (int i = 0; i < std::min(rwList.size(), rd.size()); i++)
			{
				rwList[i].loadData(rd[i]);
			}

			gui->refresh(); 
		});

	s->set_visible(true);
	s->perform_layout();

	window->center();
	//resultWindow1->set_visible(false);
	//resultWindow1->center();
	
	n::mainloop();
	
	n::shutdown();

	delete s;
	delete gui;
	return 0;
}

