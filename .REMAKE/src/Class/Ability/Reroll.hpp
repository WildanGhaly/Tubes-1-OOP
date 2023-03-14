#ifndef _REROLL_HPP
#define _REROLL_HPP

#include "../Player/PlayerList.hpp"
#include "Ability.hpp"

class Reroll : public PlayerList, public Ability {
    public :
    Reroll();
    void useAbility();
};  


#endif
