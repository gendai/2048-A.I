#include "board.hh"
#include "ai.hh"
#include <ctime>
#include <cstdlib>

std::string CLEAR_SCREEN = "\033[2J\033[1;1H";

int play_game()
{
  Board bo;
  init_tables();
  bo.set_rand();
  bo.set_rand();
  bo.print_board_color();
  while (!bo.is_over())
  {
    std::string input = "";
    getline(std::cin, input);
    if (input == "u" && bo.can_move_up())
      bo.move_up();
    else if (input == "d" && bo.can_move_down())
      bo.move_down();
    else if (input == "l" && bo.can_move_left())
      bo.move_left();
    else if (input == "r" && bo.can_move_right())
      bo.move_right();
    else
      continue;
    std::cout << CLEAR_SCREEN;
    bo.set_rand();
    bo.print_board_term();
    bo.print_board_color();
  }
  std::cout << CLEAR_SCREEN;
  std::cout << "Game Over\n";
  bo.print_board_color();
  return 0;
}

int launch_ai()
{
  std::cout << "Started A.I" << std::endl;
  AI ai;
  ai.start();
  return 0;
}

int main()
{
  init_tables();
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
