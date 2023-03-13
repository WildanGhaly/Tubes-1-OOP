#ifndef _QUARTER_HPP
#define _QUARTER_HPP

#include <iostream>
#include "../Ability/Ability.hpp"
#include "../Table/Table.hpp"

class Quarter : public Table, public Ability  {
    public :
        Quarter();
        void useAbility();
};


#endif