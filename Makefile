CCC=g++

CCCFLAGS= -g -std=c++11 -lX11

SRC_INCLUDE = include
INCLUDE = -I $(SRC_INCLUDE)
SRC_DIR = src

all : SlidePuzzle

%.o : %.cpp
	$(CCC) $(CCCFLAGS) -c $< -o $@

SlidePuzzle : $(SRC_DIR)
	$(CCC) $(CCCFLAGS) -o SlidePuzzle $(INCLUDE) $(SRC_DIR)/*.cpp 

clean:
	rm -f *.o *~ *% *# .#* SlidePuzzle
