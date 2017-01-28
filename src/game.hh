#ifndef GAME_HH
#define GAME_HH

#include <cstdint>

uint16_t LEFT_TABLE[65536];
uint16_t RIGHT_TABLE[65536];
uint16_t UP_TABLE[65536];
uint16_t DOWN_TABLE[65536];

void init_left_table();
void init_right_table();
void init_up_table();
void init_down_table();
void init_tables();

#include "game.hxx"

#endif
