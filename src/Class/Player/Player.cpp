#include "Player.hpp"

Player::Player() {
    this->name = "Player";
    this->score = 0;
    this->hand = CardList<Card>();
    this -> ability = 0;
    this->abilityName = create_player_ability(0);
}

Player::Player(string name) {
    this->name = name;
    this->score = 0;
    this->hand = CardList<Card>();
    this -> ability = 0;
    this->abilityName = create_player_ability(0);
}

Player::Player(const Player& player) {
    this->name = player.name;
    this->score = player.score;
    this->hand = player.hand;
    this -> ability = player.ability;
    this->abilityName = player.abilityName;
    // this->ability_id = player.ability_id;
    // this->usingAbility = player.usingAbility;
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

int Player::getAbility() const {
    return this->ability;
}

string Player::getAbilityName() const {
    for (auto it = abilityName.begin(); it != abilityName.end(); it++) {
        if (it->first == this->ability) {
            return "Abilitymu " + it->second;
        }
    }
    throw NotFoundException();
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

void Player::setAbility(int ability) {
    this->ability = ability;
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
    vector<string> prints(5);
    for (int i = 0; i < 3; i++) {
         prints=getHand(i).setToPrint(prints);
    }
    for (int i=0; i< 5;i++){
        cout << prints[i] << endl;
    }
    cout << endl;
    vector<string> prints1(5);
    for (int i = 3; i < 8; i++) {
        prints1=getHand(i).setToPrint(prints1);
    }
    for (int i=0; i< 5;i++){
        cout << prints1[i] << endl;
    }
    cout << endl;
    vector<string> prints2(5);
    for (int i = 8; i < 13; i++) {
        prints2=getHand(i).setToPrint(prints2);
    }
    for (int i=0; i< 5;i++){
        cout << prints2[i] << endl;
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
    this -> ability = player.ability;
    this->abilityName = player.abilityName;
    // this->ability_id = player.ability_id;
    // this->usingAbility = player.usingAbility;
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

