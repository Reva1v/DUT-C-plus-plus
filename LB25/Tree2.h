//
// Created by Reva1v on 09/06/2025.
//

#ifndef TREE2_H
#define TREE2_H

#include "Tree.h"
#include <iostream>
using namespace std;

class Tree2 final : public Tree
{
public:
    void draw() override
    {
        cout << "Drawing 2:\n";
        cout << " /\\\n";
        cout << "/**\\\n";
    }
};

#endif //TREE2_H
