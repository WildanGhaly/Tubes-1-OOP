#ifndef _ABILITYLESS_HPP
#define _ABILITYLESS_HPP

#include <iostream>
#include "../Game/Game.hpp"
#include "Ability.hpp"

class Abilityless : public Ability {
    public :
    Abilityless();
    bool useAbility(Game<Card>&, int, int);
};  


#endif
