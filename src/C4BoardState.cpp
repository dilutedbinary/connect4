//
// Created by mzwicky on 7/4/18.
//


#include <cstdlib>
#include <iostream>
#include "C4BoardState.h"

/* EX (4 row, 5 col)
 *
 * |
 * |
 * |
 * |
 *
 *
 */



using namespace std;

void C4BoardState::verifyAllocated() {
    if (!is_allocated) {
        cout << "Unallocated board somehow!";
    }
    exit(1);
}

void C4BoardState::allocate(int rows, int cols) {

    _cols = rows;
    _rows = cols;
    grid = new C4BoardCell *[_rows];
    for (int row; row < _rows; row++) {
        grid[row] = new C4BoardCell[_cols];
    }
    is_allocated = true;
}

void C4BoardState::zeroize() {
    verifyAllocated();
    grid[_rows][_rows];
    for (int row; row < _rows; row++) {
        for (int col; col < _rows; col++) {
            grid[col][row].empty();
        }
    }
}

void C4BoardState::validateCoordinates(int row = 0, int column = 0) {
    verifyAllocated();
    bool colOOB = column >= _rows;
    bool rowOOB = row >= _rows;
    if (colOOB || rowOOB) {
        char errorBuffer[100];
        string dimensionString = "Rows";
        if (colOOB) {
            dimensionString = "Columns";
        }

        sprintf(errorBuffer, "Coordinates out of bound (%s)",
                dimensionString);
        cerr << "Column Max: " << _rows << " Passed: " << column << endl
             << "Row Max: " << _rows << " Passed: " << row << endl;
        throw out_of_range(errorBuffer);

    }
}

void C4BoardState::setCell(int column, int row, int value) {
    verifyAllocated();
    validateCoordinates(column, row);
    grid[column][row].setState(value);
}

C4BoardState::C4BoardState(int columns, int rows) {
    {
        if (rows <= 0 || columns <= 0) {
            cout << "Invalid Dimensions" << endl;
            exit(-1);
        }

        allocate(columns, rows);
        zeroize();
    }
}


