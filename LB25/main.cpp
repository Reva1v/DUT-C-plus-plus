#include <iostream>

#include "Tree.h"

#include "Tree1.h"
#include "Tree2.h"
#include "Tree3.h"

using namespace std;


int main() {
    Tree* trees[3];

    Tree1 t1;
    Tree2 t2;
    Tree3 t3;

    trees[0] = &t1;
    trees[1] = &t2;
    trees[2] = &t3;

    for (int i = 0; i < 3; i++) {
        trees[i]->draw();
    }

    return 0;
}
