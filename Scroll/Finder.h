#ifndef FINDER_H
#define FINDER_H

#include <utility>
#include "../Stone/Stone.h"
using std::string;

class Finder{
    public:
        Finder(pair<int,int> finderPosition, Stone*); // random positioned "finder" scrolls
        string displayHint(){ return hint; }
        bool finderFound;
        int aura;
        Color getStnColor() { return stoneColor; }
    private:
        pair <int, int> position; // finders position
        string hint; // the hint read from a txt file
        Color stoneColor;
};

#endif