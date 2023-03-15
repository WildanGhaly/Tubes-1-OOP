#ifndef _SWITCH_CARD_HPP_
#define _SWITCH_CARD_HPP_


#include "../Player/ListPlayerVec.hpp"
#include "../Ability/Ability.hpp"

class Switch : public ListPlayerVec, public Ability{
    public:
        Switch();
        void useAbility(int);
};


#endif