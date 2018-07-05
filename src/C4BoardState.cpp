//
// Created by mzwicky on 7/4/18.
//


#include <cstdlib>
#include <iostream>
#include "C4BoardState.h"

using namespace std;

void C4BoardState::allocate(int cols, int rows) {

    _rows = rows;
    _cols = cols;
    grid = new int *[_cols];
    for (int col; col < _cols; col++) {
        grid[col] = new int[_rows];
    }
    is_allocated = true;
}

void C4BoardState::zeroize() {
    if (!is_allocated) {
        cout << "Unallocated board somehow!";
    }
    grid[_cols][_rows];
    for (int row; row < _rows; row++) {
        for (int col; col < _cols; col++) {
            grid[col][row] = 0;
        }
    }
}
