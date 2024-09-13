#include <iostream>

using namespace std;

int firstTaskFunction(const int threeDigitNumber)
{
    const int lastNum = threeDigitNumber % 10;
    const int midNum = threeDigitNumber / 10 % 10;
    const int firstNum = threeDigitNumber / 100;

    int sum = 0;
    if (firstNum > 3) sum += firstNum;
    if (midNum > 3) sum += midNum;
    if (lastNum > 3) sum += lastNum;
    return sum;
}

void secondTaskFunction(const int busNumber)
{
    switch (busNumber)
    {
    case 1:
        cout << "Bus number 1 has 10 stops." << endl;
        break;
    case 2:
        cout << "Bus number 2 has 15 stops." << endl;
        break;
    case 3:
        cout << "Bus number 3 has 20 stops." << endl;
        break;
    case 4:
        cout << "Bus number 4 has 12 stops." << endl;
        break;
    default:
        cout << "Unknown bus number." << endl;
        break;
    }
}

void firstTask()
{
    int num;
    cout << "Enter the three digit number: ";
    cin >> num;
    cout << "Result: " << firstTaskFunction(num) << endl;
}

void secondTask()
{
    int busNumber;
    cout << "Here all bus numbers: 1, 2, 3, 4" << "\n" << "Enter the bus number: ";
    cin >> busNumber;
    secondTaskFunction(busNumber);
}

int main()
{
    // firstTask();
    // secondTask();
}
