CCC=g++

CCCFLAGS= -g -std=c++11 -lX11

all : SlidePuzzle

SlidePuzzle : main.o Board_Tile.o
	$(CCC) $(CCCFLAGS) $^ -o $@

%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

main.o : Board_Tile.h

clean:
	rm -f *.o *~ *% *# .#* similar
