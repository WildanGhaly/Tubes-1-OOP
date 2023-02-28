#ifndef _CARD_NUMBER_HPP_
#define _CARD_NUMBER_HPP_

#include <iostream>

class CardNumber {
    public:
        /* ctor cctor dtor */
        CardNumber();
        CardNumber(int);
        CardNumber(const CardNumber&);
        ~CardNumber();

        /* setter */
        void setNumber(int);

        /* getter */
        int getNumber() const;

        /* operator */
        CardNumber &operator=(const CardNumber&);
        bool operator==(const CardNumber&) const;
        bool operator!=(const CardNumber&) const;
        // bool operator<(const CardNumber&) const;
        // bool operator>(const CardNumber&) const;
        // bool operator<=(const CardNumber&) const;
        // bool operator>=(const CardNumber&) const;
        // CardNumber& operator=(const CardNumber&);

        /* method */
        void print() const;
        void input();

    private:
        int number;
};

#endif