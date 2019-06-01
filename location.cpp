#include "location.hpp"

//******************************************************************************
Location::Location(char value, const int gridSize) {

    if (value == '_') {     //not a clue
        this->value = -1;
        //populate with all values
        for (int k = 0; k < gridSize; k++) {
            this->possibles.push_back(k);
        }
    }
    else if (value >= '0' && value <= '9') {  //check if numeric
        this->value = value - '0';  //store number, not ASCII
        this->possibles.clear();
    }
    //do nothing if it is an invalid character?


    // if (this->value == -1) {
    //     for (int k = 1; k <= 9; k++) {  //populate with 1-9
    //         this->possibles.push_back(k);
    //     }
    // }
    // else {
    //     this->possibles.clear();
    // }
}

//******************************************************************************
char Location::dispValue() {
    if (this->value >= 0 && this->value <= 9) {
        return this->value + '0';   //translate into ASCII
    }
    else {
        return '_';
    }
}

//******************************************************************************
void Location::removePossibles(std::vector<int> rejects) {
    std::vector<int> matchIndex;

    //find matches
    if(this->possibles.size() == 0)
        return;

    for (int k = 0; k < this->possibles.size()-1; k++) {
        if (std::find(rejects.begin(), rejects.end(), this->possibles.at(k)) != rejects.end()) {
            matchIndex.push_back(k);
        }
    }

    //remove matches (reverse order)
    for (int k = matchIndex.size()-1; k >= 0; k--) {
        //std::cout << "new reject: " << matchIndex.at(k) << std::endl;
        this->possibles.erase(this->possibles.begin() + matchIndex.at(k));
    }
}

//******************************************************************************
bool Location::isPossible(int checkValue) {
    return std::find(this->possibles.begin(), this->possibles.end(), checkValue) != this->possibles.end();
}
