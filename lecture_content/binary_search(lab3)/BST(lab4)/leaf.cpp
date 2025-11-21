//find the num of leavs in BST (a verterix with no child node)

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

// 统计叶子节点数量
int countLeaves(Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    // 如果是叶子节点
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    // 递归统计左右子树的叶子节点
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n, val;
    cin >> n;
    
    Node* root = NULL;
    for(int i = 0; i < n; i++) {
        cin >> val;
        insert(root, val);
    }
    
    cout << countLeaves(root) << endl;
    return 0;
}

