#ifndef _SWAP_CARD_HPP_
#define _SWAP_CARD_HPP_

#include "../Player/ListPlayerVec.hpp"
#include "../Player/PlayerVec.hpp"
#include "../Game/GameVec.hpp"

class SwapCard : public ListPlayerVec, public GameVec{
    public:
        /* ctor cctor dtor */
        SwapCard(int, int, int, int);

        // int data;
};


#endif