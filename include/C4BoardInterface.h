#include <iostream>
#include <ncurses.h>
#include "C4BoardState.h"

class C4BoardStateInterface {
    friend class C4BoardState;

private:

    static void place(int xCoord, int yCoord, int token);


public:
    static C4BoardState *create_board(int cols = 6, int rows = 7);

    static const int getWidth(const C4BoardState *);

    static const int getHeight(const C4BoardState *);

    static const char *getToken(int key, int lineNum);

    static int drop(int xCoord, int token);

    static void clear(C4BoardState *board);

    int drop(C4BoardState *board, int xCoord, int token);
};
