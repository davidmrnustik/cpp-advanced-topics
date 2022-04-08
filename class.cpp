//
// Created by David Mrnustik on 7/4/22.
//
#include <cstdio>

class c1 {
    // with class keyword, members default to private
    int i = 0;
public:
    void setValue( const int &);
    int getValue() const;
    int getValue2() const;
};

void c1::setValue( const int & value) {
    i = value;
}

int c1::getValue() const {
    printf("getValue: this is: %p\n", this);
    return i;
}

int c1::getValue2() const {
    printf("getValue2\n");
    return this->getValue();
}

int main() {
    const int i = 47;
    c1 o1;
    o1.setValue(i);
    printf("value is %d\n", o1.getValue());

    c1 o2 = o1;
    printf("value is %d\n", o2.getValue());

    o1.setValue(72);
    o2 = o1;
    printf("value is %d\n", o2.getValue());
    printf("value is %d\n", o1.getValue());

    printf("address of o1 is %p\n", &o1);
    printf("value is %d\n", o1.getValue2());

    return 0;
}