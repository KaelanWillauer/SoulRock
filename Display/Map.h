#ifndef MAP_H
#define MAP_H

#include <utility>
#include <map>
#include "../Stone/Stone.h"
#include "../Player/Inventory.h"
using namespace std;

// Assumes board size is 64x64
const int MAX_SIZE = 64;

class Scroll;
class Finder;
class Map {
    public:
        Map();
        ~Map();
        Checkpoint getItem(pair<int, int>, bool);
        bool willPurpleStoneKickBack();
        void removeItem(pair<int, int>);
        bool isOccupied(pair<int, int>);
        void updateBoard();
        Scroll* getScroll(Color);
        Finder* getFinder(Color);
        
        char board[MAX_SIZE][MAX_SIZE] {}; // Initialize values to 0
    private:
        void genScroll(Stone*);
        void genFinder(Stone*);
        void genStone(Color);
        pair<int, int> getNextRand();
        
        void fillAura(pair<int, int>, int);
        map<pair<int, int>, Stone*> stones;
        map<Stone*, Scroll*> scrolls;
        map<pair<int, int>, Finder*> finders;
};

#endif