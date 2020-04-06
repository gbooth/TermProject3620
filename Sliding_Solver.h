/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#ifndef SLIDING_SOLVER_INCLUDED
#define SLIDING_SOLVER_INCLUDED

#include <string>
#include <iostream>
#include <queue>

#include "Board_Tile.h"

class Sliding_Solver {
  public:
    Sliding_Solver(const std::string&);
    std::string Solve_Puzzle(const Board_Tile&);
  private:
    std::priority_queue<Board_Tile> tileQueue;
};

#endif