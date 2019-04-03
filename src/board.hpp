#ifndef BOARD_GUARD
#define BOARD_GUARD

#include "global.hpp"
#include "DrawHelper.hpp"

class Board
{
private:
    int board_array[pixel_darstellbar_x][pixel_darstellbar_y];
    DrawHelper drawHelper;
public:
    Board();
    ~Board();


    void set(int x, int y, int state);
    int get(int x, int y);
    void draw();

};

#endif


