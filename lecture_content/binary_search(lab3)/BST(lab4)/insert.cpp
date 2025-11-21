#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 插入节点
void insert(Node*& root, int data) {
    if (root == nullptr) {
        root = new Node(data);
        return;
    }
    if (data < root->val) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

// 中序遍历
void inorderTraversal(Node* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->val << " "; //处理根节点
    inorderTraversal(node->right);
}

int main() {
    Node* root = nullptr;

    cout << "Inserting elements: 50, 30, 70, 20, 40, 60, 80" << endl;
    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal (sorted): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}