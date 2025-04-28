#include <iostream>
#include <cstdlib>
#include "rbtree.h"

using namespace std;


/* Tests the Red-Black Tree implementation
 by inserting, deleting, and searching for nodes.

 In this code, a RB tree is created, nodes are inserted,
 deleted, and searched for. The tree structure is printed
 after each operation to show the changes in the tree.
 Small disclaimer, the tree isn't printed after each insertion
 but only after the deletion of nodes.

 The minimum and maximum nodes are also printed
 to demonstrate the functionality of the tree.
 The program also checks if the nodes are found or not
 after deletion. 
 */

int main() {
    Tree tree;

    Node* newNode = new Node(10);
    tree.RBTreeInsert(newNode);

    Node* newNode2 = new Node(5);
    tree.RBTreeInsert(newNode2);

    Node* newNode3 = new Node(20);
    tree.RBTreeInsert(newNode3);
    
    Node* newNode4 = new Node(15);
    tree.RBTreeInsert(newNode4);

    Node* newNode5 = new Node(25);
    tree.RBTreeInsert(newNode5);

    Node* newNode6 = new Node(12);
    tree.RBTreeInsert(newNode6);

    Node* newNode7 = new Node(13);
    tree.RBTreeInsert(newNode7);

    // Printing the tree structure
    cout << "Initial Tree Structure:" << endl;
    tree.PrintTree(tree.root);
    cout << endl;
    cout << "Minimum node: " << tree.Minimum(tree.root)->key << endl;
    cout << "Maximum node: " << tree.Maximum(tree.root)->key << endl;
    cout << "Searching for 20: " << (tree.Search(tree.root, 20) ? "Found" : "Not Found") << endl;

    cout << endl;

    // Deleting node with key 20
    tree.Delete(newNode3); // Delete node with key 20
    cout << endl;
    cout << "Tree Structure After Deleting 20:" << endl;
    tree.PrintTree(tree.root);
    cout << endl;
    cout << "Minimum node: " << tree.Minimum(tree.root)->key << endl;
    cout << "Maximum node: " << tree.Maximum(tree.root)->key << endl;
    cout << "Searching for 20: " << (tree.Search(tree.root, 20) ? "Found" : "Not Found") << endl;

    cout << endl;

    // Deleting node with key 25
    tree.Delete(newNode5); // Delete node with key 25
    cout << "Tree Structure After Deleting 25:" << endl;
    tree.PrintTree(tree.root);
    cout << endl;
    cout << "Minimum node: " << tree.Minimum(tree.root)->key << endl;
    cout << "Maximum node: " << tree.Maximum(tree.root)->key << endl;
    cout << "Searching for 25: " << (tree.Search(tree.root, 25) ? "Found" : "Not Found") << endl;

    cout << endl;

    // Deleting node with key 10
    tree.Delete(newNode); // Delete node with key 10
    cout << "Tree Structure After Deleting 10:" << endl;
    tree.PrintTree(tree.root);
    cout << endl;
    cout << "Minimum node: " << tree.Minimum(tree.root)->key << endl;
    cout << "Maximum node: " << tree.Maximum(tree.root)->key << endl;
    cout << "Searching for 10: " << (tree.Search(tree.root, 25) ? "Found" : "Not Found") << endl;

    cout << endl;

    // Inserting a new node with key 11
    Node* newNode8 = new Node(11);
    tree.RBTreeInsert(newNode8);
    cout << "Tree Structure After Inserting 11:" << endl;
    tree.PrintTree(tree.root);
    cout << endl;
    cout << "Searching for 11: " << (tree.Search(tree.root, 11) ? "Found" : "Not Found") << endl;

    cout << endl;
    // Inorder traversal of the tree
    cout << "Inorder Traversal of the Tree:" << endl;
    tree.InorderTraverse(tree.root);
    cout << endl;

    // Deleting all nodes
    cout << endl;
    tree.Delete(newNode8);
    tree.Delete(newNode2);
    tree.Delete(newNode4);
    tree.Delete(newNode6);
    tree.Delete(newNode7);
    cout << "Tree Structure After Deleting All Nodes:" << endl;
    tree.PrintTree(tree.root);
    cout << endl;
    cout << "Minimum node: " << (tree.Minimum(tree.root) != tree.NIL ? to_string(tree.Minimum(tree.root)->key) : "NIL") << endl;
    cout << "Maximum node: " << (tree.Maximum(tree.root) != tree.NIL ? to_string(tree.Maximum(tree.root)->key) : "NIL") << endl;
    return 0;
}


