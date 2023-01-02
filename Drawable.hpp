#pragma once
#include <ncurses.h>

class Drawable {
public:
    // default constructor
    Drawable() {
        // default case, it's in the top left corner
        y = x = 0;
        icon = ' ';
    }

    // parameterized constructor
    Drawable(int y, int x, chtype ch) {
        this->y = y;
        this->x = x;
        this->icon = ch;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    chtype getIcon() {
        return icon;
    }

protected:
    int y, x;
    chtype icon;
};