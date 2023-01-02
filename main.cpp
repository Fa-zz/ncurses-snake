#include <ncurses.h>
#include "Board.hpp"
#include "SnakeGame.hpp"
#include "Drawable.hpp"

// defining consts to represent board dimensions
#define BOARD_DIM 17
#define BOARD_ROWS BOARD_DIM // there should be less rows than cols, bc the cols are thinner
#define BOARD_COLS BOARD_DIM * 2.5

int main(int argc, char **argv) {
    
    initscr();
    refresh();

    //noecho();
    SnakeGame game = SnakeGame(BOARD_ROWS, BOARD_COLS);

    while (!game.isOver()) {
        game.processInput(); // 1. get input from user (but do not wait indefinitely for input)
        game.updateState(); // 2. update game state
        game.redraw(); // 3. redraw display
        // 4. go to 1, unless game over
    }

    getch();
    endwin();
}