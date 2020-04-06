/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#ifndef BOARD_TILE_INCLUDED
#define BOARD_TILE_INCLUDED

#include <string>
#include <iostream>
#include <list>

enum moveDir {U, L, D, R};

class Board_Tile {
  public:
    Board_Tile(const std::string&, const std::string& = "", const std::string& = "");

    std::list <Board_Tile> nextConfigs();
    bool operator<(const Board_Tile&) const;

    int numMoves() const;
    int Manhattan_Distance(const Board_Tile&);

    Board_Tile move(moveDir, int) const;
    unsigned int findTile(char) const;

  private:
    std::string config;

    std::string goalConfig;
    unsigned int manDist[9];
    int manDistSum = -1;
    std::string movesFromStart;
};

#endif