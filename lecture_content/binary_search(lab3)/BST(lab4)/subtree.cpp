/*
output the subtree of the given root node as the order of root,left node and right node
Input                                       4
5                                          / \
4 2 7 1 3                                 2   7
2                                        / \
Output                                  1   3
2 1 3 
*/


#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
 
    Node(int x) : data(x), left(NULL), right(NULL) {}
};


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

// --- 3. 查找节点函数 ---
// 在树中查找值为 target 的节点
Node* findNode(Node* root, int target) {
    if (root == NULL) {
        return NULL; // 树为空或未找到
    }
    
    if (target == root->data) {
        return root; // 找到目标节点
    }
    // 小于当前节点值，去左子树找
    else if (target < root->data) {
        return findNode(root->left, target);
    }
    // 大于当前节点值，去右子树找
    else {
        return findNode(root->right, target);
    }
}

// --- 4. 先序遍历输出函数 (新增核心函数) ---
// 按 (根 -> 左 -> 右) 顺序输出子树节点
void order(Node* node) {
    if (node == NULL) {
        return;
    }
   
    cout << node->data << " "; 
    
    order(node->left);
    
    order(node->right); 
}


int main() {
    
    int n, x;
    Node* root = NULL;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        insert(root, x);
    }
    
    cin >> x;
    
    // 1. 查找目标节点 X
    Node* targetNode = findNode(root, x);
    
    if (targetNode != nullptr) {
        order(targetNode);
    }
    cout << endl;
    
    return 0;
}