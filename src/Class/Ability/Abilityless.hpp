#ifndef _ABILITYLESS_HPP
#define _ABILITYLESS_HPP

#include <iostream>
#include "../Player/PlayerVec.hpp"
#include "../Ability/Ability.hpp"

class Abilityless : public PlayerVec, public Ability {
    public :
    Abilityless();
    void useAbility();
};  


#endif
