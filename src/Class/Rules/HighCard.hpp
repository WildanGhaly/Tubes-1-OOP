#include "../Game/Game.hpp"

/* Class TwoPair */
class HighCard {
    public:
        /* Constructor */
        HighCard();

        /* Destructor */
        ~HighCard() {
        }

        /* Mengembalikan true jika memenuhi syarat */
        bool check(Game game);

        /* Mengembalikan nama */
        std::string getName() const;

        int compute(Game game);
    
    private:
        std::string name;
};