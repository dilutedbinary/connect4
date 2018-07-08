#include <iostream>
#include <ncurses.h>
#include "C4BoardState.h"
#include <vector>

using namespace std;

class Game {


private:

    void place(int xCoord, int yCoord, int token);

    C4BoardState currentState;

public:
    Game(int cols = 6, int rows = 7);

    const int getWidth();

    const int getHeight();

    const char *getToken(int key, int lineNum);

    int drop(int xCoord, int token);

    void clear();

    vector<int> getAvailableMoves();

};
