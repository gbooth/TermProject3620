CCC=g++

CCCFLAGS= -g -std=c++11 -lX11

all : SlidePuzzle

SlidePuzzle : main.o Sliding_Solver.o
	$(CCC) $(CCCFLAGS) $^ -o $@

%.o : %.cpp
	$(CCC) -c $(CCCFLAGS) $<

main.o : Sliding_Solver.h
Sliding_Solver.o : Sliding_Solver.h Board_Tile.o
Board_Tile.o : Board_Tile.h

clean:
	rm -f *.o *~ *% *# .#* SlidePuzzle
