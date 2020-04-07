/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#ifndef SLIDING_SOLVER_INCLUDED
#define SLIDING_SOLVER_INCLUDED

#include <string>
#include <iostream>
#include <queue>
#include <list>

#include "Board_Tile.h"

class Sliding_Solver {
  public:
    Sliding_Solver(const std::string&, const std::string& = "");
    std::string Solve_Puzzle();
  private:
    Board_Tile* initialBoard;
    std::priority_queue<Board_Tile> tileQueue;
    std::list<Board_Tile> boardInQueue;
    std::list<Board_Tile> boardsExpanded;

    std::list<Board_Tile>::const_iterator contains(const Board_Tile&) const;
};

#endif