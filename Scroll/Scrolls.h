#ifndef SCROLLS_H
#define SCROLLS_H

#include <utility>
#include <string>
#include "../Stone/Stone.h"
using namespace std;

class Scroll{
    public:
        Scroll();  // creates riddle and assigns riddle and answer
        string showRiddle() { return riddle; }
        string getAnswer() { return answer; }
        bool scrollFound;
        bool checkAnswer(string);       // asks the user for there answer and checks whether its correct or not
        Color color;
    private:
        string riddle;
        string answer;
};

#endif
