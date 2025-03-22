#include <iostream>
#include <climits>
using namespace std;

void task1() {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int length = sizeof(vector) / sizeof(vector[0]);
    int min = INT_MAX;
    for (int i = 0; i < length; i++) {
        if (*(vector + i) < min) {
            min = *(vector + i);
        }
    }
    cout << min << endl;
}
void task2() {
    int matrix[10][10] = { };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            *(*(matrix + i) + j) = (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout.width(4);
            cout << *(*(matrix + i) + j);
        }
        cout << endl;
    }
}

int main() {
    // task1();
    // task2();
}