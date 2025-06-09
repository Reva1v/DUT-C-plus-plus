#include <iostream>
#include <string>

#include "Fraction.h"

using namespace std;

int main() {
    int num1, den1, num2, den2;
    char slash;

    cin >> num1 >> slash >> den1;
    cin >> num2 >> slash >> den2;

    const Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    if (f1.isGreaterThan(f2)) {
        cout << f1.toString() << " > " << f2.toString() << endl;
    } else if (f1.isLessThan(f2)) {
        cout << f1.toString() << " < " << f2.toString() << endl;
    } else {
        cout << f1.toString() << " == " << f2.toString() << endl;
    }

    return 0;
}
