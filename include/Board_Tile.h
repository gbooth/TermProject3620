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
    Board_Tile(const std::string&, const std::string& = "123456780");
    std::list<Board_Tile> nextConfigs() const;
    bool operator<(const Board_Tile&) const;
    bool operator==(const Board_Tile&) const;

    bool betterBoard(const Board_Tile&) const;
    bool isSolution() const;
    std::string getMoves() const;

    int numMoves() const;
    int Manhattan_Distance(const Board_Tile&);
    int Manhattan_Distance();

    Board_Tile move(moveDir, int) const;
    unsigned int findTile(char) const;

    void output(std::string) const;
  private:
    std::string config;
    std::string movesFromStart;

    std::string goalConfig;
    int manDistSum;
};

#endif