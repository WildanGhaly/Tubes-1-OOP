#ifndef _QUADRUPLE_HPP
#define _QUADRUPLE_HPP

#include <iostream>
#include "Ability.hpp"
#include "../Table/Table.hpp"
#include "../Game/Game.hpp"


class Quadruple : public Ability {
    public :
        Quadruple();
        void useAbility();
        void useAbilitys(Game<Card>&, int);
};
    


#endif