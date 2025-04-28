#ifndef RBTREE_H
#define RBTREE_H

enum Color { RED, BLACK };


struct Node {
    int key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
    Node(int k) : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};
extern Node* NIL;
class Tree {
    public:
        Node* root;
        Node* NIL;

        Tree() {
            NIL = new Node(0);
            NIL->color = BLACK;
            NIL->left = NIL->right = NIL->parent = NIL;
            root = NIL;
        }
        
        void RBTreeInsert(Node* z);
        Node* RBLocateParent(Node* z);
        Node* Sibling(Node* x);
        Node* RBInsertFixupA(Node* z);
        Node* RBInsertFixupB(Node* z);
        Node* RBInsertFixupC(Node* z);
        void PrintTree(Node* node);
        void LeftRotate(Node* x);
        void RightRotate(Node* x);
        void Shift(Node* z, Node* x); // Shift z to x aka Transplant function
        void Delete(Node* z);
        void DeleteFixup(Node* x);
        Node* Minimum(Node* x);
        Node* Maximum(Node* x);
        bool Search(Node* x, int key);
        void InorderTraverse(Node* node);
};

#endif