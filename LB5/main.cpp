#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

double task1MathFunction(double x)
{
    double y;
    return y = pow(sin(x), 5) + fabs(5 * x - 1.5);
}

void task1()
{
    double x;
    for (int i = 0; i < 5; ++i)
    {
        cout << "Enter the value of x (" << i + 1 << " of 5): ";
        cin >> x;

        cout << "The value of y for x = " << x << " is: " << task1MathFunction(x) << endl;
    }
}

int task2SumOfPairNumbers(const vector<int>& arr)
{
    int result = 0;
    for (const int i : arr)
    {
        if (i % 2 == 0)
        {
            result += i;
        }
    }
    return result;
}

void task2()
{
    vector<int> arr;

    while (true)
    {
        int x;
        cout << "Enter the values you want to sum: " << endl;
        cout << "If you done, enter \"000\" " << endl;
        cin >> x;
        if (x != 000)
        {
            arr.push_back(x);
        }
        else
        {
            cout << task2SumOfPairNumbers(arr);
            break;
        }
    }
}

double f(const double x) {
    const double x1 = 10 - 5 * x;
    if (x1 < 0) {
        return numeric_limits<double>::quiet_NaN();
    }
    return 6 * pow(x, 3) + sqrt(x1);
}

int task3()
{
    double a, b, h;

    cout << "Enter the values of a, b, and h: ";
    cin >> a >> b >> h;

    if (h <= 0) {
        cout << "Step size must be greater than zero!" << endl;
        return 1;
    }

    cout << "-------------------------" << endl;
    cout << ":   X   :\tY\t:" << endl;
    cout << "-------------------------" << endl;

    for (double x = a; x <= b; x += h) {
        double y = f(x);
        if (isnan(y)) {
            cout << "x = " << x << " is outside the domain of the function." << endl;
            break;
        }
        cout << ": " << setw(5) << x << " : " << setw(15) << y << " :" << endl;
    }

    cout << "-------------------------" << endl;

    return 0;
}


int main()
{
    // task1();
    // task2();
    task3();
}
