/******************************************************************************
 * Test branch for initial classes, merged 1 March 2019                       *
 *****************************************************************************/
 
#include <iostream>
#include <cstdlib>

#include "Finder.h"
#include "Inventory.h"
#include "Player.h"
#include "Scrolls.h"
#include "SpecificStones.h"
#include "Stone.h"
#include "Map.h"
#include "HUD.h"
using namespace std;

int main() {
    // Seed for random generator
    srand(3);
    pair<int, int> position;
    
    // Test white stone
    position = make_pair(rand() % 64, rand() % 64);
    WhiteStone* whtStnPtr = new WhiteStone(position);
    cout << "White stone constructed." << endl;
    pair<int, int> whtStnPstn = whtStnPtr->getPosition();
    cout << "Position: " << whtStnPstn.first << ", " << whtStnPstn.second << endl;
    cout << "Aura: " << whtStnPtr->aura << "\nScroll found: " << whtStnPtr->scrollFound << "\nObtained: " << whtStnPtr->obtained << endl;
    cout << "Color: " << whtStnPtr->getColor() << endl;
    cout << "Setting position to (16, 27)..." << endl;
    whtStnPtr->setPosition(16, 27);
    whtStnPstn = whtStnPtr->getPosition();
    cout << "New position: " << whtStnPstn.first << ", " << whtStnPstn.second << endl;
    cout << "Calling unique function 6 times" << endl;
    for (int i = 0; i < 6; ++i) {
        whtStnPtr->uniqueFunction();
    }
    whtStnPstn = whtStnPtr->getPosition();
    cout << "New position: " << whtStnPstn.first << ", " << whtStnPstn.second << endl;
    cout << "Calling unique function another 6 times" << endl;
    for (int i = 0; i < 6; ++i) {
        whtStnPtr->uniqueFunction();
    }
    whtStnPstn = whtStnPtr->getPosition();
    cout << "New position: " << whtStnPstn.first << ", " << whtStnPstn.second << endl;
    
    cout << endl; // Finished testing
    
    // Testing green stone
    position = make_pair(rand() % 64, rand() % 64);
    GreenStone* grnStnPtr = new GreenStone(position);
    cout << "Green stone constructed." << endl;
    pair<int, int> grnStnPstn = grnStnPtr->getPosition();
    cout << "Position: " << grnStnPstn.first << ", " << grnStnPstn.second << endl;
    cout << "Aura: " << grnStnPtr->aura << "\nScroll found: " << grnStnPtr->scrollFound << "\nObtained: " << grnStnPtr->obtained << endl;
    cout << "Color: " << grnStnPtr->getColor() << endl;
    cout << "Setting position to (16, 27)..." << endl;
    grnStnPtr->setPosition(16, 27);
    grnStnPstn = grnStnPtr->getPosition();
    cout << "New position: " << grnStnPstn.first << ", " << grnStnPstn.second << endl;
    cout << "Calling unique function 5 times" << endl;
    for (int i = 0; i < 5; ++i) {
        grnStnPtr->uniqueFunction();
    }
    grnStnPstn = grnStnPtr->getPosition();
    cout << "New position: " << grnStnPstn.first << ", " << grnStnPstn.second << endl;
    cout << "Calling unique function another 5 times" << endl;
    for (int i = 0; i < 5; ++i) {
        grnStnPtr->uniqueFunction();
    }
    grnStnPstn = grnStnPtr->getPosition();
    cout << "New position: " << grnStnPstn.first << ", " << grnStnPstn.second << endl;
    
    cout << endl; // Finished testing
    
    // Testing blue stone
    position = make_pair(rand() % 64, rand() % 64);
    BlueStone* bluStnPtr = new BlueStone(position);
    cout << "Blue stone constructed." << endl;
    pair<int, int> bluStnPstn = bluStnPtr->getPosition();
    cout << "Position: " << bluStnPstn.first << ", " << bluStnPstn.second << endl;
    cout << "Aura: " << bluStnPtr->aura << "\nScroll found: " << bluStnPtr->scrollFound << "\nObtained: " << bluStnPtr->obtained << endl;
    cout << "Color: " << bluStnPtr->getColor() << endl;
    cout << "Setting position to (16, 27)..." << endl;
    bluStnPtr->setPosition(16, 27);
    bluStnPstn = bluStnPtr->getPosition();
    cout << "New position: " << bluStnPstn.first << ", " << bluStnPstn.second << endl;
    cout << "Calling unique function 5 times" << endl;
    for (int i = 0; i < 5; ++i) {
        bluStnPtr->uniqueFunction();
    }
    cout << "Calling unique function another 5 times" << endl;
    for (int i = 0; i < 5; ++i) {
        bluStnPtr->uniqueFunction();
    }
    
    cout << endl; // Finished testing
    
    // Testing purple
    position = make_pair(rand() % 64, rand() % 64);
    PurpleStone* pplStnPtr = new PurpleStone(position);
    cout << "Purple stone constructed." << endl;
    pair<int, int> pplStnPstn = pplStnPtr->getPosition();
    cout << "Position: " << pplStnPstn.first << ", " << pplStnPstn.second << endl;
    cout << "Aura: " << pplStnPtr->aura << "\nScroll found: " << pplStnPtr->scrollFound << "\nObtained: " << pplStnPtr->obtained << endl;
    cout << "Color: " << pplStnPtr->getColor() << endl;
    cout << "Setting position to (16, 27)..." << endl;
    pplStnPtr->setPosition(16, 27);
    pplStnPstn = pplStnPtr->getPosition();
    cout << "New position: " << pplStnPstn.first << ", " << pplStnPstn.second << endl;
    cout << "Calling unique function 10 times" << endl;
    for (int i = 0; i < 10; ++i) {
        pplStnPtr->uniqueFunction();
        cout << (pplStnPtr->willKickBack() ? "Will kick back" : "Will not kick back") << endl;
    }
    cout << "Calling unique function another 10 times" << endl;
    for (int i = 0; i < 10; ++i) {
        pplStnPtr->uniqueFunction();
        cout << (pplStnPtr->willKickBack() ? "Will kick back" : "Will not kick back") << endl;
    }
    
    cout << endl; // Finished testing
    
    // Testing black
    position = make_pair(rand() % 64, rand() % 64);
    BlackStone* blkStnPtr = new BlackStone(position);
    cout << "Black stone constructed." << endl;
    pair<int, int> blkStnPstn = blkStnPtr->getPosition();
    cout << "Position: " << blkStnPstn.first << ", " << blkStnPstn.second << endl;
    cout << "Aura: " << blkStnPtr->aura << "\nScroll found: " << blkStnPtr->scrollFound << "\nObtained: " << blkStnPtr->obtained << endl;
    cout << "Color: " << blkStnPtr->getColor() << endl;
    cout << "Setting position to (16, 27)..." << endl;
    blkStnPtr->setPosition(16, 27);
    blkStnPstn = blkStnPtr->getPosition();
    cout << "New position: " << blkStnPstn.first << ", " << blkStnPstn.second << endl;
    cout << "Calling unique function 13 times" << endl;
    for (int i = 0; i < 13; ++i) {
        blkStnPtr->uniqueFunction();
        cout << "Aura: " << blkStnPtr->aura << endl;
    }
    cout << "Calling unique function another 13 times" << endl;
    for (int i = 0; i < 13; ++i) {
        blkStnPtr->uniqueFunction();
        cout << "Aura: " << blkStnPtr->aura << endl;
    }
    
    cout << endl; // Finished testing
    
    // Testing orange stone
    position = make_pair(rand() % 64, rand() % 64);
    OrangeStone* orgStnPtr = new OrangeStone(position);
    cout << "Orange stone constructed." << endl;
    pair<int, int> orgStnPstn = orgStnPtr->getPosition();
    cout << "Position: " << orgStnPstn.first << ", " << orgStnPstn.second << endl;
    cout << "Aura: " << orgStnPtr->aura << "\nScroll found: " << orgStnPtr->scrollFound << "\nObtained: " << orgStnPtr->obtained << endl;
    cout << "Color: " << orgStnPtr->getColor() << endl;
    cout << "Setting position to (16, 27)..." << endl;
    orgStnPtr->setPosition(16, 27);
    orgStnPstn = orgStnPtr->getPosition();
    cout << "New position: " << orgStnPstn.first << ", " << orgStnPstn.second << endl;
    cout << (orgStnPtr->canBeObtained() ? "Can be obtained" : "Cannot be obtained") << endl;
    cout << "Now setting checkpoints" << endl;
    Inventory* invPtr = new Inventory;
    for (int i = 0; i < 7; ++i) {
        invPtr->setFlag(static_cast<Checkpoint>(i));
        orgStnPtr->hasAllStones(invPtr);
        cout << (orgStnPtr->canBeObtained() ? "Can be obtained" : "Cannot be obtained") << endl;
    }
    
    cout << endl; // Finished testing
    
    // Testing red stone
    position = make_pair(rand() % 64, rand() % 64);
    RedStone* redStnPtr = new RedStone(position);
    cout << "Red stone constructed." << endl;
    pair<int, int> redStnPstn = redStnPtr->getPosition();
    cout << "Position: " << redStnPstn.first << ", " << redStnPstn.second << endl;
    cout << "Aura: " << redStnPtr->aura << "\nScroll found: " << redStnPtr->scrollFound << "\nObtained: " << redStnPtr->obtained << endl;
    cout << "Color: " << redStnPtr->getColor() << endl;
    cout << "Setting position to (16, 27)..." << endl;
    redStnPtr->setPosition(16, 27);
    redStnPstn = redStnPtr->getPosition();
    cout << "New position: " << redStnPstn.first << ", " << redStnPstn.second << endl;
    cout << (redStnPtr->canBeObtained() ? "Can be obtained" : "Cannot be obtained") << endl;
    cout << "Now setting checkpoint" << endl;
    invPtr->setFlag(OBT_REDFDR);
    redStnPtr->hasRedFinder(invPtr);
    cout << (redStnPtr->canBeObtained() ? "Can be obtained" : "Cannot be obtained") << endl;
    
    cout << endl; // Finished testing

    /***************************************************************
     * Scroll tests                                                *
     **************************************************************/
    
    string answer;
    
    position = make_pair(rand() % 64, rand() % 64);
    Scroll* oneScrlPtr = new Scroll(position);
    cout << "Scroll constructed. " << (oneScrlPtr->scrollFound ? "Is found." : "Is not found.") << endl;
    cout << oneScrlPtr->displayRiddle();
    cin >> answer;
    cout << (oneScrlPtr->checkAnswer(answer) ? "Correct." : "Incorrect.") << endl;
    cin >> answer;
    cout << (oneScrlPtr->checkAnswer(answer) ? "Correct." : "Incorrect.") << endl;
    
    cout << endl;
    delete oneScrlPtr;
    
    position = make_pair(rand() % 64, rand() % 64);
    oneScrlPtr = new Scroll(position);
    cout << "Scroll constructed. " << (oneScrlPtr->scrollFound ? "Is found." : "Is not found.") << endl;
    cout << oneScrlPtr->displayRiddle();
    cin >> answer;
    cout << (oneScrlPtr->checkAnswer(answer) ? "Correct." : "Incorrect.") << endl;
    cin >> answer;
    cout << (oneScrlPtr->checkAnswer(answer) ? "Correct." : "Incorrect.") << endl;
    
    cout << endl;
    delete oneScrlPtr;
    
    /***************************************************************
     * Finder tests                                                *
     **************************************************************/
     
    position = make_pair(rand() % 64, rand() % 64);
    Finder* oneFdrPtr = new Finder(position, blkStnPtr);
    cout << "Finder constructed. " << (oneFdrPtr->finderFound ? "Is found." : "Is not found.") << endl;
    cout << oneFdrPtr->displayHint() << endl;
    delete oneFdrPtr;
    
    position = make_pair(rand() % 64, rand() % 64);
    oneFdrPtr = new Finder(position, whtStnPtr);
    cout << "Finder constructed. " << (oneFdrPtr->finderFound ? "Is found." : "Is not found.") << endl;
    cout << oneFdrPtr->displayHint() << endl;
    delete oneFdrPtr;

    /***************************************************************
     * Player tests                                                *
     **************************************************************/
    
    Map* map = new Map;
    Player* player = new Player;
    
    cout << "Player created. " << "X: " << player->getPosition().first << " Y: " << player->getPosition().second << endl;
    player->move('W');
    cout << "Moving up! " << "X: " << player->getPosition().first << " Y: " << player->getPosition().second << endl;
    player->move('A');
    cout << "Moving left! " << "X: " << player->getPosition().first << " Y: " << player->getPosition().second << endl;
    player->move('S');
    cout << "Moving down! " << "X: " << player->getPosition().first << " Y: " << player->getPosition().second << endl;
    player->move('D');
    cout << "Moving right! " << "X: " << player->getPosition().first << " Y: " << player->getPosition().second << endl;
    
    if (player->pickUpItem(player->getPosition(), map)) {
        cout << "Successful item pick up. (Bad)" << endl;
    }
    if (player->pickUpItem(make_pair(48, 25), map)) {
        cout << "Successful item pick up." << endl;
    }
    cout << "Set checkpoint for white stone (OBT_WHTSTN)" << endl;
    player->setCheckpoint(OBT_WHTSTN);
    // more checking will be added
    player->addStep();
    cout << "Steps taken: " << player->getSteps() << endl;
    
    cout << "Current inventory below" << endl;
    cout << player->displayInventory(0) << endl;
    
    /***************************************************************
     * Inventory tests                                             *
     **************************************************************/
     
    Inventory* inv = new Inventory();
    inv->setFlag(OBT_WHTSTN);
    inv->setFlag(OBT_GRNSTN);
    cout << "Expecting two items in inventory..." << endl;
    for (int i = 0; i < 2; ++i) {
        cout << i << " " << inv->displayItem(i) << endl;
    }
    inv->setFlag(OBT_ORGSTN);
    inv->setFlag(OBT_BLKSTN);
    inv->setFlag(OBT_BLKFDR);
    cout << "Expecting five items in inventory..." << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i << " " << inv->displayItem(i) << endl;
    }
    
    /***************************************************************
     * Map tests                                                   *
     **************************************************************/
    cout << map->printLine(1) << endl;
    
    /***************************************************************
     * HUD tests                                                   *
     **************************************************************/
    char tmp;
    
    HUD* hud = new HUD;
    hud->print(player->getPosition());
    cin >> tmp;
    player->move('W');
    hud->updateBoard();
    hud->print(player->getPosition());
    cin >> tmp;
    player->move('A');
    hud->updateBoard();
    hud->print(player->getPosition());
    cin >> tmp;
    player->move('S');
    hud->updateBoard();
    hud->print(player->getPosition());
    cin >> tmp;
    player->move('D');
    hud->updateBoard();
    hud->print(player->getPosition());
    
    delete hud;
    delete map;
    delete inv;
    delete player;
    delete redStnPtr;
    delete orgStnPtr;
    delete blkStnPtr;
    delete pplStnPtr;
    delete bluStnPtr;
    delete grnStnPtr;
    delete whtStnPtr;
    
    return 0;
}