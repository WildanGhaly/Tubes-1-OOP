#ifndef _REVERSEDIR_HPP_
#define _REVERSEDIR_HPP_

#include <iostream>
#include "../Player/ListPlayerVec.hpp"
#include "../Player/PlayerVec.hpp"
#include "../Game/GameVec.hpp"

class ReverseDirection : public ListPlayerVec, public GameVec{
    public:
        /* ctor cctor dtor */
        ReverseDirection();
        ~ReverseDirection();

};


#endif