#include "rbtree.h"
#include <iostream>

using namespace std;

Node* Tree::Sibling(Node* x) {
    if (x->parent == NIL) {
        cout << "error: Root has no siblings" << endl;
    } 
    Node* p = x->parent;
    if (p->left == x) {
        return p->right;
    } else {
        return p->left;
    }
}