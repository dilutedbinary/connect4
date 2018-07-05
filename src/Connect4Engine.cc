
#include "Connect4Engine.h"

const int Engine::checkState(const C4BoardState *board, int currentPlayer) {
    int width = C4BoardStateInterface::getWidth(board);
    int height = C4BoardStateInterface::getHeight(board);


    //check horizontal
    for (int i = 0; i < width - 4; i++) {
        for (int j = 0; j < height; j++) {
            if (board[i][j] == board[i + 1][j] &&
                board[i + 1][j] == board[i + 2][j] &&
                board[i + 2][j] == board[i + 3][j]) {
                if (board[i][j] != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;


}
