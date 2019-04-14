#ifndef TRANSLATION_GUARD
#define TRANSLATION_GUARD

#include "global.hpp"


struct Translation_State
{
    v2 dir;
    v2 pos;

};


using translation_function = void (*)(Translation_State& t);

void turn_right(Translation_State& t);
void turn_left(Translation_State& t);
void straight(Translation_State& t);
void jump_left(Translation_State& t);
void jump_right(Translation_State& t);
void diag_right(Translation_State& t);
void diag_left(Translation_State& t);

#endif // !TRANSLATION_GUARD
