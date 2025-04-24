#include <iostream>
#include <ctime>
using namespace std;

void task1()
{
    srand(time(nullptr));

    int size;
    cout << "Enter the size of the array(min 1, max 20): ";
    cin >> size;

    if (size < 1 | size > 20)
    {
        cout << "Invalid size!" << endl;
        return;
    }

    int positive = 0, negative = 0;

    double* arr = new double[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = (double)rand() / (double)RAND_MAX - 0.5;
        cout.width(20);
        cout << arr[i];
        if (arr[i] < 0)
        {
            negative++;
        }
        else
        {
            positive++;
        }
    }
    cout << endl;

    cout << "Positive: " << positive << ";\nNegative: " << negative << ";" << endl;
    delete[] arr;
}

void task2()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size < 1 or size > 10)
    {
        cout << "Invalid size!" << endl;
        return;
    }

    int odds = 0, evens = 0;

    int** arr = new int*[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];

        for (int j = 0; j < size; j++)
        {
            arr[i][j] = rand() % 101 - 50;
            cout << arr[i][j] << "\t";

            if (arr[i][j] % 2 == 0)
            {
                evens++;
            }
            else
            {
                odds++;
            }
        }
        cout << endl << endl;
    }
    cout << "Main D: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i][i] << "\t";
    }
    cout << endl;

    cout << "Secondary D: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i][size - i - 1] << "\t";
    }
    cout << endl;

    cout << "Evens: " << evens << ";\nOdds: " << odds << "." << endl;

    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

int main()
{
    task1();
    // task2();
}
