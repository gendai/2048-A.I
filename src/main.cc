#include "board.hh"
#include "game.hh"

int main()
{
  Board bo;
  bo.set_case_value(0, 4);
  bo.set_case_value(6, 2);
  bo.set_case_value(11, 5);
  bo.set_case_value(8, 9);
  std::cout << "Terminale mode board print: " << std::endl;
  bo.print_board_term();
  std::cout << "Beautify board print: " << std::endl;
  bo.print_board_color();
	init_tables();
  return 0;
}
