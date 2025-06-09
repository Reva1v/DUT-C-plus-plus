//
// Created by Reva1v on 09/06/2025.
//

#ifndef TREE1_H
#define TREE1_H

#include "Tree.h"
#include <iostream>
using namespace std;


class Tree1 final : public Tree
{
public:
    void draw() override
    {
        cout << "Drawing 1:\n";
        cout << " /\\\n";
        cout << "//\\\\\n";
    }
};

#endif //TREE1_H

