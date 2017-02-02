/**
 ** \file ./src/game.hh
 ** \brief Decalre the moves lookup table and initialization functions.
 */

#pragma once

#include <cstdint>

/// The left move lookup table.
uint16_t LEFT_TABLE[65536];

/// The right move lookup table.
uint16_t RIGHT_TABLE[65536];

/// Initialize the LEFT_TABLE.
void init_left_table();

/// Initialize the RIGHT_TABLE.
void init_right_table();

/// Call init_right_table and init_left_table.
void init_tables();

/// Get the value from the LEFT_TABLE.
/// \param value  value of the row or column, which serve as index.
/// \return the corresponding value in the LEFT_TABLE.
uint16_t get_left_table(uint16_t value);

/// Get the value from the RIGHT_TABLE.
/// \param value  value of the row or column, which serve as index.
/// \return the corresponding value in the RIGHT_TABLE.
uint16_t get_right_table(uint16_t value);

#include "game.hxx"
