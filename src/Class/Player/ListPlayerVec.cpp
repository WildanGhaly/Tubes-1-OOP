#include "ListPlayerVec.hpp"

int ListPlayerVec::totalListPlayer = 0;

ListPlayerVec::ListPlayerVec() : ID(totalListPlayer++) {
    this->players = vector<PlayerVec>();
}

ListPlayerVec::ListPlayerVec(int totalPlayer) : ID(totalListPlayer++) {
    this->players = vector<PlayerVec>(totalPlayer);
}

ListPlayerVec::ListPlayerVec(const ListPlayerVec& lp) : ID(totalListPlayer++) {
    this->players = lp.players;
}

ListPlayerVec::~ListPlayerVec() {
    totalListPlayer--;
}

int ListPlayerVec::getID() const {
    return this->ID;
}

int ListPlayerVec::getTotalPlayer() const {
    return this->players.size();
}

std::vector<PlayerVec> ListPlayerVec::getPlayers() const {
    return this->players;
}

int ListPlayerVec::getTotalCard() const {
    int totalCard = 0;
    for (int i = 0; i < this->players.size(); i++) {
        totalCard += this->players[i].getTotalCard();
    }
    return totalCard;
}

PlayerVec ListPlayerVec::getPlayer(int index) const {
    return this->players[index];
}

void ListPlayerVec::setPlayers(std::vector<PlayerVec> players) {
    this->players = players;
}

void ListPlayerVec::setPlayer(int index, PlayerVec player) {
    this->players[index] = player;
}

void ListPlayerVec::print() const {
    for (int i = 0; i < this->players.size(); i++) {
        std::cout << "Player " << i << ": \n";
        this->players[i].print();
        std::cout << std::endl;
    }
}

void ListPlayerVec::print(int index) const {
    this->players[index].print();
}

void ListPlayerVec::print(int index, int indexCard) const {
    this->players[index].print(indexCard);
}

void ListPlayerVec::addCard(Card card) {
    for (int i = 0; i < this->players.size(); i++) {
        this->players[i].addCard(card);
    }
}

void ListPlayerVec::addCard(Card card, int index) {
    this->players[index].addCard(card);
}

void ListPlayerVec::addCard(CardDeckVec &deck, int amount) {
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < this->players.size(); j++) {
            this->players[j].addCard(deck.getCard(0));
            deck.removeCard(0);
        }
    }
}

void ListPlayerVec::removeCard(Card card) {
    for (int i = 0; i < this->players.size(); i++) {
        this->players[i].removeCard(card);
    }
}

void ListPlayerVec::removeCard(Card card, int index) {
    this->players[index].removeCard(card);
}

void ListPlayerVec::removeCard(int index) {
    for (int i = 0; i < this->players.size(); i++) {
        this->players[i].removeCard(index);
    }
}

void ListPlayerVec::addScore(int score) {
    for (int i = 0; i < this->players.size(); i++) {
        this->players[i].addScore(score);
    }
}

void ListPlayerVec::addScore(int score, int index) {
    this->players[index].addScore(score);
}

bool ListPlayerVec::operator==(const ListPlayerVec& lp) const {
    return this->players == lp.players;
}

bool ListPlayerVec::operator!=(const ListPlayerVec& lp) const {
    return this->players != lp.players;
}

ListPlayerVec& ListPlayerVec::operator=(const ListPlayerVec& lp) {
    this->players = lp.players;
    return *this;
}

