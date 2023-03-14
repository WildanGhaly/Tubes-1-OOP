#ifndef _SWITCH_CARD_HPP_
#define _SWITCH_CARD_HPP_


#include "../Player/PlayerList.hpp"
#include "Ability.hpp"

class Switch : public PlayerList, public Ability{
    public:
        Switch();
        void useAbility(int);
};


#endif