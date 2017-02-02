#pragma once

#include "board.hh"
#include "game.hh"
#include <algorithm>
#include <climits>

class AI
{

  public:
    void start();
    void do_next_move();
    int expminmax(Board bo, int depth, int player);
    int heuri(Board bo);
  private:
    Board bo;
};

#include "ai.hxx"
