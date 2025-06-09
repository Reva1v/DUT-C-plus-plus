#include <iostream>
using namespace std;

//Lab 7.1.1
void task1()
{
    int a = 8, b = 0, c = 0;
    cout << "[Task 1] Enter value: " << endl;
    cin >> b;

    try
    {
        if (b == 0)
            throw "Your input is not valid, you can't divide by zero.";
        c = a / b;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    cout << "Result: " << c << endl;
}

//Lab 7.2.1
void task2()
{
    auto internaldiv = [](const float arg1, const float arg2) -> float
    {
        return arg1 / arg2;
    };

    float r, a, b;
    cout << "[Task 2.2] Enter two numbers: " << endl;
    while (cin >> a >> b)
    {
        try
        {
            if (b == 0.0 || a == 0.0)
                throw "Are you kidding me?\n" "Your input is not valid. You can't divide by zero.";
            r = internaldiv(a, b);
            cout << "Result: " << r << endl;
        }
        catch (const char* msg)
        {
            cout << msg << endl;
        }
        break;
    }
}

// Lab 7.1.3
void task3()
{
    int a = 0, b = 0, c = 0;
    cout << "[Task 3] Enter two integers (b then a): " << endl;
    cin >> a;
    cin >> b;

    try
    {
        if (b == 0 || a == 0)
            throw ("You can't divide by zero.");
        c = a / b;
        cout << c << endl;
    }
    catch (const char* mgs)
    {
        cout << mgs << endl;
        cout << "Your input is not valid" << endl;
    }
}

int main()
{
    int choice;
    cout << "Choose a task to run:\n";
    cout << "1. Task 1\n";
    cout << "2. Task 2\n";
    cout << "3. Task 3\n";
    cout << "Enter your choice: " << endl;
    cin >> choice;

    switch (choice)
    {
    case 1: task1();
        break;
    case 2: task2();
        break;
    case 3: task3();
        break;
    default: cout << "Invalid choice!" << endl;
    }

    return 0;
}
