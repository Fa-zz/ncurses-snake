#include <ncurses.h>
#include "Board.hpp"

// defining consts to represent board dimensions
#define BOARD_DIM 17
#define BOARD_ROWS BOARD_DIM // there should be less rows than cols, bc the cols are thinner
#define BOARD_COLS BOARD_DIM * 2.5

int main(int argc, char **argv) {
    
    initscr();
    refresh();

    Board board(BOARD_ROWS, BOARD_COLS);

    getch();
    endwin();
}