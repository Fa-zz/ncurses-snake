#pragma once
#include <ncurses.h>
#include "Board.hpp"

// this is the main controller of the game
class SnakeGame {
public:
    SnakeGame(int height, int width) {
        board = Board(height, width);
        board.initialize();
        game_over = false;
    }

    void processInput() {
        chtype input = board.getInput();
        // process input in the future
    }

    void updateState() {
        // doesn't really do anything rn, but would update snake and score
    }

    void redraw() {
        board.refresh();
    }

    bool isOver() {
        return game_over;
    }
private:
    Board board;
    bool game_over;
};