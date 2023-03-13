#ifndef _QUADRUPLE_HPP
#define _QUADRUPLE_HPP

#include <iostream>
#include "../Player/Score.hpp"

class Quadruple : public Score  {
    public :
        Quadruple();
        bool isQuadruple() const;
        void setQuadruple(bool);
    
    private :
        bool usingQuadruple;
};


#endif