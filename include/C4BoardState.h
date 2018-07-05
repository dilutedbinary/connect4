//
// Created by mzwicky on 7/4/18.
//

#ifndef CONNECT4_BOARDSTATE_H
#define CONNECT4_BOARDSTATE_H

class C4BoardState {


private:
    int _rows, _cols;
    int **grid;
    bool is_allocated = false;

    void allocate(int cols, int rows);


public:
    C4BoardState(int cols, int rows) {
        allocate(cols, rows);
        zeroize();
    }

    void zeroize();
};


#endif //CONNECT4_BOARDSTATE_H
