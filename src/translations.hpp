#ifndef TRANSLATION_GUARD
#define TRANSLATION_GUARD

#include "global.hpp"

class Ant;

using translation_function = void (*)(Ant& a);

void turn_right(Ant& a);
void turn_left(Ant& a);
void straight(Ant& a);
void jump_left(Ant& a);
void jump_right(Ant& a);

#endif // !TRANSLATION_GUARD
