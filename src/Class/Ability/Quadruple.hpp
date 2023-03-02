#ifndef _QUADRUPLE_HPP
#define _QUADRUPLE_HPP

#include <iostream>
#include "../Player/PlayerVec.hpp"
#include "../Game/GameVec.hpp"

class Quadruple : public PlayerVec, public GameVec  {
    public :
        Quadruple();
        bool isQuadruple() const;
        void setQuadruple(bool);
    
    private :
        bool usingQuadruple;
};


#endif