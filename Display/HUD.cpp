#include <iostream>
#include <iomanip>
#include "Map.h"
#include "../Player/Player.h"
#include "HUD.h"
using namespace std;

extern const int MAX_SIZE;

HUD::HUD() {
    // Nothing
}

void HUD::updateBoard() {
    map.updateBoard();
}

void HUD::print(pair<int, int> position) {
    // First line
    cout << "\e[1;1H\e[2J"; // CLS
    cout << left << setw(61) << setfill('-') << "" << endl;
    cout << setw(30) << setfill(' ') << "|" << "| "
         << setw(28) << "Inventory:" << "|"
         << endl;
    
    // Each line with map and inventory items
    int inventoryItem = 0;
    (map.board)[position.first][position.second] = '.';
    for (int i = position.first - 5; i <= position.first + 5; ++i) {
        if (i >= 0 && i < 64) {
            cout << "|   ";
            for (int j = position.second - 5; j <= position.second + 5; ++j) {
                if (j >= 0 && j < 64) {
                    cout << "|" << (map.board)[i][j];
                    if (j == (position.second + 5) || j == 63)
                        cout << "|";
                } else
                    cout << "  ";
                
            }
        } else
            cout << setw(27) << "|";
        cout << "   |";
        if (inventoryItem < 9) {
            cout << " - " << setw(26) << player.displayInventory(inventoryItem);
            inventoryItem++;
        } else if (inventoryItem == 9) {
            cout << setw(29) << " 'E' for full inventory";
            inventoryItem++;
        } else if (inventoryItem == 10) {
            cout << setw(29) << setfill('-') << "";
            cout << setfill(' ');
            inventoryItem++;
        } else {
            cout << setw(29) << "";
        }
        cout << "|" << endl;
    }
    cout << setw(30) << "|" 
         << "| Steps taken: " << setw(15) << player.getSteps() << "|" << endl;
    cout << setw(61) << setfill('-') << "" << endl;
    (map.board)[position.first][position.second] = ' ';
}

bool HUD::isOccupied(pair<int, int> position) {
    return map.isOccupied(position);
}

void HUD::pickUpItem(pair<int, int> position) {
    player.pickUpItem(position, &map);
}