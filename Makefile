CC=g++ -g
EXE_FILE=sudoku

all: $(EXE_FILE)

$(EXE_FILE): location.o puzzle.o main.o
	$(CC) location.o puzzle.o main.o -o $(EXE_FILE)

main.o: main.cpp
	$(CC) -c main.cpp

location.o: location.hpp location.cpp
	$(CC) -c location.hpp location.cpp

puzzle.o: puzzle.hpp puzzle.cpp
	$(CC) -c puzzle.hpp puzzle.cpp


clean:
	rm -f *.o *.hpp.gch $(EXE_FILE)
