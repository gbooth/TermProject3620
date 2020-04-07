/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#include "Sliding_Solver.h"
#include <string>
#include <iostream>

int main () {
    std::string initial = "123745086";
    std::string goal = "123456780";
    Sliding_Solver test(initial, goal);
    std::cout << test.Solve_Puzzle();
    
    return 0;
}