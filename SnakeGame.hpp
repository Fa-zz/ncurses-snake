#pragma once
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "Board.hpp"
#include "Apple.hpp"
#include "Empty.hpp"

// The SnakeGame class is the main controller of the game

class SnakeGame {
public:
    SnakeGame(int height, int width) {
        board = Board(height, width);
        board.initialize();
        game_over = false;

        // inits random seed
        srand(time(NULL));
    }

    void processInput() {
        chtype input = board.getInput();
        // process input in the future
    }

    void updateState() {
        int y, x; // x, y: the coords for the apple drawable, not populated yet

        // board gets a set of empty coords and populates the y and x value
        board.getEmptyCoordinates(y, x);

        if (apple != NULL)
            board.add(Empty(apple->getY(), apple->getX()));
        
        // Apple(y, x) constructs an Apple object with the y, x vars
        apple = new Apple(y, x);

        // Apple is then added to board
        board.add(*apple);
    }

    void redraw() {
        board.refresh();
    }

    bool isOver() {
        return game_over;
    }

    ~SnakeGame() {
        delete apple;
    }
private:
    Board board;
    bool game_over;
    Apple *apple;
};