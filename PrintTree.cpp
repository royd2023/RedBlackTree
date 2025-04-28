#include "rbtree.h"
#include <iostream>
#include <queue>
using namespace std;

Node* NIL = nullptr;

void Tree::PrintTree(Node* node) {
    if (node == NIL) {
        cout << "()"; // Empty tree or NIL node
        return;
    }

    // Print the current node's key and color
    cout << "(" << node->key << " " << (node->color == RED ? "R" : "B");

    // Print the left and right subtrees
    PrintTree(node->left);
    PrintTree(node->right);

    cout << ")"; // Close the current node's representation
}