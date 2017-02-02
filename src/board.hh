/**
 ** \file ./src/board.hh
 ** \brief Define the Board and its functions.
 */

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
    
    /// Return the value of the case at \a index.
    /// \param index  index of the case from the board.
    /// \return the power of 2 giving the value of the case.
    int get_case_value(int index) const;
    
    /// Set the \a value of the case at \a index.
    /// \param index  index of the case from the board.
    /// \param value  the value to set the case to.
    void set_case_value(int index, uint64_t value);

    Board set_case_value_cpy(int index, uint64_t value);

    /// Print the board values separated by spaces.
    void print_board_term() const;
    
    
    /// Print the board with colors and style.
    void print_board_color() const;

    /// Get the ansi color code for the printer.
    /// \param value  the value of the case.
    /// \return a string containing the ansi color code of the corresponding
    ///         value for the printer.
    std::string board_case_format(int value) const;
   
    /// Return the row value (uint16_t) at \a index.
    /// \param index  index of the row.
    /// \return a uint16_t representation in which each case has 4 bits.
    uint16_t get_row(int index) const;
    
    /// Return the column value (uint16_t) at \a index.
    /// \param index  index of the column.
    /// \return a uint16_t representation in which each case has 4 bits.
    uint16_t get_col(int index) const;

    /// Set the \a value of the row at \a index.
    /// \param index  index of the row.
    /// \param value  the value to set the row to.
    void set_row(int index, uint16_t value);

    /// Set the \a value of the column at \a index.
    /// \param index  index of the column.
    /// \param value  the value to set the column to.
    void set_col(int index, uint16_t value);
   
    /// Operate a left move of all cases. 
    void move_left();
    
    /// Operate a right move of all cases.
    void move_right();

    /// Operate a up move of all cases.
    void move_up();

    /// Operate a down move of all cases.
    void move_down();

    /// Operate a left move of all cases. 
    Board get_move_left();
    
    /// Operate a right move of all cases.
    Board get_move_right();

    /// Operate a up move of all cases.
    Board get_move_up();

    /// Operate a down move of all cases.
    Board get_move_down();

    /// Put a 2 or 4 on a random empty case.
    void set_rand();

    /// Check if the game is over, no move possible.
    /// \return true if the game is over, false otherwise.
    bool is_over() const;
    
    /// Check if a down move is valid.
    /// \return true if a down move is valid, false otherwise.
    bool can_move_down() const;
   
    /// Check if a up move is valid.
    /// \return true if a up move is valid, false otherwise.
    bool can_move_up() const;
   
    /// Check if a left move is valid.
    /// \return true if a left move is valid, false otherwise.
    bool can_move_left() const;

    /// Check if a right move is valid.
    /// \return true if a right move is valid, false otherwise.
    bool can_move_right() const; 

    void set_cases(uint64_t casen)
    {
      this->cases = casen;
    }

    uint64_t get_cases()
    {
      return this->cases;
    }

  private:

    /// The full board representation, each case is represented on 4 bits.
    uint64_t cases = 0;
};

#include "board.hxx"
