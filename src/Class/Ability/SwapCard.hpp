#ifndef _SWAP_CARD_HPP_
#define _SWAP_CARD_HPP_

#include "../Player/ListPlayerVec.hpp"
#include "../Ability/Ability.hpp"

class SwapCard : public Ability, public ListPlayerVec{
    public:
        /* ctor cctor dtor */
        SwapCard();
        void useAbility(int, int, int, int);

        // int data;
};


#endif