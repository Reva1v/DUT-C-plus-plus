#include <algorithm>
#include <iostream>

using namespace std;

int task1()
{
    int arr[] = {5, 4, 1, 2, 3, 6, 9, 10, 7, 8, 12, 11};

    const int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    for (const auto i : arr)
        cout << i << " ";
    return 0;
}

void task2()
{
    int arr[] = {5, 4, 1, -2, 3, -5, -6, 10, 7, -13, 12, 11};

    int newArr[size(arr)];

    for (int i = 0; i < size(arr); i++)
    {
        if (arr[i] > 0)
        {
            newArr[i] = arr[i];
        }
        else
        {
            newArr[i] = 0;
        }
    }

    for (const auto i : newArr)
    {
        cout << i << " ";
    }
}


int main()
{
    // task1();
    // task2();
}
