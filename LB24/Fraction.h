//
// Created by Reva1v on 09/06/2025.
//

#ifndef FRACTION_H
#define FRACTION_H

#endif //FRACTION_H

#include <iostream>
#include <string>
#include <numeric>
#include <stdexcept>
#include <cmath>

using namespace std;

class Fraction {
public:
    Fraction(const int numerator, const int denominator) {
        if (denominator == 0) throw invalid_argument("Denominator cannot be zero.");
        this->numerator = numerator;
        this->denominator = denominator;
        reduce();
    }

    [[nodiscard]] string toString() const {
        if (abs(numerator) >= denominator) {
            const int whole = numerator / denominator;
            const int remainder = abs(numerator % denominator);
            if (remainder == 0) return to_string(whole);
            return to_string(whole) + " " + to_string(remainder) + "/" + to_string(denominator);
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }

    [[nodiscard]] double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

    [[nodiscard]] bool isGreaterThan(const Fraction that) const {
        return this->numerator * that.denominator > that.numerator * this->denominator;
    }

    [[nodiscard]] bool isLessThan(const Fraction that) const
    {
        return this->numerator * that.denominator < that.numerator * this->denominator;
    }

    [[nodiscard]] bool isEqual(const Fraction that) const
    {
        return this->numerator * that.denominator == that.numerator * this->denominator;
    }

private:
    int numerator;
    int denominator;

    void reduce() {
        const int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        // ensure denominator is positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
};
