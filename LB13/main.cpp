#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 10;

void fillArray(int arr[SIZE][SIZE], int& evens, int& odds) {
    srand(time(nullptr));
    evens = odds = 0;

    cout << "Array with random numbers:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = rand() % 101;
            cout.width(6);
            cout << arr[i][j];

            if (arr[i][j] % 2 == 0) evens++;
            else odds++;
        }
        cout << endl << endl;
    }
}

void printDiagonals(int arr[SIZE][SIZE]) {
    cout << "First diagonal: ";
    for (int i = 0; i < SIZE; i++) {
        cout.width(4);
        cout << arr[i][i];
    }
    cout << endl;

    cout << "Second diagonal: ";
    for (int i = 0; i < SIZE; i++) {
        cout.width(4);
        cout << arr[i][SIZE - i - 1];
    }
    cout << endl;
}

int main() {
    int arr[SIZE][SIZE];
    int evens, odds;

    fillArray(arr, evens, odds);
    printDiagonals(arr);

    cout << "\nEvens: " << evens << "\nOdds: " << odds << endl;

    return 0;
}