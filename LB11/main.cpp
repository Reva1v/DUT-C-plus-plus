#include <iostream>
#include <iomanip>

using namespace std;

struct Date
{
    int hours;
    int minutes;
};

Date addMinutes(Date currentTime, int extraMinutes)
{
    currentTime.minutes += extraMinutes;

    currentTime.hours += currentTime.minutes / 60;
    currentTime.minutes %= 60;

    currentTime.hours %= 24;

    return currentTime;
}

Date getEventDuration(Date startTime, Date endTime)
{
    Date duration;

    if (endTime.minutes < startTime.minutes)
    {
        endTime.minutes += 60;
        endTime.hours -= 1;
    }

    duration.minutes = endTime.minutes - startTime.minutes;

    if (endTime.hours < startTime.hours)
    {
        endTime.hours += 24;
    }

    duration.hours = endTime.hours - startTime.hours;

    return duration;
}

void task1()
{
    Date currentTime;
    int extraMinutes;

    cout << "Enter time (HH MM): " << endl;
    cin >> currentTime.hours;
    cin >> currentTime.minutes;

    cout << "Enter extra minutes (MM): " << endl;
    cin >> extraMinutes;

    Date newTime = addMinutes(currentTime, extraMinutes);

    cout << setw(2) << setfill('0') << newTime.hours << ":"
        << setw(2) << setfill('0') << newTime.minutes << endl;
}

void task2()
{
    Date startTime, endTime;

    cout << "Enter first time (HH MM): " << endl;
    cin >> startTime.hours >> startTime.minutes;

    cout << "Enter second time (HH MM): " << endl;
    cin >> endTime.hours >> endTime.minutes;

    Date duration = getEventDuration(startTime, endTime);

    cout << setw(2) << setfill('0') << duration.hours << ":"
        << setw(2) << setfill('0') << duration.minutes << endl;
}

int main()
{
    // task1();
    task2();
}
