#include <iostream>
#include <cmath>

using namespace std;

void task6()
{
    bool answer;
    int value;
    while (true)
    {
        cout << "Enter a value: ";
        cin >> value;

        answer = (value >= 0 && value < 10 || value * 2 < 20 && value - 2 > -2 || value - 1 > 1 && value / 2 < 10 ||
            value == 111);

        cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;

        if (value == 999)
        {
            break;
        }
    }
}

void task7FunctionRemoveAfterDot(float num, int numToRemoveAfterDot)
{
    cout << fixed;
    cout.precision(numToRemoveAfterDot);
    cout << num;
}

void task7()
{
    float num;
    int numToRemoveAfterDot;

    cout << "Enter the number with floating-point:" << endl;
    cin >> num;
    cout << "Enter the number of digits you want to leave after the dot:" << endl;
    cin >> numToRemoveAfterDot;
    task7FunctionRemoveAfterDot(num, numToRemoveAfterDot);
}

bool task8FunctionAreAlmostEqual(const double num1, const double num2, const double epsilon = 0.000001)
{
    return fabs(num1 - num2) < epsilon;
}

void task8()
{
    int a, b;

    cout << "Enter two integers: " << endl;
    cin >> a >> b;

    double result1 = 1.0 / a;
    double result2 = 1.0 / b;

    if (task8FunctionAreAlmostEqual(result1, result2))
    {
        cout << "Results are equal (by 0.000001 epsilon)" << endl;
    }
    else
    {
        cout << "Results are not equal (by 0.000001 epsilon)" << endl;
    }
}

int task9FunctionCheckNumbers(int num)
{
    int correctNum;
    if (num > 255)
    {
        do
        {
            cout << "Number can not be more than 255";
            cout << "\n" << "Enter suitable value numbers:" << endl;
            cin >> correctNum;

            if (correctNum <= 255)
            {
                num = correctNum;
                break;
            }
            else
            {
                cout << "The number you entered is still more than 255. Try again." << endl;
            }
        }
        while (true);
    }
    return num;
}

void task9()
{
    int a, b, c, d;

    cout << "Enter four numbers";

    cout << "\n" << "First: " << endl;
    cin >> a;
    a = task9FunctionCheckNumbers(a);

    cout << "Second: " << endl;
    cin >> b;
    b = task9FunctionCheckNumbers(b);
    cout << "Third: " << endl;
    cin >> c;
    c = task9FunctionCheckNumbers(c);

    cout << "Fourth: " << endl;
    cin >> d;
    d = task9FunctionCheckNumbers(d);

    cout << a << "." << b << "." << c << "." << d;
}

int main()
{
    // task6();
    // task7();
    task8();
    // task9();
}
