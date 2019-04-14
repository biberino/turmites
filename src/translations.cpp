#include "translations.hpp"

const v2 UP(0, -1);
const v2 DOWN(0, 1);
const v2 LEFT(-1, 0);
const v2 RIGHT(1, 0);

void turn_right(Translation_State& t)
{
    if (t.dir == UP)
    {

        t.dir = RIGHT;
    }
    else if (t.dir == RIGHT)
    {
        t.dir = DOWN;
    }
    else if (t.dir == DOWN)
    {
        t.dir = LEFT;
    }
    else if (t.dir == LEFT)
    {
        t.dir = UP;
    }
    t.pos = t.dir + t.pos;

    if (t.pos.x >= pixel_darstellbar_x)
        t.pos.x = t.pos.x % pixel_darstellbar_x;
    if (t.pos.y >= pixel_darstellbar_y)
        t.pos.y = t.pos.y % pixel_darstellbar_y;
    if (t.pos.x < 0)
        t.pos.x += pixel_darstellbar_x;
    if (t.pos.y < 0)
        t.pos.y += pixel_darstellbar_y;
}
void turn_left(Translation_State& t)
{
    if (t.dir == UP)
    {

        t.dir = LEFT;
    }
    else if (t.dir == RIGHT)
    {
        t.dir = UP;
    }
    else if (t.dir == DOWN)
    {
        t.dir = RIGHT;
    }
    else if (t.dir == LEFT)
    {
        t.dir = DOWN;
    }
    t.pos = t.dir + t.pos;

    if (t.pos.x >= pixel_darstellbar_x)
        t.pos.x = t.pos.x % pixel_darstellbar_x;
    if (t.pos.y >= pixel_darstellbar_y)
        t.pos.y = t.pos.y % pixel_darstellbar_y;
    if (t.pos.x < 0)
        t.pos.x += pixel_darstellbar_x;
    if (t.pos.y < 0)
        t.pos.y += pixel_darstellbar_y;
}

void straight(Translation_State& t)
{
    t.pos = t.dir + t.pos;

    if (t.pos.x >= pixel_darstellbar_x)
        t.pos.x = t.pos.x % pixel_darstellbar_x;
    if (t.pos.y >= pixel_darstellbar_y)
        t.pos.y = t.pos.y % pixel_darstellbar_y;
    if (t.pos.x < 0)
        t.pos.x += pixel_darstellbar_x;
    if (t.pos.y < 0)
        t.pos.y += pixel_darstellbar_y;
}

void jump_left(Translation_State& t)
{
    if (t.dir == UP)
    {

        t.dir = LEFT;
    }
    else if (t.dir == RIGHT)
    {
        t.dir = UP;
    }
    else if (t.dir == DOWN)
    {
        t.dir = RIGHT;
    }
    else if (t.dir == LEFT)
    {
        t.dir = DOWN;
    }
    t.pos = t.dir * 2 + t.pos;

    if (t.pos.x >= pixel_darstellbar_x)
        t.pos.x = t.pos.x % pixel_darstellbar_x;
    if (t.pos.y >= pixel_darstellbar_y)
        t.pos.y = t.pos.y % pixel_darstellbar_y;
    if (t.pos.x < 0)
        t.pos.x += pixel_darstellbar_x;
    if (t.pos.y < 0)
        t.pos.y += pixel_darstellbar_y;
}

void jump_right(Translation_State& t)
{
    if (t.dir == UP)
    {

        t.dir = RIGHT;
    }
    else if (t.dir == RIGHT)
    {
        t.dir = DOWN;
    }
    else if (t.dir == DOWN)
    {
        t.dir = LEFT;
    }
    else if (t.dir == LEFT)
    {
        t.dir = UP;
    }
    t.pos = t.dir * 2 + t.pos;

    if (t.pos.x >= pixel_darstellbar_x)
        t.pos.x = t.pos.x % pixel_darstellbar_x;
    if (t.pos.y >= pixel_darstellbar_y)
        t.pos.y = t.pos.y % pixel_darstellbar_y;
    if (t.pos.x < 0)
        t.pos.x += pixel_darstellbar_x;
    if (t.pos.y < 0)
        t.pos.y += pixel_darstellbar_y;
}

void diag_right(Translation_State& t)
{
    v2 old = t.dir;
    if (t.dir == UP)
    {
        t.dir = RIGHT;
    }
    else if (t.dir == RIGHT)
    {
        t.dir = DOWN;
    }
    else if (t.dir == DOWN)
    {
        t.dir = LEFT;
    }
    else if (t.dir == LEFT)
    {
        t.dir = UP;
    }
    t.pos = t.dir + t.pos + old;

    if (t.pos.x >= pixel_darstellbar_x)
        t.pos.x = t.pos.x % pixel_darstellbar_x;
    if (t.pos.y >= pixel_darstellbar_y)
        t.pos.y = t.pos.y % pixel_darstellbar_y;
    if (t.pos.x < 0)
        t.pos.x += pixel_darstellbar_x;
    if (t.pos.y < 0)
        t.pos.y += pixel_darstellbar_y;
}
void diag_left(Translation_State& t)
{
    v2 old = t.dir;
    if (t.dir == UP)
    {

        t.dir = LEFT;
    }
    else if (t.dir == RIGHT)
    {
        t.dir = UP;
    }
    else if (t.dir == DOWN)
    {
        t.dir = RIGHT;
    }
    else if (t.dir == LEFT)
    {
        t.dir = DOWN;
    }
    t.pos = t.dir + t.pos + old;

    if (t.pos.x >= pixel_darstellbar_x)
        t.pos.x = t.pos.x % pixel_darstellbar_x;
    if (t.pos.y >= pixel_darstellbar_y)
        t.pos.y = t.pos.y % pixel_darstellbar_y;
    if (t.pos.x < 0)
        t.pos.x += pixel_darstellbar_x;
    if (t.pos.y < 0)
        t.pos.y += pixel_darstellbar_y;
}