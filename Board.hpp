#pragma once

//  TODO: move definitions separate .cpp file

class Board {
public:
    // basic constructor
    Board(int height, int width) {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);

        board_win = newwin(height, width, (yMax/2) - (height/2), (xMax/2)- (width/2));
        //box(board_win, 0, 0);
        //wrefresh(board_win);
    }

    // initialize: Inits the board
    void initialize() {
        clear();
        refresh();
    }

    // addBorder: adds border around window/board
    // Preconditions: 
    // Postconditions: 
    void addBorder() {
        box(board_win, 0, 0);
    }

    // addAt: 
    void addAt(int y, int x, chtype ch) {
        mvwaddch(board_win, y, x, ch);
    }

    // clear: Clears the whole window. Everytime we clear the window (e.g. when game over) we want to re-add the border
    // Preconditions: 
    // Postconditions: 
    void clear() {
        wclear(board_win);
        addBorder();
    }

    // refresh: Updates the board
    // Preconditions: 
    // Postconditions: 
    void refresh() {
        wrefresh(board_win);
    }

private:
    WINDOW* board_win;
};