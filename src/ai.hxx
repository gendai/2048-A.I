void AI::start()
{
  bo.set_rand();
  bo.set_rand();
  while (!bo.is_over())
  {
    do_next_move();
    bo.set_rand();
    std::cout << "\033[2J\033[1;1H";
    bo.print_board_color();
  }
}

void AI::do_next_move()
{
  auto alup = expminmax(bo.get_move_up(), 6, 1);
  auto aldw = expminmax(bo.get_move_down(), 6, 1);
  auto alle = expminmax(bo.get_move_left(), 6, 1);
  auto alri = expminmax(bo.get_move_right(), 6, 1);
  auto max = std::max(alup, std::max(aldw, std::max(alle, alri)));
  if (max == alup)
    bo.move_up();
  else if (max == aldw)
    bo.move_down();
  else if (max == alle)
    bo.move_left();
  else
    bo.move_right(); 
}

int AI::expminmax(Board bo, int depth, int player)
{
  int p;
  if (bo.is_over())
    return 2;
  if (depth == 0)
    return heuri(bo);
  if (player)
  {
    p = INT_MIN;
    p = std::max(p, expminmax(bo.get_move_up(), depth - 1, 0));
    p = std::max(p, expminmax(bo.get_move_down(), depth - 1, 0));
    p = std::max(p, expminmax(bo.get_move_left(), depth - 1, 0));
    p = std::max(p, expminmax(bo.get_move_right(), depth - 1, 0));
  }
  else
  {
    p = 0;
    for (auto i = 0; i < 16; ++i)
    {
      if (bo.get_case_value(i) == 0)
        p += (0.9 * expminmax(bo.set_case_value_cpy(i, 0x1), depth - 1, 1)
              + (0.1 * expminmax(bo.set_case_value_cpy(i, 0x2), depth - 1, 1)));
    }
  }
  return p;
}

int AI::heuri(Board bo)
{
  int res = 0;
  for (auto i = 0; i < 16; ++i)
    res += bo.get_case_value(i);
  return res;
}
