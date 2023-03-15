#ifndef _REVERSEDIR_HPP_
#define _REVERSEDIR_HPP_

#include "../Player/PlayerList.hpp"
#include "Ability.hpp"
#include "../Game/Game.hpp"

class ReverseDirection : public PlayerList, public Ability{
    public:
        /* ctor cctor dtor */
        ReverseDirection();
        // ~ReverseDirection();
        // void useAbility();
        bool useAbility(Game<Card>&, int, int);

};


#endif