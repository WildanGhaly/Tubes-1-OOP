#ifndef _QUADRUPLE_HPP
#define _QUADRUPLE_HPP

#include <iostream>
#include "Ability.hpp"
#include "../Table/Table.hpp"

class Quadruple : public Ability {
    public :
        Quadruple();
        void useAbility();
        void useAbilitys(Game<Card>&, int);
};


#endif