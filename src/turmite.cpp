#include "turmite.hpp"

Turmite::Turmite(int max_board_states, int max_internal_states, v2 start_pos, v2 start_dir)
{
    _rules.resize(max_board_states);
    for (size_t i = 0; i < max_board_states; i++)
    {
        _rules[i].resize(max_internal_states);
    }

    _pos = start_pos;
    _dir = start_dir;
}

Turmite::~Turmite()
{
}

void Turmite::add_rule(int board_state, int internal_state, int new_board_state, int new_internal_state, translation_function func)
{
    _rules[board_state][internal_state] = Rule_Out(new_internal_state, new_board_state, func);
}

void Turmite::update(Board &b)
{
    Rule_Out out = _rules[b.get(_pos.x, _pos.y)][_internal_state];

    b.set(_pos.x, _pos.y, out.new_board);
    _internal_state = out.new_internal;

    Translation_State buffer;
    buffer.pos = _pos;
    buffer.dir = _dir;
    out.func(buffer);

    _pos = buffer.pos;
    _dir = buffer.dir;
}