#include "CardList.hpp"

template <class T>
CardList<T>::CardList() {
    this->cards = vector<Card>();
}

template <class T>
CardList<T>::CardList(int totalCard) {
    this->cards = vector<Card>(totalCard);
}

template <class T>
CardList<T>::CardList(string name) {
    this->cards = vector<Card>();
    for(int i=0; i< name.size();i++){
        name[i]=toupper(name[i]);
    }
    if (name == "POKER") {
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= 13; j++) {
                this->cards.push_back(Card(i, j));
            }
        }
    } else {
        throw InvalidInputException();
    }
}

template <class T>
CardList<T>::CardList(const CardList<T> cardList, const CardList<T> cardList2) {
    this->cards = vector<Card>();
    for (int i = 0; i < cardList.getTotalCard(); i++) {
        this->cards.push_back(cardList.getCard(i));
    }
    for (int i = 0; i < cardList2.getTotalCard(); i++) {
        this->cards.push_back(cardList2.getCard(i));
    }
}

template <class T>
CardList<T>::CardList(const CardList& cardList) {
    this->cards = cardList.cards;
}

template <class T>
CardList<T>::~CardList() {
    // Nothing to do
}

template <class T>
int CardList<T>::getTotalCard() const {
    return this->cards.size();
}

template <class T>
T CardList<T>::getCard(int index) const {
    return this->cards[index];
}

template <class T>
vector<T> CardList<T>::getCards() const {
    return this->cards;
}

template <class T>
void CardList<T>::setCard(int index, T card) {
    this->cards[index] = card;
}

template <class T>
void CardList<T>::setCards(vector<T> cards) {
    this->cards = cards;
}

template <class T>
void CardList<T>::setCards(CardList<T> cardList) {
    this->cards = cardList.cards;
}

template <class T>
void CardList<T>::setCardsList(CardList<T> cards1, CardList<T> cards2) {
    this->cards = vector<Card>();
    for (int i = 0; i < cards1.getTotalCard(); i++) {
        this->cards.push_back(cards1.getCard(i));
    }
    for (int i = 0; i < cards2.getTotalCard(); i++) {
        this->cards.push_back(cards2.getCard(i));
    }
}

template <class T>
void CardList<T>::addCard(Card card) {
    this->cards.push_back(card);
}

template <class T>
void CardList<T>::removeCard(Card card) {
    for (int i = 0; i < this->cards.size(); i++) {
        if (this->cards[i] == card) {
            this->cards.erase(this->cards.begin() + i);
            break;
        }
    }
}

template <class T>
void CardList<T>::removeCard(int index) {
    if(index>=0 && index<=this->cards.size()-1){
        this->cards.erase(this->cards.begin() + index);
    } else {
        throw IndexOutOfBoundException();
    }
}

template <class T>
void CardList<T>::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < this->cards.size(); i++) {
        int randomIndex = rand() % this->cards.size();
        Card temp = this->cards[i];
        this->cards[i] = this->cards[randomIndex];
        this->cards[randomIndex] = temp;
    }
}

template <class T>
void CardList<T>::sortByNumber() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getNumber() > this->cards[j].getNumber()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

template <class T>
void CardList<T>::sortByNumberDesc() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getNumber() < this->cards[j].getNumber()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

template <class T>
void CardList<T>::sortByColor() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getColor() > this->cards[j].getColor()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

template <class T>
void CardList<T>::sortByColorDesc() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getColor() < this->cards[j].getColor()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

template <class T>
void CardList<T>::sortByNumberAndColor() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getNumber() > this->cards[j].getNumber()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
            else if (this->cards[i].getNumber() == this->cards[j].getNumber()) {
                if (this->cards[i].getColor() > this->cards[j].getColor()) {
                    Card temp = this->cards[i];
                    this->cards[i] = this->cards[j];
                    this->cards[j] = temp;
                }
            }
        }
    }
}

template <class T>
void CardList<T>::sortByNumberAndColorDesc() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getNumber() < this->cards[j].getNumber()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
            else if (this->cards[i].getNumber() == this->cards[j].getNumber()) {
                if (this->cards[i].getColor() < this->cards[j].getColor()) {
                    Card temp = this->cards[i];
                    this->cards[i] = this->cards[j];
                    this->cards[j] = temp;
                }
            }
        }
    }
}

template <class T>
void CardList<T>::sortByColorAndNumber() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getColor() > this->cards[j].getColor()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
            else if (this->cards[i].getColor() == this->cards[j].getColor()) {
                if (this->cards[i].getNumber() > this->cards[j].getNumber()) {
                    Card temp = this->cards[i];
                    this->cards[i] = this->cards[j];
                    this->cards[j] = temp;
                }
            }
        }
    }
}

template <class T>
void CardList<T>::sortByColorAndNumberDesc() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getColor() < this->cards[j].getColor()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
            else if (this->cards[i].getColor() == this->cards[j].getColor()) {
                if (this->cards[i].getNumber() < this->cards[j].getNumber()) {
                    Card temp = this->cards[i];
                    this->cards[i] = this->cards[j];
                    this->cards[j] = temp;
                }
            }
        }
    }
}

template <class T>
void CardList<T>::print() {
    vector<string> prints(5);
    for (int i = 0; i < this->cards.size(); i++) {
        prints=cards[i].setToPrint(prints);
    }
    for (int i=0; i< 5;i++){
        cout << prints[i] << endl;
    }
}

template <class T>
bool CardList<T>::operator==(const CardList& cardList) const {
    if (this->cards.size() != cardList.cards.size()) {
        return false;
    }
    for (int i = 0; i < this->cards.size(); i++) {
        if (this->cards[i] != cardList.cards[i]) {
            return false;
        }
    }
    return true;
}

template <class T>
bool CardList<T>::operator!=(const CardList& cardList) const {
    return !(*this == cardList);
}

template <class T>
const Card& CardList<T>::operator[](int index) const {
    return this->cards[index];
}

template <class T>
CardList<T>& CardList<T>::operator=(const CardList& cardList) {
    this->cards.clear();
    for (int i = 0; i < cardList.cards.size(); i++) {
        this->cards.push_back(cardList.cards[i]);
    } 
    return *this;
}

template <class T>
CardList<T>& CardList<T>::operator<<(const Card& card) {
    this->cards.push_back(card);
    return *this;
}

template <class T>
CardList<T>& CardList<T>::operator>>(Card& card) {
    card = this->cards.back();
    this->cards.pop_back();
    return *this;
}

template class CardList<Card>;