#include "board.hh"

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
	bo.set_row(3, 0x1111);
	std::cout << "Terminale mode board print (after set_row): " << std::endl;
  bo.print_board_term();
  std::cout << "Beautify board print (after set_row): " << std::endl;
  bo.print_board_color();
	/*bo.set_col(0, 0x0020);
	std::cout << "Terminale mode board print (after set_col): " << std::endl;
  bo.print_board_term();
  std::cout << "Beautify board print (after set_col): " << std::endl;
  bo.print_board_color();*/
	bo.move_right();
	std::cout << "Terminale mode board print (after move_left): " << std::endl;
  bo.print_board_term();
  std::cout << "Beautify board print (after move_left): " << std::endl;
  bo.print_board_color();
	return 0;
}
