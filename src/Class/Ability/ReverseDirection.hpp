#ifndef _REVERSEDIR_HPP_
#define _REVERSEDIR_HPP_


class ReverseDirection{
    public:
        /* ctor cctor dtor */
        ReverseDirection();
        ReverseDirection(const ReverseDirection&);
        ~ReverseDirection();

        /* Getter */
        // int get() const;

        /* Setter */
        // void set(int);

        /* Method */
        // void print() const;
        // void addPlayer(Player);
        // void removePlayer(Player);
        // void removePlayer(int);
        // void addCard(Card);
        // void removeCard(Card);
        // void removeCard(int);
        // void shuffle();
        // void start();
        // void start(int);
        
        /* Operator */
        bool operator==(const ReverseDirection&) const;
        bool operator!=(const ReverseDirection&) const;
        ReverseDirection& operator=(const ReverseDirection&);

    private:
        // int data;
};


#endif