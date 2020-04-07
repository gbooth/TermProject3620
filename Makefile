CCC=g++

CCCFLAGS= -g -std=c++11 -lX11

all : SlidePuzzle

SlidePuzzle : Sliding_Solver.o main.o
	$(CCC) $(CCCFLAGS) $^ -o $@

%.o : %.cpp
	$(CCC) -c $(CCCFLAGS) $< -o $@

main.o : Sliding_Solver.h
Sliding_Solver.o : Sliding_Solver.h Board_Tile.o
Board_Tile.o : Board_Tile.h

clean:
	rm -f *.o *~ *% *# .#* SlidePuzzle
