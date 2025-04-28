#include "rbtree.h"

bool Tree::Search(Node* x, int key) {
    bool found = false;
    while (x != NIL && key != x->key) {
        if ( key < x->key) {
            x = x->left;
        } 
        else {
            x = x->right;
        }
    }
    if (x != NIL) {
        found = true;
    }
    return found;
}