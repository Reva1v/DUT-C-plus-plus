#include <iostream>
using namespace std;

bool isLeap(const int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int monthLengthSwitch(const int year, const int month)
{
    switch (month)
    {
    case 1:
        return 31;
    case 2:
        return isLeap(year) ? 29 : 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        return 0;
    }
}

int monthLengthArr(const int year, const int month)
{
    const int lengthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year))
    {
        return 29;
    }
    return lengthArr[month - 1];
}

void task1()
{
    for (int yr = 1995; yr < 2017; yr++)
        cout << yr << "->" << isLeap(yr) << endl;
}

void task2()
{
    for (int yr = 2000; yr < 2002; yr++)
    {
        for (int mo = 1; mo <= 12; mo++)
            cout << monthLengthSwitch(yr, mo) << " ";
        cout << endl;
    }
}

int main()
{
    // task1();
    task2();
}
