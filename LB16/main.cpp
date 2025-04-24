#include <iostream>
#include <ctime>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

Date today()
{
    const time_t t = time(nullptr);
    const tm tm = *localtime(&t);
    return Date{
        tm.tm_year + 1900,
        tm.tm_mon + 1,
        tm.tm_mday
    };
}

bool isLeap(const int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int monthLengthArr(const int month, const int year)
{
    const int lengthArr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year))
        return 29;
    return lengthArr[month - 1];
}

int daysFromStartOfYear(const Date date)
{
    int days = date.day;
    for (int i = 1; i < date.month; ++i)
        days += monthLengthArr(i, date.year);
    return days;
}

int daysBetweenDates(const Date birth, const Date current)
{
    int days = 0;

    for (int year = birth.year + 1; year < current.year; ++year)
    {
        days += isLeap(year) ? 366 : 365;
    }

    if (birth.year == current.year)
    {
        days = daysFromStartOfYear(current) - daysFromStartOfYear(birth);
    }
    else
    {
        const int daysInBirthYear = isLeap(birth.year) ? 366 : 365;
        days += daysInBirthYear - daysFromStartOfYear(birth);

        days += daysFromStartOfYear(current);
    }

    return days;
}

int main()
{
    const Date t = today();
    cout << t.year << "-" << t.month << "-" << t.day << endl;

    Date birth{};
    cout << "Enter the birth date: " << endl;
    cout << "Year: ";
    cin >> birth.year;
    cout << endl;
    cout << "Month: ";
    cin >> birth.month;
    cout << endl;
    cout << "Day: ";
    cin >> birth.day;
    cout << endl;

    const int days = daysBetweenDates(birth, t);

    cout << "Number of days from your birthday to today: " << days << endl;
}
