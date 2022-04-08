//
// Created by David Mrnustik on 8/4/22.
//

#include <cstdio>
using namespace std;

class c1 {
    int _value = 0;
    c1(); // simple way to prevent default constructor from being called
public:
    // explicit - avoids implicit conversion
    explicit c1 (const int & value) : _value(value) {}
    void setvalue( const int &value ) { _value = value; }
    int getvalue() const { return _value; }
};

void func(const c1 & o) {
    printf("value is %d\n", o.getvalue());
}

int main() {
    c1 o = 3; // implicit conversion
    printf("value is %d\n", o.getvalue());
    func('x');

    return 0;
}