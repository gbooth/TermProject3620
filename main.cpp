/**
 * @author Gavin Booth
 * @date 2020-04-06
 */

#include "Board_Tile.h"
#include <string>
#include <iostream>

int main () {
    Board_Tile test("123405678", "This is a test string", "123456780");

    test = test.move(U, 4);
    test.output();
    return 0;
}