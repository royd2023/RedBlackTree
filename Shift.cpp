#include "rbtree.h"

// also know as transplant
// z is old node and x is new node
// Shift z to x
void Tree::Shift(Node* z, Node* x) {
    if (z->parent == NIL) {
        root = x;
    }
    else if(z == z->parent->left) {
        z->parent->left = x;
    }
    else {
        z->parent->right = x;
    }
    x->parent = z->parent;
}