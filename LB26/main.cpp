#include "IPAddress.h"
#include "IPAddressChecked.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a1, a2, a3;
    getline(cin, a1);
    getline(cin, a2);
    getline(cin, a3);

    const IPAddress ip(a1);
    const IPAddressChecked ip1(a2);
    const IPAddressChecked ip2(a3);

    ip.print();  cout << endl;
    ip1.print(); cout << endl;
    ip2.print(); cout << endl;

    return 0;
}