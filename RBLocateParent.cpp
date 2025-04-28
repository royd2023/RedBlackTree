# include <iostream>
# include <cstdlib>
#include "rbtree.h"

Node* Tree::RBLocateParent(Node* z) {
    Node* y = NIL;
    Node* x = root;

    while (x != NIL) {
        y=x;
        if (z->key < x->key) {
            x = x->left;
        }else {
            x = x->right;
        }
    }
    return y;
}