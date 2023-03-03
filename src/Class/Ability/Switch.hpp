#ifndef _SWITCH_CARD_HPP_
#define _SWITCH_CARD_HPP_


#include "../Player/Player.hpp"
#include "../Player/ListPlayerVec.hpp"
#include "../Player/PlayerVec.hpp"
#include "../Card/CardListVec.hpp"

class Switch : public ListPlayerVec{
    public:
        Switch(int, int);
};


#endif