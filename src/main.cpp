/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#include "Sliding_Solver.h"
#include <string>
#include <iostream>

int main () {
    std::string initial;
    std::string goal;
    std::string solution;
    bool GOAL_FLAG = false;

    std::cout << "Welcome to my 8-puzzle solver\n\n"
              << "Input your desired start input as a string, reading top to bottom, left to right\n only use digits 0 to 8--";
    std::cin >> initial;
    std::cout << "Enter your goal state in the same fashion.\nEnter 'd' to select the default goal of 123456780--";
    std::cin >> goal;
    if(goal == "d")
        goal = "123456780";
    Sliding_Solver solve(initial, goal);
    solution = solve.Solve_Puzzle();

    std::cout << "Initial config -- " << initial << "\n\n"
              << "Goal config -- " << goal << "\n\n"
              << "Number of moves -- " << solution.size() << "\n\n"
              << "Solution -- " << solution << "\n\n";
    return 0;
}