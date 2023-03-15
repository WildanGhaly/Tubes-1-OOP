#ifndef _QUARTER_HPP
#define _QUARTER_HPP

#include <iostream>
#include "Ability.hpp"
#include "../Game/Game.hpp"


class Quarter : public Ability  {
    public :
        Quarter();
        bool useAbility(Game<Card>&, int , int);
};


#endif