#include <iostream>
using namespace std;

void increment(int *number) {
    ++*number;
}
void increment(int *number, const int value) {
    *number += value;
}

int main()
{
    int var = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            increment(&var);
        }
        else {
            increment(&var, i);
        }
    }
    cout << var << endl;
}