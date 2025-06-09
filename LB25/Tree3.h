//
// Created by Reva1v on 09/06/2025.
//

#ifndef TREE3_H
#define TREE3_H

#include "Tree.h"
#include <iostream>
using namespace std;

class Tree3 final : public Tree
{
public:
    void draw() override
    {
        cout << "Drawing 3:\n";
        cout << " /\\\n";
        cout << "/++\\\n";
    }
};

#endif //TREE3_H