#pragma once
#include <ncurses.h>
#include "Drawable.hpp"

class Apple : public Drawable {
public:
    // constructor
    Apple(int y, int x) {
        this->y = y;
        this->x = x;
        this->icon = 'A';
    }

    // logic of apple appearing: choose a random Empty spot on the board to place apple
};