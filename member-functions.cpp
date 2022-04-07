//
// Created by David Mrnustik on 7/4/22.
//

#include <cstdio>

class A {
    int _value = 0;
public:
    void setv ( const int a ) { _value = a; }
    // any method that is called on const-qualified object must const safe
    // const is a part of function signature
    int getv () const;
    int getv ();
};

int A::getv() const {
    puts("const getv");
    return _value;
}

int A::getv() {
    puts("mutable getv");
    return _value;
}

int main() {
    A a;
    a.setv(42);
    printf("a is %d\n", a.getv());

    const A b = a;
    printf("b is %d\n", b.getv());

    return 0;
}