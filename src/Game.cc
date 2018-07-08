#include <C4BoardState.h>
#include <Game.h>

using namespace std;


//Inititialize an interface
Game::Game(int columns, int rows) : currentState(columns, rows) {

}

void Game::clear() {
    currentState.zeroize();
}


/**
 * Drop: place a toke in the given column (if a valid move)
 *
 * Return 1: good move
 * Return -1: column full
 * Return -2: invalid column
 */
int Game::drop(int column, int token) {
    int width = getWidth();
    int height = getHeight();
    if (!(column < width)) {

        return -2;
    }

    int currentHeight = 0;
    //iterate through the selected column until an open pace appears
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

vector<int> Game::getAvailableMoves() {
    return vector<int>();
}

/*


void Game::place(int colNum, int rowNum, int token) {
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



const char *Game::getToken(int key, int lineNum) {
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
const int *Game::operator[](int i) const {

    return grid[i];
}


*/