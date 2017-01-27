#pragma once

#include <cstdint>
#include <cmath>
#include <string>

class Board
{
  public:
    int get_case_value(int index) const;
    void set_case_value(int index, uint64_t value);
    void print_board_term() const;
    void print_board_color() const;
    std::string board_case_format(int value) const;
  private:
    uint64_t cases = 0;
    uint64_t mask = 0x000000000000000f;
};

#include "board.hxx"
