#include <utility>  // For pair
#include <iostream> // Temp
#include <stdlib.h> // For rand
#include "SpecificStones.h"
using namespace std;

// ========================White Stone=====================================//
WhiteStone::WhiteStone(pair<int, int> position) {
    this->position = position;
    color = WHITE;
    numCalls = 0;
}

void WhiteStone::uniqueFunction() {
    // Trait: Moves in a random axis direction 3 squares every 6 steps
    
    // First, check if stone should move
    if (numCalls % 6 != 0) {
        numCalls++;
        return;
    }
    
    int direction = rand() % 4;
    // 0-1 are x axis, 2-3 are y axis
    
    switch (direction) {
        case 0: // Move left on x axis
            position.second -= 3;
            if (position.second < 0)
                position.second = 0;
            break;
        case 1: // Move right on x axis (max size is 64)
            position.second += 3;
            if (position.second > 63)
                position.second = 63;
            break;
        case 2: // Move down on y axis
            position.first += 3;
            if (position.first > 63)
                position.first = 63;
            break;
        case 3: // Move up on y axis
            position.first -= 3;
            if (position.first < 0)
                position.first = 0;
            break;
    }
    
    numCalls++;
}

// ========================Green Stone=====================================//
GreenStone::GreenStone(pair<int, int> position) {
    this->position = position;
    color = GREEN;
    numCalls = 0;
    outsidePos = make_pair(-5, -5);
}

// Disappears every 5 moves for 1 turn
void GreenStone::uniqueFunction() {
    if (numCalls % 5 == 0) {
        pair<int, int> tmp = outsidePos;
        outsidePos = position;
        position = tmp;
    }
    numCalls++;
}

// ========================Blue Stone=====================================//
BlueStone::BlueStone(pair<int, int> position) {
    this->position = position;
    color = BLUE;
}

// ========================Purple Stone=====================================//
PurpleStone::PurpleStone(pair<int, int> position) {
    this->position = position;
    color = PURPLE;
    kb = false;
}

void PurpleStone::uniqueFunction() {
    int val = rand() % 10 + 1;
    kb = (val <= 6);
}

// ========================Black Stone=====================================//
BlackStone::BlackStone(pair<int, int> position) {
    this->position = position;
    color = BLACK;
    aura = 0;
    numCalls = 0;
}

void BlackStone::uniqueFunction() {
    numCalls++;
    if (numCalls % 2 == 0) {
        if (numCalls > 4) {
            aura--;
            if (numCalls == 8)
                numCalls = 0;
        }
        else
            aura++;
    }
}

// ========================Red Stone========================================//

RedStone::RedStone(pair<int, int> position) {
    this->position = position;
    color = RED;
    available = false;
}

void RedStone::uniqueFunction() {
    // This function does nothing; the other bool function is called
    // when the player picks up an item.
    return;
}

void RedStone::hasRedFinder(Inventory* ptr) {
    available = (ptr->hasRedFinder());
}

// ========================Orange Stone=====================================//
OrangeStone::OrangeStone(pair<int, int> position) {
    this->position = position;
    color = ORANGE;
    aura = 5;
    available = false;
}

void OrangeStone::uniqueFunction() {
    // This function does nothing; the other bool functions are called
    // when the player picks up an item.
    return;
}

void OrangeStone::hasAllStones(Inventory* ptr) {
    if (ptr->hasAllStones()) {
        available = true;
    }
}