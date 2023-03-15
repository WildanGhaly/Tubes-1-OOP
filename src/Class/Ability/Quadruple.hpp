#ifndef _QUADRUPLE_HPP
#define _QUADRUPLE_HPP

#include <iostream>
#include "../Ability/Ability.hpp"
#include "../Table/Table.hpp"

class Quadruple : public Ability, public Table {
    public :
        Quadruple();
        void useAbility();
    
};


#endif