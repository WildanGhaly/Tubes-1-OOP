#ifndef _ABILITYLESS_HPP
#define _ABILITYLESS_HPP

#include <iostream>
#include "../Player/PlayerList.hpp"
#include "Ability.hpp"

class Abilityless : public PlayerList, public Ability {
    public :
    Abilityless();
    void useAbility(int);
};  


#endif
