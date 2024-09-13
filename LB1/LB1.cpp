#include <iostream>
#include <cmath>
using namespace std;

double firstMathFunction(const double a, const double b) {
    double jopa = pow(pow(a, 2) / pow(b, 3), 2.0 / 3.0);
    double bracket1 = 0.807 * (1 - pow(sin((a - b) * (M_PI / 4)), 2));
    double bracket2 = 0.312 * (1 + pow(cos((b + a) * (M_PI / 4)), 2));
    double exponent = exp(bracket1 / bracket2);

    return jopa * exponent;
}

double secondMathFunction(double a, double b) {
    double jopa = (a-b)/(b+a);
    double exponent = exp(log(cos(a-b)*(M_PI/8))/0.137);
    return cbrt(jopa*exponent);
}

int main() {
    double a;
    double b;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter a number: ";
    cin >> b;
    // std::cout << "Result: " << firstMathFunction(a, b);
    cout << "Result: " << secondMathFunction(a, b);
}
