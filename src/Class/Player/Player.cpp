#include "Player.hpp"

/* Static ID counter */
int Player::totalPlayer = 0;

/* Default Constructor */
Player::Player() : ID(++totalPlayer) {
    this->cards = new Card[0];
    this->cardCount = 0;
    this->point = 0;
    this->ability = 0;
    this->isTurn = false;
    // this->name = "Player ";
}

/* Constructor with name */
Player::Player(std::string name) : ID(++totalPlayer) {
    this->cards = new Card[0];
    this->cardCount = 0;
    this->point = 0;
    this->ability = 0;
    this->isTurn = false;
    // this->name = name;
}

/* Copy Constructor */
Player::Player(const Player& p) : ID(totalPlayer){
    this->cardCount = p.cardCount;
    if (this->getCardCount() > 0) {
        delete[] this->cards;
    }
    this->cards = new Card[this->cardCount];
    for (int i = 0; i < this->cardCount; i++) {
        this->cards[i] = p.cards[i];
    }
    this->point = p.point;
    this->ability = p.ability;
    this->isTurn = p.isTurn;
    // this->name = p.name;
}

/* Destructor */
Player::~Player(){
    totalPlayer--;
    delete[] this->cards;
}

/* Getter untuk ID */
int Player::getID() const {
    return this->ID;
}

/* Getter untuk point */
int Player::getPoint() const {
    return this->point;
}

/* Getter untuk ability */
int Player::getAbility() const {
    return this->ability;
}

/* Getter untuk isTurn */
int Player::getIsTurn() const {
    return this->isTurn;
}

/* Getter untuk cardCount */
int Player::getCardCount() const {
    return this->cardCount;
}

/* Getter untuk kartu */
Card Player::getCard(int index) const {
    return this->cards[index];
}

/* Getter untuk ID */
// std::string Player::getName() const {
//     return this->name;
// }

/* Setter untuk ID */
void Player::setID(int ID) {
    this->ID = ID;
}

/* Setter untuk point */
void Player::setPoint(int point) {
    this->point = point;
}

/* Setter untuk ability */
void Player::setAbility(int ability) {
    this->ability = ability;
}

/* Setter untuk isTurn */
void Player::setIsTurn(int isTurn) {
    this->isTurn = isTurn;
}

/* Setter untuk name */
// void Player::setName(std::string name) {
//     this->name = name;
// }

/* Menambahkan kartu ke dalam list kartu */
void Player::addCard(Card card) {
    Card* temp = new Card[this->cardCount + 1];
    for (int i = 0; i < this->cardCount; i++) {
        temp[i] = this->cards[i];
    }
    temp[this->cardCount] = card;
    delete[] this->cards;
    this->cards = temp;
    this->cardCount = this->cardCount + 1;
}

/* Menghapus kartu dari list kartu */
void Player::removeCard(Card card) {
    int index = -1;
    for (int i = 0; i < this->cardCount; i++) {
        if (this->cards[i] == card) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        Card* temp = new Card[this->cardCount - 1];
        for (int i = 0; i < index; i++) {
            temp[i] = this->cards[i];
        }
        for (int i = index + 1; i < this->cardCount; i++) {
            temp[i - 1] = this->cards[i];
        }
        delete[] this->cards;
        this->cards = temp;
        this->cardCount--;
    }
}

/* Menghapus kartu dari list kartu */
void Player::removeCard(int index) {
    if (index >= 0 && index < this->cardCount) {
        Card* temp = new Card[this->cardCount - 1];
        for (int i = 0; i < index; i++) {
            temp[i] = this->cards[i];
        }
        for (int i = index + 1; i < this->cardCount; i++) {
            temp[i - 1] = this->cards[i];
        }
        delete[] this->cards;
        this->cards = temp;
        this->cardCount--;
    }
}

/* Operator == */
bool Player::operator==(const Player& p) const {
    if (this->ID == p.ID) {
        return true;
    }
    return false;
}

/* Operator != */
bool Player::operator!=(const Player& p) const {
    if (this->ID != p.ID) {
        return true;
    }
    return false;
}

/* Operator = */
Player& Player::operator=(const Player& p) {
    this->cardCount = p.cardCount;
    delete[] this->cards;
    this->cards = new Card[this->cardCount];
    for (int i = 0; i < this->cardCount; i++) {
        this->cards[i] = p.cards[i];
    }
    this->point = p.point;
    this->ability = p.ability;
    this->isTurn = p.isTurn;
    // this->name = p.name;
    return *this;
}

/* Operator > */
bool Player::operator>(const Player& p) const {
    return (this->point > p.point);
}

/* Operator < */
bool Player::operator<(const Player& p) const {
    return (this->point < p.point);
}

/* Operator >= */
bool Player::operator>=(const Player& p) const {
    return (this->point >= p.point);
}

/* Operator <= */
bool Player::operator<=(const Player& p) const {
    return (this->point <= p.point);
}

/* Print */
void Player::print(){
    std::cout << "Player " << this->ID << std::endl;
    std::cout << "  Ability " << this->ability << std::endl;
    std::cout << "  Point " << this->point << std::endl;
    std::cout << "  Card Count " << this->cardCount << std::endl;
    if (this->cardCount > 0) {
        for (int i = 0; i < this->cardCount; i++) {
            std::cout << "    ";
            this->cards[i].print();
        }
    }
}
