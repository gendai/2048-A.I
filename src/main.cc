#include "board.hh"
#include <ctime>
#include <cstdlib>

std::string CLEAR_SCREEN = "\033[2J\033[1;1H";

int play_game()
{
 	Board bo;
  init_tables();
	bo.set_case_value(0, 4);
  bo.set_case_value(6, 2);
  bo.set_case_value(11, 5);
  bo.set_case_value(8, 9);
	bo.print_board_color();
	bo.set_rand();
	bo.print_board_color();
	return 0;
}

int launch_ai()
{
	std::cout << "Started A.I" << std::endl;
	return 0;
}

int main()
{
	std::srand(std::time(0));
	Initialize(std::rand());
 	std::string input = "";
	std::cout << "Play 2048 (0) or launch A.I (1): ";
	getline(std::cin, input);
	if (input == "0")
		play_game();
	else
		launch_ai();
	return 0;
}
