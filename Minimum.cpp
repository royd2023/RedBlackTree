# include "rbtree.h"

Node* Tree::Minimum(Node* x) {
    while (x->left != NIL) {
        x = x->left;
    }
    return x;
}