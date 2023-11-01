#include "avlTree.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    avlTree tree;
    tree.insert(50, "fifty");
    tree.insert(75, "Seventy-Five");
    cout << "done" << endl;
    tree.getHeight();
    return 0;
}