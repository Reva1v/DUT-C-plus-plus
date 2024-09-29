#include <iostream>

using namespace std;

void mathFunction2_6(int c0)
{
    int steps = 0;
    if (c0 <= 0)
    {
        cout << "Number is not unavailable." << endl;
        return;
    }

    while (c0 != 1)
    {
        if (c0 % 2 == 0)
        {
            c0 /= 2;
            cout << c0 << endl;
            steps += 1;
        }
        else if (c0 % 2 == 1)
        {
            c0 = 3 * c0 + 1;
            cout << c0 << endl;
            steps += 1;
        }
    }
    cout << "steps = " << steps;
}

void task2_6()
{
    int c0;
    cout << "Enter the value:" << endl;
    cin >> c0;
    mathFunction2_6(c0);
}

double mathFunction2_7(const long long iterations, double pi4)
{
    for (long long i = 0; i < iterations; ++i)
    {
        if (i % 2 == 0)
        {
            pi4 += 1.0 / static_cast<double>(2 * i + 1);
        }
        else
        {
            pi4 -= 1.0 / static_cast<double>(2 * i + 1);
        }
    }
    return pi4;
}

void task2_7()
{
    constexpr double pi4 = 0.0;
    long iterations;

    cout << "Number of iterations? ";
    cin >> iterations;

    cout.precision(20);
    cout << "Pi = " << (mathFunction2_7(iterations, pi4) * 4.) << endl;
}

// void squarePainter(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0 || i == n - 1)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (j == 0 || j == n - 1)
//                 {
//                     cout << '+';
//                 }
//                 else
//                 {
//                     cout << "-";
//                 }
//             }
//         }
//         else
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (j == 0 || j == n - 1)
//                 {
//                     cout << '|';
//                 }
//                 else
//                 {
//                     cout << " ";
//                 }
//             }
//         }
//         cout << endl;
//     }
// }

// void squarePainter(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         const bool iEdge = i == 0 || i == n - 1;
//         for (int j = 0; j < n; j++)
//         {
//             const bool jEdge = j == 0 || j == n - 1;
//             if (iEdge)
//             {
//                 if (jEdge)
//                 {
//                     cout << '+';
//                 }
//                 else
//                 {
//                     cout << "-";
//                 }
//             }
//             else
//             {
//                 if (jEdge)
//                 {
//                     cout << '|';
//                 }
//                 else
//                 {
//                     cout << " ";
//                 }
//             }
//         }
//         cout << endl;
//     }
// }

void drawHorizontalBorder(int n)
{
    cout << '+';
    for (int j = 1; j < n - 1; ++j)
    {
        cout << '-';
    }
    cout << '+' << endl;
}

void drawVerticalBorder(int n)
{
    cout << '|';
    for (int j = 1; j < n - 1; ++j)
    {
        cout << ' ';
    }
    cout << '|' << endl;
}

void squarePainter(int n)
{
    if (n < 2)
    {
        cout << "Sorry, the side size is too small" << endl;
        return;
    }
    if (n > 99)
    {
        cout << "Sorry, the side size is too big" << endl;
        return;
    }

    drawHorizontalBorder(n);
    for (int i = 1; i < n - 1; ++i)
    {
        drawVerticalBorder(n);
    }
    drawHorizontalBorder(n);
}

void task2_10()
{
    int n;
    cout << "Enter the value:" << endl;
    cin >> n;
    squarePainter(n);
}

int main()
{
    // task2_6();
    // task2_7();
    task2_10();
    return 0;
}
