# include "rbtree.h"

Node* Tree::RBInsertFixupC(Node* z) {
    if (z == root && z->parent->color == BLACK) {
        return z;
    }
    Node* x = z->parent;    // parent of z
    Node* w = x->parent;    // grandparent of z

    if (z == x->left && x == w->left) {
        RightRotate(w);
        x->color = BLACK;
        w->color = RED;
    
    } else if (z == x->right && x == w->right) {
        LeftRotate(w);
        x->color = BLACK;
        w->color = RED;
    }
    return z;
}