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
