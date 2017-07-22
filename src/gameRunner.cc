#include <iostream>
#include <ncurses.h>
#include "engine.h"

using namespace std;

/*    Main Method    */
const int YLOCATION = 12;
const int XLOCATION = 5;
const int BOARDWIDTH = 10;
void destroy_win(WINDOW *local_win);
WINDOW *create_newwin(int height, int width, int starty, int startx);
void printDropper(int, Board *, int);

int main() {
    WINDOW *my_win;
    int startx, starty, width, height;
    initscr();/* Start curses mode */
    cbreak();/* Line buffering disabled, Pass on
                * everty thing to me */
    keypad(stdscr, TRUE);/* I need that nifty F1 */

    height = 3;
    width = 10;
    starty = (LINES - height) / 2;/* Calculating for a center placement */
    startx = (COLS - width) / 2;/* of the window*/
    printw("Press F1 to exit");
    refresh();
    my_win = create_newwin(height, width, starty, startx);


    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);

    int currentPlayer = 1;
    int currRow = 5;
    Board* board = new Board(7, BOARDWIDTH, XLOCATION, YLOCATION);
    initscr();
    clear();
    noecho();
    cbreak();
    currRow++;
    keypad(stdscr, TRUE);
    refresh();
    int c = 66;


    while (true) {

        mvprintw(2, 5, "Hello!");
        mvprintw(3, 5, "Current Row : %d", currRow);
        mvprintw(4, 5, "Current width : %d", COLS);
        mvprintw(2, 0, "%d", c);
        c = getch();
        refresh();
        switch (c) {
            case 260:
            mvprintw(1, 1, "pressed Left");
            if (currRow == 0) {
                break;
            }
            moveLeft();
            break;
            case 261:
            if (currRow == BOARDWIDTH - 1) {
                break;
            }
            mvprintw(1, 1, "pressed right");
            moveRight();
            ;
            case 258:

            mvprintw(0, 1, "Dropped");

            board->drop(currRow, currentPlayer);
            currentPlayer = 3 - currentPlayer;
            break;
            default:
            mvprintw(0, 1, "Invalid Key Entry");


        }

        printDropper(currRow, board, currentPlayer);
        board->printJumbo();

        //if(Engine::checkState(board,currentPlayer)==1){

        //mvprintw(0,0,"Player %d has ones", currentPlayer);
        //}
    }
    endwin();
    return 0;
}




void clearDropperRow() {
    for (int i = 1; i <= 6; i++) {
        mvprintw(YLOCATION - i, 0, string(COLS, ' ').c_str());
    }

}

void moveRight() {
    mvprintw(YLOCATION - 6, 0, string(COLS, '=').c_str());
    int startRow = currRow;


}


void printDropper(int row, int currentPlayer) {
    clearDropperRow();
    int visualRow = row * 6 + XLOCATION - 1;

    mvprintw(YLOCATION - 5, visualRow, "   /X\\");
    mvprintw(YLOCATION - 4, visualRow, "  // \\\\");
    mvprintw(YLOCATION - 3, visualRow, " //   \\\\");
    mvprintw(YLOCATION - 2, visualRow, " \\\\");
    attron(COLOR_PAIR(currentPlayer));
    mvprintw(YLOCATION - 2, visualRow + 3, board->getToken(currentPlayer, 1));

    mvprintw(YLOCATION - 1, visualRow + 3, board->getToken(currentPlayer, 2));
    attroff(COLOR_PAIR(currentPlayer));
    mvprintw(YLOCATION - 2, visualRow + 6, "//");



}


WINDOW *create_newwin(int height, int width, int starty, int startx)
{   WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);/* 0, 0 gives default characters
                                * for the vertical and horizontal
                                * lines*/
    wrefresh(local_win);/* Show that box */

    return local_win;
}


void destroy_win(WINDOW *local_win)
{
    /* box(local_win, ' ', ' '); : This won't produce the desired
        * result of erasing the window. It will leave it's four corners
        * and so an ugly remnant of window.
        */
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    /* The parameters taken are
        * 1. win: the window on which to operate
        * 2. ls: character to be used for the left side of the window
        * 3. rs: character to be used for the right side of the window
        * 4. ts: character to be used for the top side of the window
        * 5. bs: character to be used for the bottom side of the window
        * 6. tl: character to be used for the top left corner of the window
        * 7. tr: character to be used for the top right corner of the window
        * 8. bl: character to be used for the bottom left corner of the window
        * 9. br: character to be used for the bottom right corner of the window
        */
    wrefresh(local_win);
    delwin(local_win);
}
