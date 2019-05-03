#ifndef SPECIFICSTONES_H
#define SPECIFICSTONES_H

#include "Stone.h"
#include "../Player/Inventory.h" // Handling Inventory pointer
#include <utility>

// White: Moves in a random axis direction 3 squares every 6 steps
// Green: Intermittent existence
// Blue: Does nothing
// Purple: Chance to Kick you back
// Black: Hardest to find (fluctuating aura)
// Red: Needs item to obtain
// Orange: Must obtain all other stones first massive aura

class WhiteStone : public Stone {
    public:
        WhiteStone(pair<int, int>);
        void uniqueFunction();
    private:
        int numCalls; // Keeps track of number of calls
};

// switch between out of bounds to in bounds every 5 turns
class GreenStone : public Stone {
    public:
        GreenStone(pair<int, int>);
        void uniqueFunction();
    private:
        pair<int, int> outsidePos; // Holds outside position
        int numCalls; // Keeps track of number of calls
    
};

class BlueStone : public Stone {
    public:
        BlueStone(pair<int, int>);
        void uniqueFunction() {}; // Does nothing
};

/* It would be nice to include player.h to refer and
change player(x,y) directly, because we can't return
anything with this unique function.*/
class PurpleStone : public Stone {
    public:
        PurpleStone(pair<int, int>);
        void uniqueFunction();
        bool willKickBack() { return kb; }
    private:
        bool kb;
};

// fluctuating aura
class BlackStone : public Stone {
    public:
        BlackStone(pair<int, int>);
        void uniqueFunction();
    private:
        int numCalls;
};

// Must have the corresponding finder scroll to obtain
class RedStone : public Stone {
    public:
        RedStone(pair<int, int>);
        void uniqueFunction();
        void hasRedFinder(Inventory*);
        bool canBeObtained() { return available; }
    private:
        bool available;
};

// Must have all other stones to obtain
class OrangeStone : public Stone {
    public:
        OrangeStone(pair<int, int>);
        void uniqueFunction();
        void hasAllStones(Inventory*);
        bool canBeObtained() { return available; }
    private:
        bool available;
};

#endif