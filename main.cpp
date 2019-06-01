#include <iostream>
#include <string>
#include <fstream>

#include "puzzle.hpp"

// #define BASE_SIZE (3)
// #define GRID_SIZE (BASE_SIZE * BASE_SIZE)

int main () {
    std::ifstream puzzleFile;
    puzzleFile.open ("testSudoku.txt");

    if (!puzzleFile.is_open()) {
        std::cout << "Didn't open" << std::endl;
        return 1;
    }

    Puzzle puzzle(puzzleFile);
    puzzleFile.close();

    puzzle.printPuzzle();
    std::cout << std::endl;
    
    puzzle.refreshPuzzle();
    puzzle.debugPrint(3);



}
