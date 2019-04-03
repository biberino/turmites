#include "basic_rule.hpp"


BasicRule::BasicRule(int input_state, int output_state, translation_function func)
{
    _input_state = input_state;
    _output_state = output_state;
    _func = func;
}

BasicRule::BasicRule()
{
    _input_state = 0;
    _output_state = 1;
    _func = nullptr;
}

BasicRule::~BasicRule()
{
}