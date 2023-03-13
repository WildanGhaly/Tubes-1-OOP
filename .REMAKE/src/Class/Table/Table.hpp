#include "../Card/Card.hpp"

template <class T>
class Table {
    public:
        /* ctor cctor dtor */
        Table();
        Table(int);
        Table(string);

        Table(const Table&);
        ~Table();

        /* Getter */
        int getTotalCard() const;
        T getCard(int) const;
        vector<T> getCards() const;

        /* Method */
        void addCard(T);
        void removeCard(T);
        void removeCard(int);
        void shuffle();
        void sortByNumber();
        void sortByNumberDesc();
        void sortByColor();
        void print() const;

        /* Operator */
        bool operator==(const Table&) const;
        bool operator!=(const Table&) const;
        const T& operator[](int) const;
        Table& operator=(const Table&);
        Table& operator<<(const T&);
        Table& operator>>(T&);

    private:
        vector<T> cards;
};