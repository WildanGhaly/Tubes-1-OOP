#include "Game.hpp"

/* Default Constructor */
Game::Game() : players(), deck(){
}

/* Constructor with total player */
Game::Game(int totalPlayer) : players(totalPlayer), deck(){
}

/* Copy Constructor */
Game::Game(const Game& g) {
    this->players = g.players;
    this->deck = g.deck;
}

/* Destructor */
Game::~Game() {
}

/* Getter untuk players */
ListPlayer Game::getPlayers() const {
    return this->players;
}

/* Getter untuk deck */
CardDeck Game::getDeck() const {
    return this->deck;
}

/* Getter untuk total card */
int Game::getTotalCard() const {
    return this->deck.getTotalCard();
}

/* Setter untuk players */
void Game::setPlayers(ListPlayer players) {
    this->players = players;
}

/* Setter untuk deck */
void Game::setDeck(CardDeck deck) {
    this->deck = deck;
}

/* Method untuk print */
void Game::print() const {
    std::cout << "Players: " << std::endl;
    this->players.print();
    std::cout << "Deck: " << std::endl;
    this->deck.print();
}

/* Method untuk start */
void Game::start() {
    this->deck.shuffle();
    for (int i = 0; i < this->players.getTotalPlayer(); i++) {
        this->players.getPlayer(i).addCard(this->deck.getCard(0));
        this->deck.removeCard(0);
    }
    this->players.getPlayer(0).setIsTurn(true);
}

/* Method untuk start dengan jumlah kartu */
void Game::start(int totalCard) {
    this->deck.shuffle();
    this->players.addCard(this->deck,totalCard);
}


