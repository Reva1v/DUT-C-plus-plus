#include "IPAddress.h"
#include <iostream>

using namespace std;

IPAddress::IPAddress(const string& addr) : address(addr) {}

IPAddress::IPAddress(const IPAddress& other) : address(other.address) {}

void IPAddress::print() const {
    cout << address;
}

IPAddress::~IPAddress() {}
