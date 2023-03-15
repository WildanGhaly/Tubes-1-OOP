#ifndef _QUARTER_HPP
#define _QUARTER_HPP

#include <iostream>
#include "Ability.hpp"
#include "../Table/Table.hpp"

template<class T>
class Quarter : public Ability<T>  {
    public :
        Quarter();
        T useAbility(T);
};


#endif