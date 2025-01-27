/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#include "Board_Tile.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <cassert>

Board_Tile::Board_Tile(const std::string& conf, const std::string& goal) : 
  config{conf}, goalConfig{goal}, manDistSum{-1} {}


std::list <Board_Tile> Board_Tile::nextConfigs() const {
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
    return this->manDistSum + movesFromStart.size() > boardTwo.manDistSum + boardTwo.movesFromStart.size();
}

bool Board_Tile::operator==(const Board_Tile& boardTwo) const {
    return config == boardTwo.config && goalConfig == boardTwo.goalConfig;
}

bool Board_Tile::betterBoard(const Board_Tile& boardTwo) const {
    if(*this == boardTwo)
        return !(*this < boardTwo) && !(this->manDistSum + movesFromStart.size() == boardTwo.manDistSum + boardTwo.movesFromStart.size());
    else
        return false;
}

bool Board_Tile::isSolution() const {
    return config == goalConfig;
}

std::string Board_Tile::getMoves() const {
    return movesFromStart;
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
        total += abs(i%3 - tileGoal%3) + abs(i/3 - tileGoal/3);
    }
    return total;
}

int Board_Tile::Manhattan_Distance() {
    char key;
    int tileGoal;
    int total = 0;
    for(int i = 0; i < 9; i++) {
        key = config[i];
        for(int j = 0; j < 9; j++) 
            if(goalConfig[j] == key) {
                tileGoal = j;
                break;
            }
        total += abs(i%3 - tileGoal%3) + abs(i/3 - tileGoal/3);
    }
    manDistSum = total;
    return total;
}

Board_Tile Board_Tile::move(moveDir dir, int emptyLoc) const {
    switch(dir) {
        case U : {
            assert(emptyLoc != 0 && 1 && 2);
            Board_Tile mv = *this;
            std::swap(mv.config[emptyLoc], mv.config[emptyLoc - 3]);
            mv.manDistSum = mv.Manhattan_Distance();
            mv.movesFromStart += "U";
            return mv;
        }
        case L : {
            assert(emptyLoc != 0 && 3 && 6);
            Board_Tile mv = *this;
            std::swap(mv.config[emptyLoc], mv.config[emptyLoc - 1]);
            mv.manDistSum = mv.Manhattan_Distance();
            mv.movesFromStart += "L";
            return mv;
        }
        case D : {
            assert(emptyLoc != 6 && 7 && 8);
            Board_Tile mv = *this;
            std::swap(mv.config[emptyLoc], mv.config[emptyLoc + 3]);
            mv.manDistSum = mv.Manhattan_Distance();
            mv.movesFromStart += "D";
            return mv;
        }
        case R : {
            assert(emptyLoc != 2 && 5 && 8);
            Board_Tile mv = *this;
            std::swap(mv.config[emptyLoc], mv.config[emptyLoc + 1]);
            mv.manDistSum = mv.Manhattan_Distance();
            mv.movesFromStart += "R";
            return mv;
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

void Board_Tile::output(std::string name) const {
    std::cout << name << " has config - " << config << std::endl
              << name << " has moves  - " << movesFromStart << std::endl
              << name << " has goal   - " << goalConfig << std::endl
              << name << " has manDis - " << manDistSum << std::endl << std::endl;
}