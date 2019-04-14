#ifndef TURMITE_GUARD
#define TURMITE_GUARD

#include <vector>

#include "translations.hpp"
#include "board.hpp"

class Turmite
{
  private:
    struct Rule_Out
    {
        int new_internal;
        int new_board;
        translation_function func;

        Rule_Out()
        {
            new_board = -1;
            new_internal = -1;
            func = nullptr;

        }

        Rule_Out(const Rule_Out &r)
        {
            new_internal = r.new_internal;
            new_board = r.new_board;
            func = r.func;
        }

        Rule_Out(int i, int b, translation_function f)
        {
            new_internal = i;
            new_board = b;
            func = f;
        }

        Rule_Out &operator=(const Rule_Out &r)
        {
            new_internal = r.new_internal;
            new_board = r.new_board;
            func = r.func;
            return *this;
        }
    };

    std::vector<std::vector<Rule_Out>> _rules;
    int _internal_state = 0;
    v2 _dir;
    v2 _pos;

  public:
    Turmite(int max_board_states, int max_internal_states, v2 start_pos, v2 start_dir);

    void add_rule(int board_state, int internal_state, int new_board_state, int new_internal_state, translation_function func);

    void update(Board &b);
    ~Turmite();
};

#endif // !TURMITE_GUARD
