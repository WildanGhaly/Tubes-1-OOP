#include "CardList.hpp"

/* Static ID counter */
int CardDeck::totalDeck = 0;

/* Default Constructor */
CardDeck::CardDeck() : ID(totalDeck++) {
    this->totalCard = 52;
    this->cards = new Card[this->totalCard];
    for (int i = 0; i < this->totalCard; i++) {
        this->cards[i] = Card(i % 13 + 1, i / 13);
    }
}

/* Constructor with total card */
CardDeck::CardDeck(int totalCard) : ID(totalDeck++) {
    this->totalCard = totalCard;
    this->cards = new Card[this->totalCard];
    for (int i = 0; i < this->totalCard; i++) {
        this->cards[i].input();
    }
}

/* Copy Constructor */
CardDeck::CardDeck(const CardDeck& cd) : ID(totalDeck++) {
    this->totalCard = cd.totalCard;
    delete[] this->cards;
    this->cards = new Card[this->totalCard];
    for (int i = 0; i < this->totalCard; i++) {
        this->cards[i] = cd.cards[i];
    }
}

/* Destructor */
CardDeck::~CardDeck() {
    delete[] this->cards;
}

int CardDeck::getTotalCard() const {
    return this->totalCard;
}

int CardDeck::getID() const {
    return this->ID;
}

Card CardDeck::getCard(int index) const {
    return this->cards[index];
}

/* Add card to deck */
void CardDeck::addCard(Card c) {
    Card* temp = new Card[this->totalCard + 1];
    for (int i = 0; i < this->totalCard; i++) {
        temp[i] = this->cards[i];
    }
    temp[this->totalCard] = c;
    delete[] this->cards;
    this->cards = temp;
    this->totalCard++;
}

/* Remove card from deck */
void CardDeck::removeCard(Card c) {
    int index = -1;
    for (int i = 0; i < this->totalCard; i++) {
        if (this->cards[i].getID() == c.getID()) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        Card* temp = new Card[this->totalCard - 1];
        for (int i = 0; i < index; i++) {
            temp[i] = this->cards[i];
        }
        for (int i = index; i < this->totalCard - 1; i++) {
            temp[i] = this->cards[i + 1];
        }
        delete[] this->cards;
        this->cards = temp;
        this->totalCard--;
    }
}

void CardDeck::removeCard(int index) {
    if (index >= 0 && index < this->totalCard) {
        Card* temp = new Card[this->totalCard - 1];
        for (int i = 0; i < index; i++) {
            temp[i] = this->cards[i];
        }
        for (int i = index; i < this->totalCard - 1; i++) {
            temp[i] = this->cards[i + 1];
        }
        delete[] this->cards;
        this->cards = temp;
        this->totalCard--;
    }
}

/* Shuffle the deck */
void CardDeck::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < this->totalCard; i++) {
        int index = rand() % this->totalCard;
        Card temp = this->cards[i];
        this->cards[i] = this->cards[index];
        this->cards[index] = temp;
    }
}

/* Sort the deck by Number*/
void CardDeck::sortByNumber() {
    for (int i = 0; i < this->totalCard; i++) {
        for (int j = i + 1; j < this->totalCard; j++) {
            if (this->cards[i].getNumber() > this->cards[j].getNumber()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

/* Sort the deck by Color */
void CardDeck::sortByColor() {
    for (int i = 0; i < this->totalCard; i++) {
        for (int j = i + 1; j < this->totalCard; j++) {
            if (this->cards[i].getColor() > this->cards[j].getColor()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

/* Sort the deck by ID */
void CardDeck::sortByID() {
    for (int i = 0; i < this->totalCard; i++) {
        for (int j = i + 1; j < this->totalCard; j++) {
            if (this->cards[i].getID() > this->cards[j].getID()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

/* Print the deck */
void CardDeck::print() const {
    for (int i = 0; i < this->totalCard; i++) {
        this->cards[i].print();
    }
}

/* Operator == */
bool CardDeck::operator==(const CardDeck& cd) const {
    if (this->totalCard != cd.totalCard) {
        return false;
    }
    for (int i = 0; i < this->totalCard; i++) {
        if (this->cards[i] != cd.cards[i]) {
            return false;
        }
    }
    return true;
}

/* Operator != */
bool CardDeck::operator!=(const CardDeck& cd) const {
    return !(*this == cd);
}

/* Operator = */
CardDeck& CardDeck::operator=(const CardDeck& cd) {
    if (this != &cd) {
        this->totalCard = cd.totalCard;
        delete[] this->cards;
        this->cards = new Card[this->totalCard];
        for (int i = 0; i < this->totalCard; i++) {
            this->cards[i] = cd.cards[i];
        }
    }
    return *this;
}

/* Operator [] */
Card& CardDeck::operator[](int index) const {
    return this->cards[index];
}
