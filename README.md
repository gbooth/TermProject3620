# TermProject3620
Term project for CPSC 3620 Spring semester 2020. Sliding puzzle solved with A*

Compile
------------
To compile the project use the makefile by running the command "make" on the University Linux system. The single command will compile the project

Runtime
------------
Durring runtime the user will be prompted for two pieces of information : Their desired initial configuration and their desired goal configuration.
This input must contain 9 characters and only be characters '0','1','2','3','4','5','6','7','8' otherwise the program will crash while solving.
The user may input 'd' when specifying the goal input to use the default goal of "123456780".

Once the goal input has been taken in, provided the input is good the program will start to look for a solution, printing each possible board as it is considered
as well as the actions taken with the board. The program will continue to look for a solution until the solutions it is considering have more than 31 moves
(as every 8 puzzle can be solved in 31 moves or less) or until it runs out of moves to consider in the priority queue, whichever comes first.

Solution
------------
Once the solution is found the program will output the initial configuation, goal configuration, number of moves taken and the list of moves in the solution using
first letter abriviations for the moves