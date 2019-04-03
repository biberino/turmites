#include "ant.hpp"


Ant::Ant(BasicRule *default_rule, v2 start_pos, v2 start_dir) : _direction(0, -1), _pos(0, 0)
{
    _default_rule = default_rule;
    _direction = start_dir;
    _pos = start_pos;
}

void Ant::add_rule(BasicRule *new_rule)
{
    if (ruleset.find(new_rule->_input_state) != ruleset.end())
        return;
    ruleset[new_rule->_input_state] = new_rule;
}

void Ant::update(Board &b)
{
    int state = b.get(_pos.x,_pos.y);
    
    int out = _default_rule->_output_state;
    translation_function func = _default_rule->_func;

    if (ruleset.find(state) != ruleset.end())
    {
        out = ruleset[state]->_output_state;
        func = ruleset[state]->_func;
    }

    b.set(_pos.x,_pos.y,out);
    func(*this);
}

Ant::~Ant()
{
}