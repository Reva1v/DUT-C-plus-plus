#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void task1()
{
    srand(time(nullptr));

    int const M = 4, N = 3;
    int arr[M][N];

    for (auto& i : arr)
    {
        int evenNum = 0;
        for (int j = 0; j < N; j++)
        {
            i[j] = rand() % 100;
            if (i[j] % 2 == 0)
            {
                evenNum++;
            }
            cout << i[j] << "\t";
        }
        cout << "Quantity even numbers: " << evenNum << endl;
    }
}

void task2()
{
    srand(time(nullptr));

    constexpr int M = 6, N = 4;
    int arr[M][N];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < N; i++)
    {
        int evenNum = 0;
        for (int j = 0; j < M; j++)
        {
            if (arr[j][i] % 2 == 0)
            {
                evenNum++;
            }
        }
        cout << "QEN:" << evenNum << "\t";
    }
}

void task3()
{
    srand(time(nullptr));

    int const M = 5, N = 7;
    int arr[M][N];

    for (int i = 0; i < M; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 100;
            rowSum += arr[i][j];
            cout << arr[i][j] << "\t";
        }
        cout << "Sum by row: " << rowSum << endl;
    }
}

void task4()
{
    srand(time(nullptr));

    int const M = 4, N = 6;
    int arr[M][N];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < N; i++)
    {
        int columnSum = 0;
        for (int j = 0; j < M; j++)
        {
            columnSum += arr[j][i];
        }
        cout << "SBC:" << columnSum << "\t";
    }
}

void task5()
{
    srand(time(nullptr));

    int const M = 3, N = 4;
    int arr[M][N];
    int maxNum = 0;
    int maxNumIndexByI, maxNumIndexByJ;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << "\t";

            // maxNum = max(arr[i][j], maxNum);

            if (arr[i][j] > maxNum)
            {
                maxNum = arr[i][j];
                maxNumIndexByI = i;
                maxNumIndexByJ = j;
            }
        }
        cout << endl;
    }
    cout << "\n" << "Max num: " << maxNum << "\t" << "Max num index: " << maxNumIndexByI << " " << maxNumIndexByJ <<
        endl;
}

void task6()
{
    srand(time(nullptr));

    int const M = 3, N = 4;
    int arr[M][N];
    int minNum = 0;
    int minNumIndexByI, minNumIndexByJ;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << "\t";

            // minNum = min(arr[i][j], minNum);

            if (i == 0 && j == 0)
            {
                minNum = arr[i][j];
            }
            else if (arr[i][j] < minNum)
            {
                minNum = arr[i][j];
                minNumIndexByI = i;
                minNumIndexByJ = j;
            }
        }
        cout << endl;
    }
    cout << "\n" << "Min num: " << minNum << "\t" << "Min num index: " << minNumIndexByI << " " << minNumIndexByJ <<
        endl;
}

void task15()
{
    srand(time(nullptr));

    int const M = 3, N = 3;
    int arr[M][N];

    int sumMainDiagonal = 0;
    int sumSecondaryDiagonal = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 20;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    for(int i = 0; i < M; i++) {
        sumMainDiagonal += arr[i][i];
        sumSecondaryDiagonal += arr[i][M - i - 1];
    }

     cout << "\n" << "Sum main diagonal: " << sumMainDiagonal << "\t" << "Sum secondary diagonal: " << sumSecondaryDiagonal << endl;
}

int main()
{
    // task1();
    // task2();
    // task3();
    // task4();
    // task5();
    // task6();
    // task15();
}
