#ifndef _SWAP_CARD_HPP_
#define _SWAP_CARD_HPP_

#include "../Player/PlayerList.hpp"
#include "Ability.hpp"
#include "../Game/Game.hpp"

class SwapCard : public Ability{
    public:
        /* ctor cctor dtor */
        SwapCard();
        bool useAbility(Game<Card>&, int, int);

        // int data;
};


#endif