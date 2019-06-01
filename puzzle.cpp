#include "puzzle.hpp"
//******************************************************************************
Puzzle::Puzzle(std::ifstream& puzzleFile) {

    //construct the grid by reading in the values from the puzzle file
    for (int k = 0; k < this->gridSize; k++) {
        for (int j = 0; j < this->gridSize; j++) {
            this->grid[k][j] = new Location(puzzleFile.get(), this->gridSize);
            // if (puzzleFile.fail())
            //     std::cout << "Issue reading" << std::endl;
            // else

        }
        puzzleFile.get();   //clear newline char
    }

    puzzleFile.close();
}

//******************************************************************************
void Puzzle::printPuzzle() {
    for (int k = 0; k < this->gridSize; k++) {
        for (int j = 0; j < this->gridSize; j++) {
            std::cout << this->grid[k][j]->dispValue() << ' ';
        }
        std::cout << std::endl;
    }
}

//******************************************************************************
void Puzzle::debugPrint(int checkValue) {
    for (int k = 0; k < this->gridSize; k++) {
        for (int j = 0; j < this->gridSize; j++) {
            // std::cout << "(" << k << ", " << j << ")" << std::endl;
            // std::cout << "Grid Value: " << this->grid[k][j]->dispValue() << std::endl;
            // std::cout << "Check Value: " << checkValue << std::endl;
            // std::cout << "Equal?: " << (this->grid[k][j]->dispValue() == checkValue + '0') << std::endl;

            if (this->grid[k][j]->dispValue() == checkValue + '0') {    //matching clue
                 std::cout << checkValue << ' ';
            }
            else if (this->grid[k][j]->dispValue() != '_') { //nonmatching clue
                std::cout << "# ";
            }
            else if (this->grid[k][j]->isPossible(checkValue)) {  //non clue, possibly matching value
                std::cout << "  ";
            }
            else {  //non clue, can't match value
                std::cout << "* ";
            }
        }
        std::cout << std::endl;
    }

}

//******************************************************************************
void Puzzle::refreshPuzzle() {
    bool hasChanged;    //detect when all updates have been made
    std::vector<int> rejects;
    int tempReject, counter = 1;
    int xMin, yMin, xMax, yMax; //for defining cells
    //struct coord directions[8] = {{-1,0}, };

    do {
        hasChanged = false;
        std::cout << "=== Refresh #" << counter++ << " ===" << std::endl;
        for (int k = 0; k < this->gridSize; k++) {
            for (int j = 0; j < this->gridSize; j++) {
                rejects.clear();    //reset
                //assemble all numbers on the same row, column, and cell

                //rows
                for (int i = 0; i < this->gridSize; i++) {
                    tempReject = this->grid[k][i]->getValue();
                    //std::cout << "tempReject: " << tempReject << std::endl;
                    //if the value is certain and unique
                    if (tempReject != -1 && std::find(rejects.begin(), rejects.end(), tempReject) == rejects.end()) {
                        rejects.push_back(tempReject);
                        //std::cout << "new reject: " << tempReject;
                    }
                }
                //std::cout << std::endl;
                
                //columns
                for (int i = 0; i < this->gridSize; i++) {
                    tempReject = this->grid[i][j]->getValue();
                    //std::cout << "tempReject: " << tempReject << std::endl;
                    //if the value is certain and unique
                    if (tempReject != -1 && std::find(rejects.begin(), rejects.end(), tempReject) == rejects.end()) {
                        rejects.push_back(tempReject);
                        //std::cout << "new reject: " << tempReject;
                    }
                }
                //std::cout << std::endl;

                //cells
                xMin = (j/3) * 3; //integer division should round down first
                yMin = (k/3) * 3;

                xMax = xMin + 3;
                yMax = yMin + 3;

                for (int i = yMin; i < yMax; i++) {
                    for (int l = xMin; l < xMax; l++) {
                        tempReject = this->grid[i][l]->getValue();
                        //if the value is certain and unique
                        if (tempReject != -1 && std::find(rejects.begin(), rejects.end(), tempReject) == rejects.end()) {
                            rejects.push_back(tempReject);
                        }
                    }
                }


                // if (this->grid[k][j]->getValue() == -1) {
                //
                // }
                // std::cout << "(" << k << ", " << j << ")" << std::endl;
                // std::cout << "Before: ";
                // for (int i = 1; i <= 9; i++) {
                //     if (this->grid[i][j]->isPossible(i))
                //         std::cout << i;
                // }
                // std::cout << std::endl;
                //
                this->grid[k][j]->removePossibles(rejects);
                //
                //std::cout << "After: ";
                // for (int i = 1; i <= 9; i++) {
                //     if (this->grid[k][j]->isPossible(i))
                //         //std::cout << i;
                // }
                //std::cout << std::endl;

                //update if something changed
                rejects.clear();

                if (rejects.size() > 0) {
                    hasChanged = true;
                }

                //std::cout << hasChanged << std::endl;
            }
        }


    } while(hasChanged);
}
