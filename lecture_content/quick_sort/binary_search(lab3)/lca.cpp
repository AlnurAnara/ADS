//print the lca address of node 
#include <iostream>
using namespace std;


struct Node {
    int val;
    Node* left;
    Node* right;

   Node(int val) {
        this->val =val;
        left = right = NULL;
    }
};


Node* FindLCA(Node* root, Node* p, Node* q) {
    if (root == NULL) {
        return NULL;
    }

    if (p->val > root->val && q->val > root->val) {
        return FindLCA(root->right, p, q);
    }

    else if (p->val < root->val && q->val < root->val) {
    }

    else {
        return root;
    }
}


