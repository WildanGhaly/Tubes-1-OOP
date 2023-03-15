#ifndef _REROLL_HPP
#define _REROLL_HPP

#include <iostream>
#include "../Player/PlayerVec.hpp"
#include "../Ability/Ability.hpp"

class Reroll : public PlayerVec, public Ability {
    public :
    Reroll();
    void useAbility();
};  


#endif
