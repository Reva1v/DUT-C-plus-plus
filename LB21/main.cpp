#include <iostream>
#include <sstream>

#include "FlightBooking.h"

using namespace std;

FlightBooking::FlightBooking(const int id, const int capacity, const int reserved)
{
    this->id = id;
    this->capacity = capacity;

    int maxReservation = static_cast<int>(capacity * 1.05);
    if (reserved < 0)
        this->reserved = 0;
    else if (reserved > maxReservation)
        this->reserved = maxReservation;
    else
        this->reserved = reserved;
}

void FlightBooking::printStatus() const
{
    double percentage = 0.0;
    if (capacity > 0)
    {
        percentage = (static_cast<double>(reserved) / capacity) * 100;
    }
    cout << "Flight " << id << " : " << reserved << "/" << capacity
        << " (" << static_cast<int>(percentage) << "%) seats reserved" << endl;
}

bool FlightBooking::reserveSeats(const int number_of_seats)
{
    int maxReservation = static_cast<int>(capacity * 1.05);
    if (number_of_seats < 0 || reserved + number_of_seats > maxReservation)
        return false;
    reserved += number_of_seats;
    return true;
}

bool FlightBooking::cancelReservations(const int number_of_seats)
{
    if (number_of_seats < 0 || reserved - number_of_seats < 0)
        return false;
    reserved -= number_of_seats;
    return true;
}

void task1()
{
    while (true)
    {
        int reserved = 0, capacity = 0;
        cout << "Provide flight capacity: " << endl;
        cin >> capacity;


        cout << "Provide number of reserved seats: " << endl;
        cin >> reserved;

        FlightBooking booking(1, capacity, reserved);
        booking.printStatus();

        cout << "Do you want to continue? (y/n): " << endl;
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
        {
            break;
        }
    }
}

void task2()
{
    int reserved = 0, capacity = 0;

    cout << "Provide flight capacity: " << endl;
    cin >> capacity;

    cout << "Provide number of reserved seats: " << endl;
    cin >> reserved;
    cin.ignore();

    FlightBooking booking(1, capacity, reserved);

    string command;
    while (true)
    {
        booking.printStatus();
        cout << "What would you like to do?(actions: add|cancel|q): " << endl;
        getline(cin, command);

        if (command == "q")
            break;

        istringstream iss(command);
        string action;
        int number;
        iss >> action >> number;

        bool result = false;
        if (action == "add")
        {
            result = booking.reserveSeats(number);
        }
        else if (action == "cancel")
        {
            result = booking.cancelReservations(number);
        }
        else
        {
            cout << "Unknown command" << endl;
            continue;
        }

        if (!result)
        {
            cout << "Cannot perform this operation" << endl;
        }
    }
}

void task3()
{
    FlightBooking flights[10];
    string commandLine;

    while (true)
    {
        cout << "What would you like to do?(actions: add|create|delete|cancel|q): " << endl;
        getline(cin, commandLine);

        if (commandLine == "q") break;

        istringstream iss(commandLine);
        string command;
        iss >> command;

        if (command == "create")
        {
            int id, cap;
            iss >> id >> cap;

            bool exists = false;
            int emptyIndex = -1;
            for (int i = 0; i < 10; ++i)
            {
                if (flights[i].getId() == id)
                    exists = true;
                if (flights[i].getId() == 0 && emptyIndex == -1)
                    emptyIndex = i;
            }

            if (exists)
            {
                cout << "Cannot perform this operation: flight " << id << " already exists" << endl;
            }
            else if (emptyIndex == -1)
            {
                cout << "Cannot perform this operation: flight list full" << endl;
            }
            else
            {
                flights[emptyIndex] = FlightBooking(id, cap, 0);
            }
        }
        else if (command == "delete")
        {
            int id;
            iss >> id;
            bool found = false;

            for (int i = 0; i < 10; ++i)
            {
                if (flights[i].getId() == id)
                {
                    flights[i] = FlightBooking();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
        }
        else if (command == "add" || command == "cancel")
        {
            int id, n;
            iss >> id >> n;

            bool found = false;
            for (int i = 0; i < 10; ++i)
            {
                if (flights[i].getId() == id)
                {
                    bool ok = (command == "add") ? flights[i].reserveSeats(n) : flights[i].cancelReservations(n);

                    if (!ok)
                        cout << "Cannot perform this operation" << endl;

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
        }
        else
        {
            cout << "Unknown command" << endl;
        }

        bool any = false;
        for (int i = 0; i < 10; ++i)
        {
            if (flights[i].getId() != 0)
            {
                flights[i].printStatus();
                any = true;
            }
        }

        if (!any)
        {
            cout << "No flights in the system" << endl;
        }
    }
}


int main()
{
    // task1();
    // task2();
    task3();
    return 0;
}
