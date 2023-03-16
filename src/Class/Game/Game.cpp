#include "Game.hpp"

template <class W>
Game<W>::Game() : PlayerList(), Table<W>(){
}

template <class W>
Game<W>::Game(int totalPlayer) : PlayerList(totalPlayer), Table<W>() {
}

template <class W>
Game<W>::Game(int totalPlayer, string name) : PlayerList(totalPlayer), Table<W>(name) {
}

template <class W>
Game<W>::Game(const Game& game) {
    this->deck = game.deck;
    this->cards = game.cards;
    this->players = game.players;
    this->round = game.round;
    this->reward = game.reward;
}

template <class W>
Game<W>::~Game() {
    // this->deck.clear();
    // this->table.clear();
    // this->players.clear();
}

/* Setter */
template <class W>
void Game<W>::setDeck(CardList<W> deck) {
    this->deck = deck;
}

template <class W>
void Game<W>::setTable(CardList<W> table) {
    this->cards = table;
}

template <class W>
void Game<W>::setPlayers(vector<Player> players) {
    this->players = players;
}

template <class W>
void Game<W>::setPlayer(int index, Player player) {
    this->players[index] = player;
}

template <class W>
void Game<W>::setRound(int round) {
    this->round = round;
}

/* Method */
template <class W>
void Game<W>::print() {
    PlayerList::print();
    Table<W>::print();
}

template <class W>
void Game<W>::start() {
    this->deck.shuffle();
    for (int i = 0; i < this->getTotalPlayer(); i++) {
        for (int j = 0; j < 2; j++) {
            this->players[i].addHand(this->deck.getCard(0));
            this->deck.removeCard(0); // error
        }
    }
}

template <class W>
void Game<W>::start(int totalCardPerPlayer) {
    this->deck.shuffle();
    for (int i = 0; i < this->getTotalPlayer(); i++) {
        for (int j = 0; j < totalCardPerPlayer; j++) {
            this->players[i].addHand(this->deck.getCard(0));
            this->deck.removeCard(0);
        }
    }
}

template <class W>
void Game<W>::nextRound() {
    this->Table<W>::nextRound();
}

template class Game<Card>;