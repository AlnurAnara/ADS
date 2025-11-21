#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    
    // 构造函数
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// --- 2. BST 插入函数 ---
// 使用 Node*& root 进行引用传递，确保能正确修改父节点的指针。
void insert(Node*& root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }
    
    // BST 规则：小于当前节点值，递归插入左子树
    if (val < root->data) {
        insert(root->left, val);
    }
    // 大于或等于当前节点值，递归插入右子树
    else {
        insert(root->right, val);
    }
}
