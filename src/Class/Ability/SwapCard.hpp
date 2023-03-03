#ifndef _SWAP_CARD_HPP_
#define _SWAP_CARD_HPP_

#include "../Player/Player.hpp"
#include "../Player/ListPlayerVec.hpp"
#include "../Player/PlayerVec.hpp"
#include "../Card/CardListVec.hpp"

class SwapCard : public ListPlayerVec{
    public:
        /* ctor cctor dtor */
        SwapCard(int, int, int, int);

        // int data;
};


#endif