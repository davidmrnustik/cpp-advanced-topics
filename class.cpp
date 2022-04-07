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
};

void c1::setValue( const int & value) {
    i = value;
}

int c1::getValue() const {
    return i;
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

    return 0;
}