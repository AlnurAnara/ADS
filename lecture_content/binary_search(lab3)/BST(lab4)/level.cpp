#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// 插入节点
void insert(Node*& root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }
    
    if (val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

// 修正：添加递归终止条件
int height(Node* root) {
    if (root == NULL) {
        return 0;  // 空树高度为0
    }
    return max(height(root->left), height(root->right)) + 1;
}

int main() {
    int n, val;
    cin >> n;
    
    Node* root = NULL;
    for(int i =0;i<n;i++){
        cin >> val;
        insert(root, val);
    }
    
    cout << height(root) << endl;
    return 0;
}