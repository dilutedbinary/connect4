//
// Created by mzwicky on 7/8/18.
//

#ifndef CONNECT4_C4BOARDCELL_H
#define CONNECT4_C4BOARDCELL_H


class C4BoardCell {
private:
    int state;
public:
    int getState() const;

    void setState(int state);

    bool isEmpty();

    void empty();

};


#endif //CONNECT4_C4BOARDCELL_H
