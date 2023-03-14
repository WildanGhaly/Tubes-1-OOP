#ifndef _REVERSEDIR_HPP_
#define _REVERSEDIR_HPP_

#include <iostream>
#include "../Player/ListPlayerVec.hpp"
#include "Ability.hpp"

class ReverseDirection : public ListPlayerVec, public Ability{
    public:
        /* ctor cctor dtor */
        ReverseDirection();
        // ~ReverseDirection();
        void useAbility();

};


#endif