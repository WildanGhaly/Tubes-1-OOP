#ifndef _CARD_COLOR_HPP_
#define _CARD_COLOR_HPP_

#include <iostream>

#define GREEN 0
#define BLUE 1
#define YELLOW 2
#define RED 3

#define GREEN_STRING "Green"
#define BLUE_STRING "Blue"
#define YELLOW_STRING "Yellow"
#define RED_STRING "Red"

class CardColor {
    public:
        /* ctor cctor dtor */
        CardColor();
        CardColor(int);
        CardColor(const CardColor&);
        ~CardColor();

        /* setter */
        void setColor(int);
        void setColor(std::string);

        /* getter */
        int getColor() const;
        std::string getColorAsString() const;

        /* operator */
        CardColor &operator=(const CardColor&);
        bool operator==(const CardColor&) const;
        bool operator!=(const CardColor&) const;
        // bool operator<(const CardColor&) const;
        // bool operator>(const CardColor&) const;
        // bool operator<=(const CardColor&) const;
        // bool operator>=(const CardColor&) const;
        // CardColor& operator=(const CardColor&);

        /* method */
        void print() const;
        void input();

    private:
        int color;
};

#endif