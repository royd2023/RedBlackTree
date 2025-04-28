#include "rbtree.h"
#include <iostream>

using namespace std;

void Tree::InorderTraverse(Node* node) {
    if (node != NIL) {
        InorderTraverse(node->left);       // Visit left child
        cout << node->key << " ";            // Visit current node
        InorderTraverse(node->right);      // Visit right child
    }
}