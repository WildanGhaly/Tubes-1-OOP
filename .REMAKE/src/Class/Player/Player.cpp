#include "Player.hpp"

Player::Player() {
    this->name = "Player";
    this->score = 0;
    this->hand = CardList<Card>();
}

Player::Player(string name) {
    this->name = name;
    this->score = 0;
    this->hand = CardList<Card>();
}

Player::Player(const Player& player) {
    this->name = player.name;
    this->score = player.score;
    this->hand = player.hand;
}

Player::~Player() {
    // Nothing to do
}

string Player::getName() const {
    return this->name;
}

long long int Player::getValue() const {
    return this->score;
}

int Player::getHandSize() const {
    return this->hand.getTotalCard();
}

CardList<Card> Player::getHand() const {
    return this->hand;
}

Card Player::getHand(int index) const {
    return this->hand.getCard(index);
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setScore(long long int score) {
    this->score = score;
}

void Player::setHand(CardList<Card> hand) {
    this->hand = hand;
}

void Player::addHand(Card card) {
    this->hand.addCard(card);
}

void Player::addScore(long long int score) {
    this->score += score;
}

void Player::removeHand(Card card) {
    this->hand.removeCard(card);
}

void Player::removeHand(int index) {
    this->hand.removeCard(index);
}

void Player::printHand() {
    vector<string> prints(5);
    for (int i = 0; i < getHandSize(); i++) {
        prints=getHand(i).setToPrint(prints);
    }
    for (int i=0; i< 5;i++){
        cout << prints[i] << endl;
    }
}

void Player::printCapsa() const {
    cout << left;
    for (int i = 0; i < 3; i++) {
        cout << setw(8) << this->hand.getCard(i).getColorString() << setw(10) << this->hand.getCard(i).getNumberString();
    }
    cout << endl;
    for (int i = 3; i < 8; i++) {
        cout << setw(8) << this->hand.getCard(i).getColorString() << setw(10) << this->hand.getCard(i).getNumberString();
    }
    cout << endl;
    for (int i = 8; i < 13; i++) {
        cout << setw(8) << this->hand.getCard(i).getColorString() << setw(10) << this->hand.getCard(i).getNumberString();
    }
    cout << endl;
}

void Player::swapCardPosition(int index1, int index2) {
    Card temp = this->hand.getCard(index1);
    this->hand.setCard(index1, this->hand.getCard(index2));
    this->hand.setCard(index2, temp);
}

bool Player::operator==(const Player& player) const {
    return this->name == player.name;
}

bool Player::operator!=(const Player& player) const {
    return this->name != player.name;
}

bool Player::operator<(const Player& player) const {
    return this->name < player.name;
}

bool Player::operator>(const Player& player) const {
    return this->name > player.name;
}

bool Player::operator<=(const Player& player) const {
    return this->name <= player.name;
}

bool Player::operator>=(const Player& player) const {
    return this->name >= player.name;
}

Player& Player::operator=(const Player& player) {
    this->name = player.name;
    this->score = player.score;
    this->hand = player.hand;
    return *this;
}

Player& Player::operator<<(const Card& card) {
    this->hand.addCard(card);
    return *this;
}

Player& Player::operator>>(Card& card) {
    card = this->hand.getCard(0);
    this->hand.removeCard(0);
    return *this;
}

