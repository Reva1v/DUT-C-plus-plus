//
// Created by Reva1v on 09/06/2025.
//

#ifndef IPADDRESSCHECKED_H
#define IPADDRESSCHECKED_H

#pragma once
#include "IPAddress.h"

class IPAddressChecked : public IPAddress {
    bool isCorrect;

    static bool isValidIP(const std::string& ip);

public:
    IPAddressChecked(const std::string& addr);
    IPAddressChecked(const IPAddressChecked& other);

    void print() const override;
};


#endif //IPADDRESSCHECKED_H
