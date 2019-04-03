#include "translations.hpp"
#include "ant.hpp"

const v2 UP(0, -1);
const v2 DOWN(0, 1);
const v2 LEFT(-1, 0);
const v2 RIGHT(1, 0);

void turn_right(Ant &a)
{
    if (a._direction == UP)
    {

        a._direction = RIGHT;
    }
    else if (a._direction == RIGHT)
    {
        a._direction = DOWN;
    }
    else if (a._direction == DOWN)
    {
        a._direction = LEFT;
    }
    else if (a._direction == LEFT)
    {
        a._direction = UP;
    }
    a._pos = a._direction + a._pos;

    if (a._pos.x >= pixel_darstellbar_x)
        a._pos.x = a._pos.x % pixel_darstellbar_x;
    if (a._pos.y >= pixel_darstellbar_y)
        a._pos.y = a._pos.y % pixel_darstellbar_y;
    if (a._pos.x < 0)
        a._pos.x += pixel_darstellbar_x;
    if (a._pos.y < 0)
        a._pos.y += pixel_darstellbar_y;
}
void turn_left(Ant &a)
{
    if (a._direction == UP)
    {

        a._direction = LEFT;
    }
    else if (a._direction == RIGHT)
    {
        a._direction = UP;
    }
    else if (a._direction == DOWN)
    {
        a._direction = RIGHT;
    }
    else if (a._direction == LEFT)
    {
        a._direction = DOWN;
    }
    a._pos = a._direction + a._pos;

    if (a._pos.x >= pixel_darstellbar_x)
        a._pos.x = a._pos.x % pixel_darstellbar_x;
    if (a._pos.y >= pixel_darstellbar_y)
        a._pos.y = a._pos.y % pixel_darstellbar_y;
    if (a._pos.x < 0)
        a._pos.x += pixel_darstellbar_x;
    if (a._pos.y < 0)
        a._pos.y += pixel_darstellbar_y;
}

void straight(Ant &a)
{
    a._pos = a._direction + a._pos;

    if (a._pos.x >= pixel_darstellbar_x)
        a._pos.x = a._pos.x % pixel_darstellbar_x;
    if (a._pos.y >= pixel_darstellbar_y)
        a._pos.y = a._pos.y % pixel_darstellbar_y;
    if (a._pos.x < 0)
        a._pos.x += pixel_darstellbar_x;
    if (a._pos.y < 0)
        a._pos.y += pixel_darstellbar_y;
}

void jump_left(Ant &a)
{
    if (a._direction == UP)
    {

        a._direction = LEFT;
    }
    else if (a._direction == RIGHT)
    {
        a._direction = UP;
    }
    else if (a._direction == DOWN)
    {
        a._direction = RIGHT;
    }
    else if (a._direction == LEFT)
    {
        a._direction = DOWN;
    }
    a._pos = a._direction*2 + a._pos;

    if (a._pos.x >= pixel_darstellbar_x)
        a._pos.x = a._pos.x % pixel_darstellbar_x;
    if (a._pos.y >= pixel_darstellbar_y)
        a._pos.y = a._pos.y % pixel_darstellbar_y;
    if (a._pos.x < 0)
        a._pos.x += pixel_darstellbar_x;
    if (a._pos.y < 0)
        a._pos.y += pixel_darstellbar_y;
}

void jump_right(Ant &a)
{
    if (a._direction == UP)
    {

        a._direction = RIGHT;
    }
    else if (a._direction == RIGHT)
    {
        a._direction = DOWN;
    }
    else if (a._direction == DOWN)
    {
        a._direction = LEFT;
    }
    else if (a._direction == LEFT)
    {
        a._direction = UP;
    }
    a._pos = a._direction*2 + a._pos;

    if (a._pos.x >= pixel_darstellbar_x)
        a._pos.x = a._pos.x % pixel_darstellbar_x;
    if (a._pos.y >= pixel_darstellbar_y)
        a._pos.y = a._pos.y % pixel_darstellbar_y;
    if (a._pos.x < 0)
        a._pos.x += pixel_darstellbar_x;
    if (a._pos.y < 0)
        a._pos.y += pixel_darstellbar_y;
}