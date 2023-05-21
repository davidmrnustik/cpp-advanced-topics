//
// Created by David Mrnustik on 11/4/22.
//
#include <limits>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

//const u_int64_t max_num = numeric_limits<unsigned long>::max();
const u_int64_t max_num = 1000000000000000000;

map<uint64_t, string> numbers = {
    {0, "zero"},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"},
    {20, "twenty"},
    {30, "thirty"},
    { 40, "forty"},
    { 50, "fifty"},
    { 60, "sixty"},
    { 70, "seventy"},
    { 80, "eighty"},
    { 90, "ninety"},
    { 100, "hundred"},
    { 1000, "thousand"},
    { 1000000, "million"},
    { 1000000000, "billion"},
    { 1000000000000, "trillion"},
    { 1000000000000000000, "quadrillion"}
};
const vector<string> bigNums = { "thousand", "million", "billion", "trillion", "quadrillion" };
//enum class numbers : uint64_t {
//
//};

class numword {
    ostringstream _os;
    void getNumbers(u_int64_t nm);
public:
    numword();
    ~numword();
    char* words(u_int64_t n);
};

void numword::getNumbers(u_int64_t n) {
    if (n > 0 && n < 10) { // jednotky
        _os << numbers[n];
        return;
    }
    if (n > 10 && n < 100) { // desitky
        _os << numbers[(n/10)*10] << "-";
        getNumbers(n%10);
    }
    if (n >= 100 && n < 1000) { // hundreds
        _os << numbers[n/100] << " " << numbers[100] << " ";
        getNumbers(n%100);
    }
    if (n > 1000) { // thousands
        vector<uint64_t> arrNum;
        auto power = [](int idx, int i, uint64_t n, auto&& power) -> uint64_t {
            if (idx / i == 3) return n; return power(idx, i++, n * 1000, power);
        };
        log n).length(); i++) {
            if (i%3 == 0) {
                uint64_t nn = power(i, 1, 1000, power);
                arrNum.emplace_back(nn);
            }
        }
        for(uint64_t i: arrNum)
            cout << "i: " << i << endl;
//        _os << numbers[n/1000] << " " << numbers[1000] << " ";
//        getNumbers(n%1000);
    }

//    if (n / 10000 != 0) { // thousands
//        _os << numbers[n/1000] << " " << numbers[1000] << " ";
//        getNumbers(n%1000);
//    }
}

char* numword::words(u_int64_t n) {
    _os = {};
//    if (n >= max_num || n < 0) {
//        _os << "error";®
//    } else if (n <= 20) {
//        _os << numbers[n];
//    } else {
//        getNumbers(n);
//    }
    getNumbers(n);

    char *str = new char[_os.str().size() + 1];
    std::strcpy(str, _os.str().c_str());

    return str;
}

numword::numword() {};
numword::~numword() {
    printf("destructor nw");
}

int main() {
//    printf("%llu", max_num);
    numword nw;
    uint64_t n;
    n = 0;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 3;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 47;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 73;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 139;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 685;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 1492;
//    n = 1 492;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 10012;
//    n = 10 012;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 100073;
//    n = 100 073;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 1000000;
//    n = 1 000 000;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 1000000001;
//    n = 1 000 000 001;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 123000000000;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 474142398123;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 1474142398007;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 999000000000000;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 999999999999999999;
    printf("n is %llu, %s\n", n, nw.words(n));
    n = 1000000000000000000;
    printf("n is %llu, %s\n", n, nw.words(n));

    return 0;
}
