#include "rbtree.h"

void Tree::RightRotate(Node* x) {
    Node* y = x->left; // y is the left child of x
    x->left = y->right; // Turn y's right subtree into x's left subtree

    if (y->right != NIL) {
        y->right->parent = x; // Update parent of y's right child
    }

    y->parent = x->parent; // Link y's parent to x's parent

    if (x->parent == NIL) {
        root = y; // If x is the root, make y the new root
    } else if (x == x->parent->right) {
        x->parent->right = y; // If x is a right child, update parent's right pointer
    } else {
        x->parent->left = y; // If x is a left child, update parent's left pointer
    }

    y->right = x; // Put x on y's right
    x->parent = y; // Update x's parent to y
}