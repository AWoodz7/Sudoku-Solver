#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Location {
private:
    int value;
    std::vector<int> possibles;
public:
    Location(char value, const int gridSize);   //check default works
    void removePossibles(std::vector<int> rejects);
    int getValue() {return this->value;}
    char dispValue();
    bool isPossible(int checkValue);
};
#endif
