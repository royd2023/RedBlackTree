#include "rbtree.h"

void Tree::RBTreeInsert(Node* z) {
    z->left = NIL;
    z->right = NIL;
    
    Node* y = RBLocateParent(z);
    z->parent = y;
    if (y == NIL) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    z->color = RED;

    if (z->parent->color == RED 
        && Sibling(z->parent)->color == BLACK 
        && z == z->parent->right) {
            RBInsertFixupB(z);
    } 
    else if (z->parent->color == RED
        && Sibling(z->parent)->color == BLACK
        && z == z->parent->left) {
        RBInsertFixupC(z);
    }
    else {
        RBInsertFixupA(z);
    }
    root->color = BLACK; 
}
    
    
    
    