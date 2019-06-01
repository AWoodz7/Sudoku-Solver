#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "location.hpp"
#include "structs.hpp"

class Puzzle {
private:
    static const int gridSize = 9;
    //Location* grid[9][9];
    Location* grid[gridSize][gridSize];
public:
    Puzzle(std::ifstream& puzzleFile);
    void printPuzzle();
    void refreshPuzzle();
    void debugPrint(int checkValue);
};



#endif
