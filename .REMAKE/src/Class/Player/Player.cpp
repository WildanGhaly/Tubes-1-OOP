#include "Player.hpp"

Player::Player() {
    this->name = "Player";
    this->score = 0;
    this->hand = CardList();
}

Player::Player(string name) {
    this->name = name;
    this->score = 0;
    this->hand = CardList();
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

int Player::getScore() const {
    return this->score;
}

int Player::getHandSize() const {
    return this->hand.getTotalCard();
}

CardList Player::getHand() const {
    return this->hand;
}

Card Player::getHand(int index) const {
    return this->hand.getCard(index);
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setScore(int score) {
    this->score = score;
}

void Player::setHand(CardList hand) {
    this->hand = hand;
}

void Player::addHand(Card card) {
    this->hand.addCard(card);
}

void Player::removeHand(Card card) {
    this->hand.removeCard(card);
}

void Player::removeHand(int index) {
    this->hand.removeCard(index);
}

void Player::printHand() const {
    for (int i = 0; i < this->hand.getTotalCard(); i++) {
        cout << this->hand.getCard(i) << endl;
    }
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

