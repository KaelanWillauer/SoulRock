#ifndef  PLAYER_H
#define  PLAYER_H

#include <map>
#include <utility>
#include "Inventory.h" // For Checkpoint enum
using namespace std;

class Map;
class Player{
    public:
        Player();
        //Mutators
        void addStep() {stepsTaken++;}
        void move(char step);
        void pickUpItem(pair<int,int>, Map*);
        void setCheckpoint(Checkpoint);
        void kickBackPlayer();
        bool hasAllStones() { return inventory.hasOrange(); }
        //Accessors
        int getSteps() {return stepsTaken;}
        pair<int, int> getPosition(){return position;}
        string displayInventory(int);
        int invSize() { return inventory.itemsSize(); }
    private:
        int stepsTaken;
        int randSeed;
        map<Checkpoint,bool> checkpoints;
        pair<int,int> position;
        Inventory inventory;
    
};

#endif