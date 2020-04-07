/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#include "Sliding_Solver.h"
#include <string>
#include <iostream>

int main () {
    Sliding_Solver test("123745086", "123456780");
    std::cout << test.Solve_Puzzle();
    
    return 0;
}