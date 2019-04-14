#include "global.hpp"
#include "turmite_factory.hpp"

int x = pixel_darstellbar_x / 2;
int y = pixel_darstellbar_y / 2;

std::vector<Turmite> create_turmites()
{
    std::vector<Turmite> ret;

    Turmite a(10, 10, v2(x, y), v2(0, -1));

    //void Turmite::add_rule(int board_state, int internal_state, int new_board_state, int new_internal_state, translation_function func)

    a.add_rule(0, 0, 1, 0, turn_right);
    a.add_rule(0, 1, 1, 1, turn_left);

    a.add_rule(1, 0, 2, 0, turn_right);
    a.add_rule(1, 1, 2, 1, turn_left);

    a.add_rule(2, 0, 3, 0, turn_left);
    a.add_rule(2, 1, 3, 1, turn_right);

    a.add_rule(3, 0, 0, 1, turn_left);
    a.add_rule(3, 1, 0, 0, turn_right);

    ret.push_back(a);
    return ret;
}