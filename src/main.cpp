/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#include "Sliding_Solver.h"
#include <string>
#include <iostream>

int main () {
    /*std::string initial = "123745086";
    std::string goal = "123456780";
    Sliding_Solver test(initial, goal);
    std::cout << test.Solve_Puzzle();*/

    Board_Tile test1("023145786", "UU");
    Board_Tile test2("123405786", "UR");

    test1.Manhattan_Distance();
    test2.Manhattan_Distance();

    if(test1 < test2)
        std::cout << "test1 is smaller than test2 and I dun fked up\n\n";
    else
        std::cout << "test2 is smaller and that is correct\n\n";
    
    return 0;
}