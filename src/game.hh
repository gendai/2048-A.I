#ifndef GAME_HH
#define GAME_HH

#include <cstdint>

uint16_t LEFT_TABLE[65536];
uint16_t RIGHT_TABLE[65536];

void init_left_table();
void init_right_table();
void init_tables();

uint16_t get_left_table(uint16_t value);
uint16_t get_right_table(uint16_t value);
#include "game.hxx"

#endif
