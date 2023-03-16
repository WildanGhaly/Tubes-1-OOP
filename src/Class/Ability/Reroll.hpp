#ifndef _REROLL_HPP
#define _REROLL_HPP

#include "../Player/PlayerList.hpp"
#include "Ability.hpp"
#include "../Game/Game.hpp"

class Reroll : public Ability {
    public :
    Reroll();
    bool useAbility(Game<Card>&, int, int);
};  


#endif
