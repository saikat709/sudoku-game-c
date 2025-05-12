#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

class Cell {
    private:
        int value;
        bool isSelected;

    public:
        void setSelected(bool value);
        bool getSelected();
        void drawCell(int startX, int startY );
};


#endif