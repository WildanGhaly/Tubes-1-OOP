#include <iostream>
using namespace std;


class A {
    public:
        virtual void print() const {
            cout << "A\n";
        }

        virtual void print2() const = 0;
};

class B : public A {
    public:
        virtual void print() const {
            cout << "B\n";
        }

        virtual void print2() const = 0;
};

class C : public B {
    public:
        virtual void print() const {
            cout << "C\n";
        }

        virtual void print2() const {
            cout << "C\n";
        }
};

class D : public C {
    public:
        void print() const {
            cout << "D\n";
        }

        void print2() const {
            cout << "D\n";
        }
};

int main(){
    A *a = new C();
    a->print2();
    cout << "TEST\n\n";
    a->print();

    return 0;
}