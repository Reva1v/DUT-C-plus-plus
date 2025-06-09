//
// Created by Reva1v on 09/06/2025.
//

#ifndef IPADDRESS_H
#define IPADDRESS_H

#pragma once
#include <string>

class IPAddress
{
protected:
    std::string address;

public:
    IPAddress(const std::string& addr);
    IPAddress(const IPAddress& other);

    virtual void print() const;
    virtual ~IPAddress();
};


#endif //IPADDRESS_H
