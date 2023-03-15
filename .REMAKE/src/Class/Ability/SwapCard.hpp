#ifndef _SWAP_CARD_HPP_
#define _SWAP_CARD_HPP_

#include "../Player/PlayerList.hpp"
#include "Ability.hpp"

class SwapCard : public Ability, public PlayerList{
    public:
        /* ctor cctor dtor */
        SwapCard();
        void useAbility(int, int, int, int);

        // int data;
};


#endif