#include <utility>
#include "Stone.h"
using namespace std;

Stone::Stone() {
    position = make_pair(-1, -1);
    aura = 2;
    obtained = scrollFound = false;
}

void Stone::setPosition(int x, int y) {
    position = make_pair(x, y);
}

pair<int, int> Stone::getPosition() const {
    return position;
}

string Stone::getColor() const {
    switch (color) {
        case (WHITE):
            return "White";
        case (ORANGE):
            return "Orange";
        case (RED):
            return "Red";
        case (GREEN):
            return "Green";
        case (BLUE):
            return "Blue";
        case (PURPLE):
            return "Purple";
        case (BLACK):
            return "Black";
        default :
            return "MISSING_STONE_COLOR";
    }
}
