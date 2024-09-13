#include <iostream>
#include <cmath>

using namespace std;

double firstTaskMathSolution(double x,double a,double b,double c,double Y) {
    if (b < 5) {
        Y = pow((4 - x), a * b);
    } else if (b >= c) {
        Y = 0.25 + b * c;
    }
    return Y;
}

bool secondTaskMathSolution(double x, double y) {
    if (x >= 1 && x <= 3 && y >= 1 && y <= 2) {
        return true;
    } else {
        return false;
    }
}

void firstTask() {
    double x, a, b, c;

    cout << "Enter the numbers x, a, b, c: ";
    cin >> x >> a >> b >> c;

    cout << "Y = " << firstTask << endl;
}

void secondTask() {
    double x, y;

    cout << "Enter the coordinates of the point (x, y): ";
    cin >> x >> y;
    if(secondTaskMathSolution(x, y)) {
        cout << "The point falls within the shaded area" << endl;
    }else cout << "The point does not fall within the shaded area." << endl;
}

int main() {
    // firstTask();
    secondTask();
}
