#include <C4BoardState.h>
#include <C4BoardInterface.h>

using namespace std;


//Inititialize an interface
C4BoardState *C4BoardStateInterface::create_board(int columns, int rows) {
    if (rows <= 0 || columns <= 0) {
        cout << "Invalid Dimensions" << endl;
        exit(-1);
    }
    C4BoardState *board = new C4BoardState(columns, rows);
    return board;

}

void C4BoardStateInterface::clear(C4BoardState *board) {
    board->zeroize();
}

/**
 * Drop: place a toke in the given column (if a valid move)
 *
 * Return 1: good move
 * Return -1: column full
 * Return -2: invalid column
 */
int C4BoardStateInterface::drop(C4BoardState *board, int column, int token) {
    int width = getWidth(board);
    int height = getHeight(board);
    if (!(column < width)) {

        return -2;
    }

    int currentHeight = 0;
    //iterate through the selected column untill an open pace appears
    while (!(grid[xCoord][currentHeight] == 0)) {
        currentHeight++;
        if (currentHeight >= height_) {
            mvprintw(0, 0, "invalid height or something");
//column is full
            return -1;
        }
    }
    grid[xCoord][currentHeight] = token;
    return 1;
}

/*deprecated
void Board::print(){
  horizontal(40);
  int xOffset = xLocation_;
  int yOffset = yLocation_;
  int originalx = xOffset;
  for(int i=height_-1;i>=0; i--){
      mvprintw(yOffset,xOffset++,"|");
      for(int j=0;j<_cols;j++){
  mvprintw(yOffset,xOffset++,getToken(grid[j][i]));
  mvprintw(yOffset,xOffset++,"|");
      }
      xOffset = originalx;
      yOffset++;

    }
  }

*/
void C4BoardStateInterface::horizontal(int yLoc) {
    int visualWidth = width_;


    mvprintw(yLoc, xLocation_, string(visualWidth * 6 + 1, '-').c_str());
}

void C4BoardStateInterface::vertical(int xLoc) {
    int visualHeight = height_;
    for (int i = 0; i < visualHeight * 3 + 1; i++) {
        if (i % 3 == 0) {
            mvprintw(i + yLocation_, xLoc, "+");
        } else {
            mvprintw(i + yLocation_, xLoc, "|");
        }
    }
}

void C4BoardStateInterface::printJumbo() {

    int xOffset = xLocation_;
    int yOffset = yLocation_;
    //just saving because it gets overwritten
    //  int originalx = xOffset;

    for (int i = 0; i < height_ + 1; i++) {
        horizontal(i * 3 + yOffset);
    }

    for (int i = 0; i < width_ + 1; i++) {
        vertical(i * 6 + xOffset);
    }
    for (int i = height_ - 1; i >= 0; i--) {

        for (int j = 0; j < width_; j++) {
            place(j, i, grid[j][i]);
        }
    }
}


void C4BoardStateInterface::place(int colNum, int rowNum, int token) {
    rowNum = height_ - rowNum - 1;
    string line1 = getToken(token, 1);
    string line2 = getToken(token, 2);

    int targx = xLocation_ + (colNum * 6) + 2;
    int targy = yLocation_ + (rowNum * 3) + 1;
    attron(COLOR_PAIR(token));
    mvprintw(targy++, targx, line1.c_str());
    mvprintw(targy, targx, line2.c_str());
    attroff(COLOR_PAIR(token));


}


const char *C4BoardStateInterface::getToken(int key, int lineNum) {
    switch (key) {
        case 0:
            return "   ";
        case 1:
            if (lineNum == 1)return "/T\\";
            if (lineNum == 2)return "\\_/";
        case 2:
            if (lineNum == 1) return "\\_/";
            if (lineNum == 2) return "/ \\";
            //default: return {'?'};
    }
    char *missing = new char[1];
    missing[0] = '?';
    return missing;
}

//[x][y]
const int *C4BoardStateInterface::operator[](int i) const {

    return grid[i];
}


void C4BoardStateInterface::initialize_board() {

}
