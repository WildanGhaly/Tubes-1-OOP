#ifndef _SWITCH_CARD_HPP_
#define _SWITCH_CARD_HPP_


#include "../Player/ListPlayerVec.hpp"
#include "../Player/PlayerVec.hpp"
#include "../Game/GameVec.hpp"

class Switch : public ListPlayerVec ,public GameVec{
    public:
        Switch(int, int);
};


#endif