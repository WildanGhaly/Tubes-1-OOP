#ifndef _QUARTER_HPP
#define _QUARTER_HPP

#include <iostream>
#include "../Player/PlayerVec.hpp"
#include "../Game/GameVec.hpp"

class Quarter : public PlayerVec, public GameVec  {
    public :
        Quarter();
        bool isQuarter() const;
        void setQuarter(bool);
    
    private :
        bool usingQuarter;
};


#endif