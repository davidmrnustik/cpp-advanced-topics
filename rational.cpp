//
// Created by David Mrnustik on 8/4/22.
//

#include <cstdio>
#include <iostream>

using namespace std;

class Rational {
    int _n = 0;
    int _d = 1;
public:
    Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};
    Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {}; // copy constructor
    ~Rational();
    int numerator() const { return _n; }
    int denominator() const { return _d; }
    Rational & operator = ( const Rational & );
    // because they are member functions, they only need one operand
    // left-hand side of operation is the object itself
    // right-hand is the argument / operand
    // they are const-safe, they return separate new object
//    Rational operator + ( const Rational & ) const;
    Rational operator - ( const Rational & ) const;
    Rational operator * ( const Rational & ) const;
    Rational operator / ( const Rational & ) const;
};

Rational & Rational::operator = ( const Rational &rhs ) {
    if (this !=  &rhs) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator - ( const Rational &rhs ) const {
    return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator * ( const Rational &rhs ) const {
    return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator / ( const Rational &rhs ) const {
    return Rational(_n * rhs._d, _d * rhs._n);
}

Rational::~Rational() {
    _n = 0; _d = 0;
}

// for std::cout, non-member function operator
std::ostream & operator << (std::ostream &o, const Rational &r) {
    if (r.denominator() == 1) return o << r.numerator();
    else return o << r.numerator() << '/' << r.denominator();
}

// if you have constructor that allows implicit conversions,
// you should consider non-member overload operators for all of your operators
Rational operator + ( const Rational &lhs, const Rational &rhs ) {
    return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

int main() {
    Rational a = 7; // 7/1
    cout << "a is: " << a << endl;

    Rational b(5, 3); // 5/3
    cout << "b is: " << b << endl;

    Rational c = b; // copy constructor
    cout << "c is: " << c << endl;

    Rational d; // default constructor
    cout << "d is: " << d << endl;

    d = c; // assignment operator
    cout << "d is: " << d << endl;

    Rational &e = d; // reference
    d = e; // assignment to self!
    cout << "e is: " << e << endl;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    // works because right-hand side 14 is taken as Rational
    // with nominator 14, implicit conversion of integer 14 to Rational
    cout << b << " + " << 14 << " = " << b + 14 << endl;

    cout << 14 << " + " << b << " = " << 14 + b << endl;

    return 0;
}

