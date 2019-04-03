#include "board.hpp"

Board::Board(/* args */)
{
    for (size_t i = 0; i < pixel_darstellbar_x; i++)
    {
        for (size_t j = 0; j < pixel_darstellbar_y; j++)
        {
            board_array[i][j] = 0;
        }
    }
}

Board::~Board()
{
}

void Board::set(int x, int y, int state)
{
    if (x >= pixel_darstellbar_x) x = x%pixel_darstellbar_x;
    if (y >= pixel_darstellbar_y) y = y%pixel_darstellbar_y;
    if (x <0) x += pixel_darstellbar_x;
    if (y <0) y += pixel_darstellbar_y;

    board_array[x][y] = state;
}

int Board::get(int x, int y)
{
    if (x >= pixel_darstellbar_x) x = x%pixel_darstellbar_x;
    if (y >= pixel_darstellbar_y) y = y%pixel_darstellbar_y;
    if (x <0) x += pixel_darstellbar_x;
    if (y <0) y += pixel_darstellbar_y;
    return board_array[x][y];
}

void Board::draw()
{
    for (size_t i = 0; i < pixel_darstellbar_x; i++)
    {
        for (size_t j = 0; j < pixel_darstellbar_y; j++)
        {
            rectange_t rect;
            rect.x1 = i*pixel_w;
            rect.y1 = j*pixel_h;
            rect.x2 = rect.x1+pixel_w;
            rect.y2 = rect.y1+pixel_h;

            drawHelper.draw_rect_glut(rect, colors::colorVec[board_array[i][j]]);
        }
    }
}
