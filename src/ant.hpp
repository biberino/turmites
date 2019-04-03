#ifndef ANT_GUARD
#define ANT_GUARD

#include <unordered_map>

#include "global.hpp"
#include "translations.hpp"
#include "basic_rule.hpp"
#include "board.hpp"




class BasicRule;

class Ant
{
private:
    BasicRule *_default_rule;

    std::unordered_map<int,BasicRule*> ruleset;
public:
    Ant(BasicRule* default_rule, v2 start_pos, v2 start_dir);
    ~Ant();

    void add_rule(BasicRule *new_rule);
    //void remove_rule(BasicRule old_rule);

    void update(Board &b);

    
    v2 _direction;;
    v2 _pos;
};




#endif // !ANT_GUARD
