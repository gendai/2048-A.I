#pragma once

#include <cstdint>
#include <cmath>
#include <string>
#include <iostream>
#include "game.hh"
#include "rand.hh"

class Board
{
  public:
    int get_case_value(int index) const;
    void set_case_value(int index, uint64_t value);
    void print_board_term() const;
    void print_board_color() const;
    std::string board_case_format(int value) const;
  	uint16_t get_row(int index) const;
		uint16_t get_col(int index) const;
		void set_row(int index, uint16_t value);
		void set_col(int index, uint16_t value);
		void move_left();
		void move_right();
		void move_up();
		void move_down();
		void set_rand();
	private:
    uint64_t cases = 0;
    uint64_t mask = 0x000000000000000f;
};

#include "board.hxx"
