#include <iostream>

using namespace std;

void task3()
{
    srand(time(nullptr));

    cout << "Old array: " << endl;
    int arr[10];
    for (int i = 0; i < size(arr); i++)
    {
        arr[i] = rand() % 100 - 50;
        cout << arr[i] << " ";
    }

    int maxNum = arr[0], minNum = arr[0];

    int positionMax, positionMin;

    for (int i = 0; i < size(arr); ++i)
    {
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
            positionMax = i;
        }
        else if (arr[i] < minNum)
        {
            minNum = arr[i];
            positionMin = i;
        }
    }

    swap(arr[positionMax], arr[positionMin]);

    cout << endl << "New array: " << endl;
    for (int i = 0; i < size(arr); ++i)
    {
        cout << arr[i] << " ";
    }
}

void task4()
{
    srand(time(nullptr));

    int arr[10];
    for (int i = 0; i < size(arr); i++)
    {
        arr[i] = rand() % 100 - 50;
        cout << arr[i] << " ";
    }

    int A;
    int count = 0;

    cout << "\n" << "Enter the value:" << endl;
    cin >> A;

    for (int i = 0; i < size(arr); ++i)
    {
        if (arr[i] > A)
        {
            count++;
        }
    }

    cout << "There are more numbers in the array than A" << endl;
    cout << count;
}

void task5()
{
    srand(time(nullptr));

    int arr[10];
    for (int i = 0; i < size(arr); i++)
    {
        arr[i] = rand() % 100 - 50;
        cout << arr[i] << " ";
    }

    int largest = arr[0], secondLargest = -1;

    for (int i = 1; i < size(arr); ++i)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    for (int i = 0; i < size(arr); ++i)
    {
        if (arr[i] != largest)
        {
            if (secondLargest == -1 || arr[i] > secondLargest)
            {
                secondLargest = arr[i];
            }
        }
    }

    if (secondLargest != -1)
    {
        cout << "\n" << "The second largest element: " << secondLargest << endl;
    }
    else
    {
        cerr << "\n" << "Calculation error." << endl;
    }
}

int findFirstZero(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

void task6()
{
    srand(time(nullptr));

    int arr[10];
    for (int i = 0; i < size(arr); i++)
    {
        arr[i] = rand() % 100 - 50;
        cout << arr[i] << " ";
    }

    int zeroIndex = findFirstZero(arr, size(arr));

    if (zeroIndex != -1)
    {
        cout << "\n" << "The first null element is at index: " << zeroIndex << endl;
    }
    else
    {
        cout << "\n" << "The array does not contain null elements." << endl;
    }
}

int main()
{
    // task3();
    // task4();
    // task5();
    // task6();
}
