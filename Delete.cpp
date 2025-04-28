#include "rbtree.h"
#include <iostream>

using namespace std;
// z is the node to be deleted
void Tree::Delete(Node* z) {
    Node* v = z;
    Color color = v->color; // keep track of the color of the node to be deleted
    Node* x; 

    if (z->left == NIL) {
        x = z->right;
        Shift(z, x);
    } 
    else if (z->right == NIL) {
        x = z->left;
        Shift(z, x);
    }
    // if z has 2 children
    else {
        //cout << "node deleting has 2 children" << endl;
        v = Minimum(z->right); // find the minimum node in the right subtree
        color = v->color;
        x = v->right;
        if (v->parent == z) {
            x->parent = v;
        }
        else {
            Shift(v, v->right);
            v->right = z->right;
            v->right->parent = v;
        }
        Shift(z, v);
        v->left = z->left;
        v->left->parent = v;
        v->color = z->color;
    }
    if (color == BLACK) {
        DeleteFixup(x);
    } 
}