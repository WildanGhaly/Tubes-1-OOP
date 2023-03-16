#include "Card.hpp"


Card::Card() {
    colors = create_color_map(0);
    color = 0;
    number = make_pair(0, "0");
}

Card::Card(int color, int number) {
    if (color>=0 && color<=3){
        colors = create_color_map(0);
        this->color = color;
    } else {
        throw CardColorException();
    }
    if(number >= 1 && number <=13){
        this->number = make_pair(number, to_string(number));
    } else {
        throw CardNumberException();
    }
}

Card::Card(string color, int number) {
    colors = create_color_map(0);
    this->color = colors[color];
    this->number = make_pair(number, to_string(number));
    // Exception handling for invalid color
}

Card::Card(const Card& card) {
    colors = create_color_map(0);
    this->color = card.color;
    this->number = card.number;
}

Card::~Card() {
    // Nothing to do
}

int Card::getColor() const {
    return this->color;
}

int Card::getNumber() const {
    return this->number.first;
}

string Card::getColorString() const {
    for (auto it = colors.begin(); it != colors.end(); it++) {
        if (it->second == this->color) {
            return it->first;
        }
    }
    throw CardColorException();
}

string Card::getNumberString() const {
    return this->number.second;
}

map<string, int> Card::getColorMap() const {
    return this->colors;
}

pair<int, string> Card::getNumberPair() const {
    return this->number;
}

float Card::getValue() const {
    return this->number.first * 0.1 + this->color * 0.03;
}

void Card::setColor(int color) {
    if(color >=0 && color <=3){
        this->color = color;
    } else {
        throw CardColorException();
    }
}

void Card::setNumber(int number) {
    if(number>=1 && number <=13){
        this->number = make_pair(number, to_string(number));
    } else {
        throw CardNumberException();
    }
}

void Card::setColorString(string color) {
    if(isColorValid(color)){
        this->color = colors[color];
    } else {
        throw CardColorException();
    }
}

void Card::setNumberString(string number) {
    if(isNumberValid(number)){
        this->number = make_pair(stoi(number), number);
    } else {
        throw CardNumberException();
    }
}

void Card::setColorMap(map<string, int> colors) {
    this->colors = colors;
}

void Card::setNumberPair(pair<int, string> number) {
    this->number = number;
}

void Card::print() {
    cout << this->getColorString() << " " << this->getNumberString() << endl;
}

vector<string> Card::setToPrint(vector<string> cards){
    if(this->color==0){
        cards[0].append(" \033[32m _____\033[0m  ");
        cards[1].append(" \033[32m| GRN |\033[0m ");
        cards[2].append(" \033[32m| ");
        if(this->number.first<10){
            cards[2].append(" ");
        }
        cards[2].append(to_string(this->number.first));
        cards[2].append("  |\033[0m ");
        cards[3].append(" \033[32m|_____|\033[0m ");
    } else if(this->color==1){
        cards[0].append(" \033[34m _____\033[0m  ");
        cards[1].append(" \033[34m| BLU |\033[0m ");
        cards[2].append(" \033[34m| "); 
        if(this->number.first<10){
            cards[2].append(" ");
        }
        cards[2].append(to_string(this->number.first));
        cards[2].append("  |\033[0m ");
        cards[3].append(" \033[34m|_____|\033[0m ");
    } else if(this->color==2){
        cards[0].append(" \033[33m _____\033[0m  ");
        cards[1].append(" \033[33m| YLW |\033[0m ");
        cards[2].append(" \033[33m| "); 
        if(this->number.first<10){
            cards[2].append(" ");
        }
        cards[2].append(to_string(this->number.first));
        cards[2].append("  |\033[0m ");
        cards[3].append(" \033[33m|_____|\033[0m ");
    } else if(this->color==3){
        cards[0].append(" \033[31m _____\033[0m  ");
        cards[1].append(" \033[31m| RED |\033[0m ");
        cards[2].append(" \033[31m| ");
        if(this->number.first<10){
            cards[2].append(" ");
        }
        cards[2].append(to_string(this->number.first));
        cards[2].append("  |\033[0m ");
        cards[3].append(" \033[31m|_____|\033[0m ");
    }
    return cards;
}

bool Card::isColorValid(string color){
    for (int i =0; i<color.size(); i++) {
        color[i] = toupper(color[i]);
    }
    return (color=="GREEN" || color=="BLUE" || color=="RED" || color=="YELLOW");
}
bool Card::isNumberValid(string number){
    int num=stoi(number);
    return num>=1 && num <=13;
}

bool Card::operator==(const Card& card) const {
    return this->color == card.color && this->number.first == card.number.first;
}

bool Card::operator!=(const Card& card) const {
    return !(*this == card);
}

bool Card::operator>(const Card& card) const {
    return this->getValue() > card.getValue();
}

bool Card::operator<(const Card& card) const {
    return this->getValue() < card.getValue();
}

bool Card::operator>=(const Card& card) const {
    return this->getValue() >= card.getValue();
}

bool Card::operator<=(const Card& card) const {
    return this->getValue() <= card.getValue();
}

Card& Card::operator=(const Card& card) {
    this->color = card.color;
    this->number = card.number;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << card.getColorString() << " " << card.getNumberString();
    return os;
}