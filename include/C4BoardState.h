//
// Created by mzwicky on 7/4/18.
//

#ifndef CONNECT4_BOARDSTATE_H
#define CONNECT4_BOARDSTATE_H

#include "C4BoardCell.h"

class C4BoardState {


private:
    int _rows, _cols;
    C4BoardCell **grid;
    bool is_allocated = false;

    void allocate(int cols, int rows);

    void verifyAllocated();

public:
    C4BoardState(int columns, int rows);

    void zeroize();


    void setCell(int column, int row, int value);

    void validateCoordinates(int column, int row);


};


#endif //CONNECT4_BOARDSTATE_H
