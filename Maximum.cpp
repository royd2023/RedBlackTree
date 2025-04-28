# include "rbtree.h"

Node* Tree::Maximum(Node* x) {
    while (x->right != NIL) {
        x = x->right;
    }
    return x;
}