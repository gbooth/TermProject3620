/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#include "Board_Tile.h"
#include <string>
#include <iostream>
#include <cstdlib>

Board_Tile::Board_Tile(const std::string& conf, const std::string& moves, const std::string& goal) : 
  config{conf}, movesFromStart{moves}, goalConfig{goal} {}

std::list <Board_Tile> Board_Tile::nextConfigs() {
    unsigned int i = this->findTile('0');
    assert(i == 0 || 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8);
    std::list <Board_Tile> possibleConfigs;
    switch(i){
        case 0 : {
            possibleConfigs.push_back(move(D, i));
            possibleConfigs.push_back(move(R, i));
            return possibleConfigs;
        }
        case 1 : {
            possibleConfigs.push_back(move(L, i));
            possibleConfigs.push_back(move(D, i));
            possibleConfigs.push_back(move(R, i));
            return possibleConfigs;
        }
        case 2 : {
            possibleConfigs.push_back(move(L, i));
            possibleConfigs.push_back(move(D, i));
            return possibleConfigs;
        }
        case 3 : {
            possibleConfigs.push_back(move(U, i));
            possibleConfigs.push_back(move(D, i));
            possibleConfigs.push_back(move(R, i));
            return possibleConfigs;
        }
        case 4 : {
            possibleConfigs.push_back(move(U, i));
            possibleConfigs.push_back(move(L, i));
            possibleConfigs.push_back(move(D, i));
            possibleConfigs.push_back(move(R, i));
            return possibleConfigs;
        }
        case 5 : {
            possibleConfigs.push_back(move(U, i));
            possibleConfigs.push_back(move(L, i));
            possibleConfigs.push_back(move(D, i));
            return possibleConfigs;
        }
        case 6 : {
            possibleConfigs.push_back(move(U, i));
            possibleConfigs.push_back(move(R, i));
            return possibleConfigs;
        }
        case 7 : {
            possibleConfigs.push_back(move(U, i));
            possibleConfigs.push_back(move(L, i));
            possibleConfigs.push_back(move(R, i));
            return possibleConfigs;
        }
        case 8 : {
            possibleConfigs.push_back(move(U, i));
            possibleConfigs.push_back(move(L, i));
            return possibleConfigs;
        }
    }
}    

bool Board_Tile::operator<(const Board_Tile& boardTwo) const {
    assert(manDistSum != -1 && boardTwo.manDistSum != -1);
    return this->manDistSum < boardTwo.manDistSum;
}

int Board_Tile::numMoves() const {
    return movesFromStart.size();
}

int Board_Tile::Manhattan_Distance(const Board_Tile& goal) {
    char key;
    int tileGoal;
    int total = 0;
    goalConfig = goal.config;
    for(int i = 0; i < 9; i++) {
        key = config[i];
        tileGoal = goal.findTile(key);
        manDist[(int)key] = abs(i%3 - tileGoal%3) + abs(i/3 - tileGoal/3);
    }
    for(int i = 0; i < 9; i++)
        total += manDist[i];
    return total;
}

Board_Tile Board_Tile::move(moveDir dir, int emptyLoc) const {
    switch(dir) {
        case U : {
            assert(emptyLoc != 0 && 1 && 2);
            
        }
    }
}
unsigned int Board_Tile::findTile(char tile) const {
    unsigned int i;
    for(i = 0; i < 9; i++)
        if(config[i] == tile)
            return i;
    assert(false);
    return -1;
}