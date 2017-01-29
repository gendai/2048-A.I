int Board::get_case_value(int index) const
{
  uint64_t maskt = this->mask << (4 * (15 - index));
  uint64_t casetmp = this->cases & maskt;
  int value = casetmp >> ((15 - index) * 4);
  int real_value = value == 0 ? 0 : std::round(std::pow(2, value));
  return static_cast<int>(real_value);
}

void Board::set_case_value(int index, uint64_t value)
{
  uint64_t vtemp = value << (4 * (15 - index));
  uint64_t casestmp = this->cases & (~(this->mask << (4 * (15 - index))));
  this->cases = casestmp | vtemp;
}

void Board::print_board_term() const
{
  for (int i = 0; i < 16; ++i)
  {
    std::cout << (std::to_string(get_case_value(i)));
    if ((i + 1) % 4 == 0)
      std::cout << std::endl;
    else
      std::cout << " ";
  }
}

std::string Board::board_case_format(int value) const
{
  switch (value)
  {
    case 2:
      return std::string("\033[0;47m");
    case 4:
      return std::string("\033[0;43m");
    case 8:
      return std::string("\033[0;45m");
    case 16:
      return std::string("\033[0;46m");
    case 32:
      return std::string("\033[0;44m");
    case 64:
      return std::string("\033[0;42m");
    case 128:
      return std::string("\033[0;41m");
    case 256:
      return std::string("\033[0;42m");
    default:
      return std::string("\033[0;40m");
  }
}

void Board::print_board_color() const
{
  std::cout << "\033[3;37m+-----+-----+-----+-----+\033[0m" << std::endl;
  for (int i = 0; i < 16; ++i) {
    std::cout << "\033[3;37m|\033[0m";
    int value = get_case_value(i);
    std::string zeros = "    ";
    if (value > 9999)
      zeros = "";
    else if (value > 999)
      zeros = " ";
    else if (value > 99)
      zeros = "  ";
    else if (value > 9)
      zeros = "   ";
    std::cout << board_case_format(value) + zeros + std::to_string(value) +
                     "\033[0m";
    if ((i + 1) % 4 == 0)
      std::cout
          << "\033[3;37m|\033[0m\n\033[3;37m+-----+-----+-----+-----+\033[0m"
          << std::endl;
  }
}

uint16_t Board::get_row(int index) const
{
	uint64_t maskrow = 0x000000000000ffff;
	uint64_t rowv = this->cases & (maskrow << (16 * (3 - index)));
	uint16_t res = rowv >> (16 * (3 - index));
	return res;
}

uint16_t Board::get_col(int index) const
{
	uint64_t maskcol = 0xf000f000f000f000;
	uint64_t maskval = 0xffff000000000000;
	uint64_t colv = this->cases & (maskcol >> (index * 4));
	uint16_t res = ((colv & maskval) >> (4 * (12 - index))) + ((colv & (maskval >> 16)) >> (4 * (9 - index)))
								+ ((colv & (maskval >> 32)) >> (4 * (6 - index))) + ((colv & (maskval >> 48)) >> (4 * (3 - index)));
	return res;
}

void Board::set_row(int index, uint16_t value)
{
	uint64_t value64 = value;
	uint64_t vtemp = value64 << (16 * (3 - index));
	uint64_t rowmask = 0x000000000000ffff;
  uint64_t casestmp = this->cases & (~(rowmask << (16 * (3 - index))));
	this->cases = casestmp | vtemp;
}

void Board::set_col(int index, uint16_t value)
{
	uint64_t c1 = value >> 12;
	uint64_t c2 = (value >> 8) & 0xF;
	uint64_t c3 = (value >> 4) & 0xF;
	uint64_t c4 = value & 0xF;
	set_case_value(index, c1);
	set_case_value(4 + index, c2);
	set_case_value(8 + index, c3);
	set_case_value(12 + index, c4);
}

void Board::move_left()
{
	set_row(0, get_left_table(get_row(0)));
	set_row(1, get_left_table(get_row(1)));
	set_row(2, get_left_table(get_row(2)));
	set_row(3, get_left_table(get_row(3)));
}

void Board::move_right()
{
	set_row(0, get_right_table(get_row(0)));
	set_row(1, get_right_table(get_row(1)));
	set_row(2, get_right_table(get_row(2)));
	set_row(3, get_right_table(get_row(3)));
}

void Board::move_up()
{
	set_col(0, get_left_table(get_col(0)));
	set_col(1, get_left_table(get_col(1)));
	set_col(2, get_left_table(get_col(2)));
	set_col(3, get_left_table(get_col(3)));
}

void Board::move_down()
{
	set_col(0, get_right_table(get_col(0)));
	set_col(1, get_right_table(get_col(1)));
	set_col(2, get_right_table(get_col(2)));
	set_col(3, get_right_table(get_col(3)));
}

void Board::set_rand()
{
	uint64_t val = 1 + (next_rand() % 10) / 9;
	while (true)
	{
			uint64_t pos = next_rand() % 16;
			if (get_case_value(pos) != 0)
				continue;
			set_case_value(pos, val);
			break;
	}
}
