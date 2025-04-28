# include "rbtree.h"

/*if the parent x of z is RED and its uncle is BLACK 
and z is the right child and its parent x is a left child,
in other words z is towards the uncle:
    1. rotate left x
    2. rotate right w
    3. z becomes black
    4. w and x becomes red
*/
Node* Tree::RBInsertFixupB(Node* z) {
    if (z == root && z->parent->color == BLACK) {
        return z;
    }
    Node* x = z->parent;    // parent of z
    Node* w = x->parent;    // grandparent of z

    // if z is the right child of x and x is the left child of w
    if (z == x->right && x == w->left) {
        LeftRotate(x);
        z = x;
        RBInsertFixupC(z);
    // if z is the left child of x and x is the right child of w
    } else if (z == x->left && x == w->right) {
        RightRotate(x);
        z = x;
        RBInsertFixupC(z);
    }
    return z;
}