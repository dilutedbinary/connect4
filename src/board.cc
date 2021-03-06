#include <iostream>
#include <string>
#include <ncurses.h>
#include "board.h"

using namespace std;



//grid[x/width][y/height]
Board::Board(int height, int width, int xLoc, int yLoc) {
  height_ = height;
  width_ = width;
  xLocation_ = xLoc;
  yLocation_ = yLoc;
  empty_ = new char[2];
  empty_ = " ";
  player1_ = new char[2];
  player1_ = "X";
  player2_ = new char[2];
  player2_ = (string() + char(238)).c_str();
  grid = new int*[width_];
  for (int i = 0; i < width_; i++) {
    grid[i] = new int[height_];
  }
  clear();

}

void Board::clear() {
  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      grid[i][j] = 0;
    }
  }
}
/**
 * Drop: place a toke in the given column (if a valid move)
 *
 * Return 1: good move
 * Return -1: column full
 * Return -2: invalid column
 */

int Board::drop(int xCoord, int token) {

  if (!(xCoord < width_)) {

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
      for(int j=0;j<width_;j++){
  mvprintw(yOffset,xOffset++,getToken(grid[j][i]));
  mvprintw(yOffset,xOffset++,"|");
      }
      xOffset = originalx;
      yOffset++;

    }
  }

*/
void Board::horizontal(int yLoc) {
  int visualWidth = width_;


  mvprintw(yLoc, xLocation_, string(visualWidth * 6 + 1, '-').c_str());
}

void Board::vertical(int xLoc) {
  int visualHeight = height_;
  for (int i = 0; i < visualHeight * 3 + 1; i++) {
    if (i % 3 == 0) {
      mvprintw(i + yLocation_, xLoc, "+");
    } else {
      mvprintw(i + yLocation_, xLoc, "|");
    }
  }
}
void Board::printJumbo() {

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







void Board::place(int colNum, int rowNum,  int token) {
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


const char * Board::getToken(int key, int lineNum) {
  switch (key) {
  case 0: return "   ";
  case 1: if (lineNum == 1)return "/T\\";
    if (lineNum == 2)return "\\_/";
  case 2: if (lineNum == 1) return "\\_/";
    if (lineNum == 2) return "/ \\";
    //default: return {'?'};
  }
  char * missing = new char[1];
  missing[0] = '?';
  return missing;
}

//[x][y]
const int*Board::operator[](int i) const {

  return grid[i];
}


const int Board::getWidth() const {
  return width_;
}

const int Board::getHeight() const {
  return height_;
}
