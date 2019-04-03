#ifndef RULE1212_GUARD
#define RULE1212_GUARD

#include "translations.hpp"
#include "global.hpp"
#include "ant.hpp"
#include "board.hpp"


class BasicRule
{
  private:
    

  public:
    

    int _input_state;
    int _output_state;
    translation_function _func;

    BasicRule();
    BasicRule(int input_state, int output_state, translation_function func);
    ~BasicRule();

};

#endif // !RULE_GUARD