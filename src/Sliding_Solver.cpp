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
    current.output("Current");
    while(tileQueue.top().numMoves() < 32 && !tileQueue.empty()) {
        std::list<Board_Tile> possibleMoves = tileQueue.top().nextConfigs();
        boardsExpanded.push_back(tileQueue.top());
        tileQueue.pop();
        assert(possibleMoves.size() <= 4);
        while(!possibleMoves.empty()) {
            possibleMoves.front().output("Front of possible list");
            auto it = std::find(boardInQueue.begin(), boardInQueue.end(), possibleMoves.front());
            if(it != boardInQueue.end()) {
                std::cout << "Possible board found in current queue list\n\n";
                it->output("Matching board to possible");
                if(possibleMoves.front().betterBoard(*it)) {
                    boardInQueue.erase(it);
                    boardInQueue.push_back(possibleMoves.front());
                    std::cout << "replacing queue\n\n";
                    std::priority_queue<Board_Tile> replacementQueue;
                    for(auto j : boardInQueue)
                        replacementQueue.push(j);
                    tileQueue.swap(replacementQueue);
                    continue;
                } else {
                    std::cout << "Discarding new duplicate\n\n";
                    possibleMoves.pop_front();
                    continue;
                }
            }
            std::cout << "Adding new possible to queue\n\n";
            boardInQueue.push_back(possibleMoves.front());
            tileQueue.push(possibleMoves.front());
            possibleMoves.pop_front();
        }
        boardInQueue.remove(current);
        if(tileQueue.top().isSolution()) {
            for(int i = 0; i < 5; i++)
                std::cout << "SOLUTION HAS BEEN FOUND\n";
            std::cout << "\n\n";
            return tileQueue.top().getMoves();
        }
        current = tileQueue.top();
        std::cout << "Solution not found. Obtaining new list of possibles\n\n";
        current.output("Current");
    }
    if(tileQueue.empty())
        std::cout << "Tile Queue empty\n\n";
    std::cout << "Loop exited. Move count --" << tileQueue.top().numMoves() << std::endl << std::endl;
    return tileQueue.top().getMoves();
}