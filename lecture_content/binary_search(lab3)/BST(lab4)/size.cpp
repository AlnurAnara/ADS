#include <iostream>
#include <vector>
using namespace std;

/*find the sum of the node of the subtree of the given node
that the subtree of node X is the set of all nodes whose ancestor is node X, including it. 
计算以节点 X 为根的子树的大小（即子树中节点的总数）。
Input
7
4 2 6 1 3 5 7
4
Output
7
*/


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
    if (root == NULL) return NULL; // 树为空或未找到

    
    if (target == root->data) return root; // 找到目标节点
    // 小于当前节点值，去左子树找
    else if (target < root->data) return findNode(root->left, target);
    // 大于当前节点值，去右子树找
    else  return findNode(root->right, target);
}

// --- 4. 计算子树大小函数 ---
// 递归计算以 node 为根的子树的节点总数
int count(Node* node) {
    if (node == NULL) {
        return 0; // 空子树大小为 0
    }
    
    // 当前子树大小 = 1 (当前节点) + 左子树大小 + 右子树大小
    return 1 + count(node->left) + count(node->right);
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

    Node* targetNode = findNode(root, x);
    cout << count(targetNode) << endl;
    
    return 0;
}