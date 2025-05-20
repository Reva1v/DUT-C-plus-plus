
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

using namespace std;


class Fraction{
public:
    Fraction(int numerator, int denominator);
    string toString() const;
    double toDouble() const;
private:
    int numerator;
    int denominator;
};

#endif //FRACTION_H
