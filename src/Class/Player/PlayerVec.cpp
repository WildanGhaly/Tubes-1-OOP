#include "PlayerVec.hpp"


int PlayerVec::totalPlayer = 0;

/* Default Constructor */
PlayerVec::PlayerVec() : ID(++totalPlayer) {
    this->cards = std::vector<Card>();
    this->score = 0;
    this -> nickname = new char[100];
    
}

PlayerVec::PlayerVec(int score, char* nickname) : ID(++totalPlayer) {
    this->cards = std::vector<Card>();
    this->score = score;
    this-> nickname = new char[100];
    strcpy(this->nickname, nickname);
}

/* Copy Constructor */
PlayerVec::PlayerVec(const PlayerVec& p) : ID(totalPlayer) {
    this->cards = p.cards;
    this->score = p.score;
    this -> nickname = new char[100];
    strcpy(this->nickname, p.nickname);
}

/* Destructor */
PlayerVec::~PlayerVec() {
    totalPlayer--;
}

/* Getter untuk ID */
int PlayerVec::getID() const {
    return this->ID;
}

/* Getter untuk score */
float PlayerVec::getScore() const {
    return this->score;
}

/* Getter untuk cards */
std::vector<Card> PlayerVec::getCards() const {
    return this->cards;
}

/* Getter untuk cards */
Card PlayerVec::getCard(int index) const {
    return this->cards[index];
}

/* Getter untuk total cards */
int PlayerVec::getTotalCard() const {
    return this->cards.size();
}

char* PlayerVec::getNickname() const {
    return this->nickname;
}

/* Setter untuk ID */
void PlayerVec::setID(int ID) {
    this->ID = ID;
}

/* Setter untuk score */
void PlayerVec::setScore(int score) {
    this->score = score;
}

/* Setter untuk cards */
void PlayerVec::setCards(std::vector<Card> cards) {
    this->cards = cards;
}

void PlayerVec::setNickname(char* nickname){
    strcpy(this->nickname, nickname);  
}

/* Method untuk menambahkan kartu */
void PlayerVec::addCard(Card card) {
    this->cards.push_back(card);
}

/* Method untuk menghapus kartu */
void PlayerVec::removeCard(Card card) {
    for (int i = 0; i < this->getTotalCard(); i++) {
        if (this->getCard(i) == card) {
            this->cards.erase(this->cards.begin() + i);
            break;
        }
    }
}

/* Method untuk menghapus kartu */
void PlayerVec::removeCard(int index) {
    this->cards.erase(this->cards.begin() + index);
}

/* Method untuk menambahkan score */
void PlayerVec::addScore(int score) {
    this->score += score;
}

/* Method untuk mencetak kartu */
void PlayerVec::print() const {
    for (int i = 0; i < this->getTotalCard(); i++) {
        std::cout << "      ";
        this->getCard(i).print();
    }
}


/* Method untuk mencetak kartu */
void PlayerVec::print(int index) const {
    this->getCard(index).print();
}

/* Method untuk mencetak kartu */
void PlayerVec::print(int index1, int index2) const {
    this->getCard(index1).print();
    this->getCard(index2).print();
}

/* Operator */
bool PlayerVec::operator==(const PlayerVec& p) const {
    return this->ID == p.ID;
}

bool PlayerVec::operator!=(const PlayerVec& p) const {
    return this->ID != p.ID;
}

PlayerVec& PlayerVec::operator=(const PlayerVec& p) {
    this->ID = p.ID;
    this->score = p.score;
    this->cards = p.cards;
    strcpy(this->nickname, p.nickname);
    return *this;
}


