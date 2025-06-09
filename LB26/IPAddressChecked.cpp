#include "IPAddressChecked.h"
#include <sstream>
#include <iostream>

using namespace std;

bool IPAddressChecked::isValidIP(const string& ip) {
    istringstream iss(ip);
    string part;
    int count = 0;

    while (getline(iss, part, '.')) {
        if (part.empty() || part.size() > 3) return false;
        for (char c : part) {
            if (!isdigit(c)) return false;
        }
        int num = stoi(part);
        if (num < 0 || num > 255) return false;
        count++;
    }
    return count == 4;
}

IPAddressChecked::IPAddressChecked(const string& addr)
    : IPAddress(addr), isCorrect(isValidIP(addr)) {}

IPAddressChecked::IPAddressChecked(const IPAddressChecked& other)
    : IPAddress(other), isCorrect(other.isCorrect) {}

void IPAddressChecked::print() const {
    IPAddress::print();
    cout << " - " << (isCorrect ? "Correct" : "Not Correct");
}
