#include "Table.hpp"

template <class V>
Table<V>::Table() {
    this->cards = CardList<V>();
    this->deck = CardList<V>();
    this->round = 0;
    this->reward = 64;
}

template <class V>
Table<V>::Table(CardList<V> deck, int round) {
    this->cards = CardList<V>();
    this->deck = deck;
    this->round = round;
    this->reward = 64;
}

template <class V>
Table<V>::Table(string name) {
    this->cards = CardList<V>();
    this->deck = CardList<V>(name);
    this->round = 0;
    this->reward = 64;
}

template <class V>
Table<V>::Table(const Table& table) {
    this->cards = table.cards;
    this->deck = table.deck;
    this->round = table.round;
    this->reward = table.reward;
}

template <class V>
Table<V>::~Table() {
    // this->cards.clear();
    // this->deck.clear();
}

/* Getter */
template <class V>
CardList<V> Table<V>::getCards() const {
    return this->cards;
}

template <class V>
int Table<V>::getTotalCard() const {
    return this->cards.getTotalCard();
}

template <class V>
V Table<V>::getCard(int index) const {
    return this->cards.getCard(index);
}

template <class V>
int Table<V>::getRound() const {
    return this->round;
}

template <class V>
long long int Table<V>::getValue() const {
    return this->reward;
}
template <class V>
CardList<V> Table<V>::getDeck() const{
    return this->deck;
}

/* Setter */
template <class V>
void Table<V>::setDeck(CardList<V> deck) {
    this->deck = deck;
}

template <class V>
void Table<V>::setCards(CardList<V> cards) {
    this->cards = cards;
}

template <class V>
int Table<V>::setRound(int round) {
    this->round = round;
    return this->round;
}

template <class V>
long long int Table<V>::setReward(long long int reward) {
    this->reward = reward;
    return this->reward;
}

/* Method */
template <class V>
void Table<V>::print() {
    std::cout << "      Round: " << this->round << std::endl;
    std::cout << "      Reward: " << this->reward << std::endl;
    std::cout << "      Cards: " << std::endl;
    this->cards.print();
    
}

template <class V>
void Table<V>::addCard(V card) {
    this->cards.addCard(card);
}

template <class V>
void Table<V>::addRound() {
    this->round++;
}

template <class V>
void Table<V>::nextRound() {
    this->deck.shuffle();
    this->cards.addCard(this->deck.getCard(0));
    this->deck.removeCard(0);
    this->round++;
}

template <class V>
void Table<V>::removeCard(V card) {
    this->cards.removeCard(card);
}

template <class V>
void Table<V>::removeCard(int index) {
    this->cards.removeCard(index);
}

template <class V>
void Table<V>::removeDeckFirst() {
    this->deck.removeCard(0);
}

template <class V>
void Table<V>::removeCards() {
    for (int i = 0; i < getTotalCard(); i++) {
        this->cards.removeCard(i);
    }
}

template <class V>
void Table<V>::shuffle() {
    this->deck.shuffle();
}

/* Operator */
template <class V>
bool Table<V>::operator==(const Table& table) const {
    return (this->cards == table.cards) && (this->deck == table.deck) && (this->round == table.round) && (this->reward == table.reward);
}

template <class V>
bool Table<V>::operator!=(const Table& table) const {
    return !(*this == table);
}

template <class V>
Table<V>& Table<V>::operator=(const Table& table) {
    this->cards = table.cards;
    this->deck = table.deck;
    this->round = table.round;
    this->reward = table.reward;
    return *this;
}

template <class V>
Table<V>& Table<V>::operator<<(const V& card) {
    this->cards.addCard(card);
    return *this;
}

template <class V>
Table<V>& Table<V>::operator>>(V& card) {
    card = this->cards.getCard(0);
    this->cards.removeCard(0);
    return *this;
}

template class Table<Card>;