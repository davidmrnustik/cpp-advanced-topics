//
// Created by David Mrnustik on 8/4/22.
//

#include <iostream>
using namespace std;

class num {
    int value = 0;
public:
    num( int x = 0 ) : value(x) {}
    int getvalue() const { return value; }
    void setvalue( int x ) { value = x; }
    num & operator ++ ();
    num operator ++ (int);
    num & operator -- ();
    num operator -- (int);
};

// pre-increment
num & num::operator ++ () {
    cout << "pre-increment: ";
    value += 1;
    return *this;
}

// post-increment, distinction between pre- and post- fix is a dummy parameter (int)
// you cannot return a reference to a temporary value in a stack
// it's a bit more expensive operation
num num::operator ++ (int) {
    cout << "post-increment: ";
    num temp = *this;
    value += 1;
    return temp;
}

// pre-decrement
num & num::operator -- () {
    cout << "pre-decrement: ";
    value -= 1;
    return *this;
}

// post-decrement
num num::operator -- (int) {
    cout << "post-decrement: ";
    num temp = *this;
    value -= 1;
    return temp;
}

ostream & operator << (ostream &o, const num &n) {
    return o << (n.getvalue());
}

int main() {
    num n(42);
    cout << "value is " << n << endl;
    cout << "value is " << ++n << endl;
    cout << "value is " << n << endl;

    return 0;
}

