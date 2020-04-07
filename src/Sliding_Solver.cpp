/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#include "Sliding_Solver.h"
#include "Board_Tile.h"
#include <queue>
#include <cassert>
#include <algorithm>

Sliding_Solver::Sliding_Solver(const std::string& startConfig, const std::string& goal) {
    Board_Tile start(startConfig, goal);
    initialBoard = &start;
    start.Manhattan_Distance();
    boardInQueue.push_back(start);
    tileQueue.push(start);
}

std::string Sliding_Solver::Solve_Puzzle() {
    if(tileQueue.top().isSolution())
        return tileQueue.top().getMoves();
    Board_Tile current = tileQueue.top();
    while(tileQueue.top().numMoves() < 32 && !tileQueue.empty()) {
        std::list<Board_Tile> possibleMoves = tileQueue.top().nextConfigs();
        boardsExpanded.push_back(tileQueue.top());
        tileQueue.pop();
        assert(possibleMoves.size() <= 4);
        while(!possibleMoves.empty()) {
            //auto it = this->contains(possibleMoves.front());
            auto it = std::find(boardInQueue.begin(), boardInQueue.end(), possibleMoves.front());
            if(it != boardInQueue.end()) {
                if(possibleMoves.front().betterBoard(*it)) {
                    boardInQueue.erase(it);
                    boardInQueue.push_back(possibleMoves.front());
                    std::priority_queue<Board_Tile> replacementQueue;
                    for(auto j : boardInQueue)
                        replacementQueue.push(j);
                    tileQueue.swap(replacementQueue);
                    continue;
                } else {
                    possibleMoves.pop_front();
                    continue;
                }
            }
            boardInQueue.push_back(possibleMoves.front());
            tileQueue.push(possibleMoves.front());
            possibleMoves.pop_front();
        }
        boardInQueue.remove(current);
        if(tileQueue.top().isSolution())
            return tileQueue.top().getMoves();
        current = tileQueue.top();
    }
    if(tileQueue.empty())
        std::cout << "Tile Queue empty";
    std::cout << "Loop exited. Move count --" << tileQueue.top().numMoves();
    return tileQueue.top().getMoves();
}

std::list<Board_Tile>::const_iterator Sliding_Solver::contains(const Board_Tile& key) const {
    return std::find(boardInQueue.begin(), boardInQueue.end(), key);
}