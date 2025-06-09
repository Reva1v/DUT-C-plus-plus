
#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

class Tree {
public:
    virtual void draw() {
        cout << "Base tree drawing\n";
    }
    virtual ~Tree() {}
};

#endif //TREE_H