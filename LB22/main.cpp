#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

Fraction::Fraction(const int numerator, const int denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("denominator cannot be zero");
    }
    if ((numerator < 0 and denominator < 0) or denominator < 0)
    {
        this->numerator = -numerator;
        this->denominator = -denominator;
    }
    else
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
}

string Fraction::toString() const
{
    string answer;
    if (numerator >= denominator)
    {
        answer += to_string(numerator / denominator) + " ";
    }
    if (numerator % denominator != 0)
    {
        answer += to_string(numerator % denominator) + "/" + to_string(denominator);
    }
    return answer;
}

double Fraction::toDouble() const
{
    return static_cast<double>(numerator) / denominator;
}


int main()
{
    while (true)
    {
        cout << "Enter a fraction or \"q\" to quit: " << endl;
        string input;
        getline(cin, input);

        if (input == "q")
        {
            break;
        }

        const int divider_index = input.find('/');
        const int num = stoi(input.substr(0, divider_index));
        const int den = stoi(input.substr(divider_index + 1));
        if (den == 0)
        {
            cout << "denominator is zero" << endl;
            return 1;
        }

        const Fraction fraction(num, den);
        cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    }
    return 0;
}
