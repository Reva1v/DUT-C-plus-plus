#include <iostream>
#include <string>
#include <sstream>
#include <numeric> // для std::gcd в C++17
#include "Fraction.h"
using namespace std;

Fraction::Fraction(int num, int den)
{
    if (den == 0) throw invalid_argument("Denominator cannot be zero.");

    if (den < 0)
    {
        num = -num;
        den = -den;
    }
    numerator = num;
    denominator = den;
    reduce();
}

void Fraction::reduce()
{
    const int g = gcd(abs(numerator), abs(denominator));
    numerator /= g;
    denominator /= g;
}

int Fraction::gcd(int a, int b)
{
    while (b != 0)
    {
        const int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

string Fraction::toString() const
{
    const int whole = numerator / denominator;
    int rem = abs(numerator % denominator);

    if (rem == 0)
        return to_string(whole);
    else if (whole == 0)
        return to_string(numerator) + "/" + to_string(denominator);
    else
        return to_string(whole) + " " + to_string(rem) + "/" + to_string(denominator);
}

double Fraction::toDouble() const
{
    return static_cast<double>(numerator) / denominator;
}

Fraction Fraction::plus(const Fraction& that) const
{
    const int num = numerator * that.denominator + that.numerator * denominator;
    const int den = denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::minus(const Fraction& that) const
{
    const int num = numerator * that.denominator - that.numerator * denominator;
    const int den = denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::times(const Fraction& that) const
{
    const int num = numerator * that.numerator;
    const int den = denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::by(const Fraction& that) const
{
    if (that.numerator == 0) throw invalid_argument("Division by zero fraction.");
    const int num = numerator * that.denominator;
    const int den = denominator * that.numerator;
    return Fraction(num, den);
}

int main()
{

    while (true)
    {
        int n1, d1, n2, d2;
        char slash;

        cout << "Enter first fraction: " << endl;
        cin >> n1 >> slash >> d1;
        if (cin.fail() || d1 == 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid fraction." << endl;
            continue;
        }
        cout << "Enter second fraction: " << endl;
        cin >> n2 >> slash >> d2;
        if (cin.fail() || d2 == 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid fraction." << endl;
            continue;
        }

        const Fraction f1(n1, d1);
        const Fraction f2(n2, d2);

        cout << f1.toString() << " + " << f2.toString() << " = " << f1.plus(f2).toString() << endl;
        cout << f1.toString() << " - " << f2.toString() << " = " << f1.minus(f2).toString() << endl;
        cout << f1.toString() << " * " << f2.toString() << " = " << f1.times(f2).toString() << endl;
        cout << f1.toString() << " / " << f2.toString() << " = " << f1.by(f2).toString() << endl;

        cout << "Press 'q' to quit or any other key to continue: " << endl;
        char choice;
        cin >> choice;
        if (choice == 'q' || choice == 'Q')
        {
            break;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
