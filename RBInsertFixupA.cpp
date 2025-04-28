# include "rbtree.h"

Node* Tree::RBInsertFixupA(Node* z) {
    Node* y = NIL;
    while (z != root && z->parent->color != BLACK) {
        y = Sibling(z->parent);
        if (y->color == BLACK) {
            return y;
        }
        z->parent->color = BLACK;
        y->color = BLACK;
        z = z->parent->parent;
        z->color = RED;
    }
    return y;
}