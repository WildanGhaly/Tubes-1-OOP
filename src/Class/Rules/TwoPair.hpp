#include "../Game/GameVec.cpp"

class TwoPair {
    static int totalTwoPair;
    const int maxTwoPair = 100; // unknown yet
    public:
        TwoPair();
        TwoPair(int);
        TwoPair(GameVec, int);
        TwoPair(const TwoPair& tp);
        ~TwoPair();

        /* Getter */
        int getID() const;
        int getScore() const;
        std::vector<Card> getCards() const;
        Card getCard(int) const;
        const float getMaxTwoPair() const;

        /* Setter */
        void setID(int);
        void setScore(int);
        
        /* Method */
        void print() const;
        void print(int) const;
        void print(int, int) const;
        void addCard(Card);
        void removeCard(Card);
        void removeCard(int);
        void addScore(int);
        void computeScore();

        /* Operator */
        bool operator==(const TwoPair&) const;
        bool operator!=(const TwoPair&) const;
        TwoPair& operator=(const TwoPair&);
    
    private:
        int ID;
        float score;
        std::vector<Card> cards;
};