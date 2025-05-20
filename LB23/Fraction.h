
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

using namespace std;


class Fraction {
public:
    Fraction(int num, int den);
    string toString() const;
    double toDouble() const;

    Fraction plus(const Fraction& that) const;
    Fraction minus(const Fraction& that) const;
    Fraction times(const Fraction& that) const;
    Fraction by(const Fraction& that) const;

private:
    int numerator;
    int denominator;

    void reduce();
    static int gcd(int a, int b);
};

#endif //FRACTION_H
