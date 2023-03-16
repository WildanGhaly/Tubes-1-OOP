#ifndef _SWITCH_CARD_HPP_
#define _SWITCH_CARD_HPP_


#include "../Game/Game.hpp"
#include "Ability.hpp"

class Switch : public Ability{
    public:
        Switch();
        bool useAbility(Game<Card>&, int, int);
};


#endif