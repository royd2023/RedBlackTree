# include "rbtree.h"
#  include <iostream>
using namespace std;

void Tree::DeleteFixup(Node* x) {
 
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node* w = x->parent->right; // Sibling of x
            // case 1: w is red
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                LeftRotate(x->parent);
                w = x->parent->right;
            }
            // case 2: w is black and both children are black
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent; 
            } else {
                // case 3: w is black, w.left is red, w.right is black
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    RightRotate(w);
                    w = x->parent->right;
                }
                // case 4: w is black, w.right is red
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                LeftRotate(x->parent);
                x = root; // Exit loop
            }
        } 
        else {
            Node* w = x->parent->left; // Sibling of x
    
            // case 1: w is red
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                RightRotate(x->parent);
                w = x->parent->left;
            }
            // case 2: w is black and both children are black
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } 
            else {
                //cout << "using this else" << endl;
                // case 3: w is black, w.right is red, w.left is black
                if (w->left->color == BLACK) {
                    //cout << "using this if" << endl;
                    w->right->color = BLACK;
                    w->color = RED;
                    LeftRotate(w);
                    w = x->parent->left;
                }
                // case 4: w is black, w.left is red
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK; 
                RightRotate(x->parent);
                
                x = root; // Exit loop
            }
        }
    }
    x->color = BLACK; // Ensure x is black
}
