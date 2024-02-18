#include "main.hpp"

ResultWindow::ResultWindow(n::FormHelper* fh, RoundData rd)
	:window(fh->add_window(n::Vector2i(0, 0), "Election Results"))
{
	window = fh->add_window(n::Vector2i(0, 0), "Election Results");
	//n::ref<n::Window> resultWindow = gui->add_window(n::Vector2i(0, 0), "Election Results");
	fh->add_group("Round Results");
	fh->add_variable("Round Number", rd.roundNumber);
	
	std::string outcome = "";
	switch (rd.getRoundResult())
	{
	case RoundResult::WINNER:
		outcome = "Winner";
		break;
	case RoundResult::TIED:
		outcome = "Tie";
		break;
	case RoundResult::NEWROUND:
		outcome = "New Round";
		break;
	}

	fh->add_variable("Round Result", outcome);
}
