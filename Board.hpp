#pragma once
#include <stdlib.h>
#include "Drawable.hpp"

//  TODO: move definitions to separate .cpp file

class Board {
public:
    // default constructor
    Board() {
        construct(0, 0);
    }

    // parameterized constructor
    Board(int height, int width) {
        construct(height, width);
    }

    // initialize: Inits the board
    void initialize() {
        clear();
        refresh();
    }

    // addBorder: adds border around window/board
    void addBorder() {
        box(board_win, 0, 0);
    }

    // add: Add an entity/drawable to the board using the x and y coords of the drawable
    void add(Drawable drawable) {
        addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
    }

    // addAt: Add a char at the coords that are passed in
    void addAt(int y, int x, chtype ch) {
        mvwaddch(board_win, y, x, ch);
    }

    // getInput: 
    chtype getInput() {
        return wgetch(board_win);
    }

    // clear: Clears the whole window. Everytime we clear the window (e.g. when game over) we want to re-add the border
    // Preconditions: 
    // Postconditions: 
    void clear() {
        wclear(board_win);
        addBorder();
    }

    // getEmptyCoordinates: Populates a passed by reference y and x coords with randomly selected empty coords from the board
    void getEmptyCoordinates(int& y, int& x) {
         // mvwinch returns whatever character is in y and x
         // this line loops until it finds an empty spot on the board, y and x are then populated
        while((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' ');
    }

    // refresh: Updates the board
    // Preconditions: 
    // Postconditions: 
    void refresh() {
        wrefresh(board_win);
    }

private:
    WINDOW* board_win;
    int height, width;

    void construct(int height, int width) {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);

        this->height = height;
        this->width = width;

        board_win = newwin(height, width, (yMax/2) - (height/2), (xMax/2)- (width/2));

    }
};