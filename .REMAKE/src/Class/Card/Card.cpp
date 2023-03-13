#include "Card.hpp"

Card::Card() {
    colors = create_color_map(0);
    color = 0;
    number = make_pair(0, "0");
}

Card::Card(int color, int number) {
    colors = create_color_map(0);
    this->color = color;
    this->number = make_pair(number, to_string(number));
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
    return "Invalid color";
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
    this->color = color;
}

void Card::setNumber(int number) {
    this->number = make_pair(number, to_string(number));
}

void Card::setColorString(string color) {
    this->color = colors[color];
}

void Card::setNumberString(string number) {
    this->number = make_pair(stoi(number), number);
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