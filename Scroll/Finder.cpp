#include <utility>
#include <iostream>
#include <math.h>
#include "Finder.h"
#include "../Stone/Stone.h"
#include <fstream>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

Finder::Finder(pair<int, int> finderPosition, Stone* stone){
    finderFound = false;
    int line; // line is for correct hint based on positions
    string temp; // to read hints into
    aura = 2;
    position = finderPosition; // finders position
    ifstream readIn;
    stoneColor = stone->getActualColor(); // taken from stone class
    pair <int, int> stonePosition = stone->getPosition(); // fills in the pair
    int xDist = stonePosition.first - position.first;
    int yDist = stonePosition.second - position.second;
    if (fabs(xDist) > fabs(yDist)) {
        if (xDist < 0)
            line = 3;
        else
            line = 4;
    } else {
        if (yDist < 0)
            line = 1;
        else
            line = 2;
    }
    switch (stoneColor) {
        case WHITE:
            readIn.open("Scroll/finderWhite.txt");
            break;
        case ORANGE:
            readIn.open("Scroll/finderOrange.txt");
            break;
        case RED:
            readIn.open("Scroll/finderRed.txt");
            break;
        case GREEN:
            readIn.open("Scroll/finderGreen.txt");
            break;
        case BLACK:
            readIn.open("Scroll/finderBlack.txt");
            break;
        case BLUE:
            readIn.open("Scroll/finderBlue.txt");
            break;
        case PURPLE:
            readIn.open("Scroll/finderPurple.txt");
            break;
    }
    for(int i = 0; i < line; ++i){ // puts in correct hint
        getline(readIn, hint, '\n');
    }
    readIn.close();
}
