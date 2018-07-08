//
// Created by mzwicky on 7/8/18.
//

#include "C4BoardCell.h"

int _emptyState = 0;

int C4BoardCell::getState() const {
    return state;
}

void C4BoardCell::setState(int state) {
    C4BoardCell::state = state;
}

bool C4BoardCell::isEmpty() {
    return state == _emptyState;
}


void C4BoardCell::empty() {
    state = _emptyState;
}