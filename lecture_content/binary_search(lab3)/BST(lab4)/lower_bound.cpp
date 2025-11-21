#include <iostream>
#include <vector>
using namespace std;

/*find the lower bound of a given value in BST
lower bound 是第一个不小于（大于或等于）目标值的元素
i.e. 
       8
      / \
     3   10
    / \    \
   1   6    14
      / \   /
     4   7 13
     
lowerBoundBST(root, 5)  // 返回节点6 (第一个>=5的节点)
lowerBoundBST(root, 6)  // 返回节点6 (精确匹配)
lowerBoundBST(root, 9)  // 返回节点10 (第一个>=9的节点)
lowerBoundBST(root, 15) // 返回nullptr (没有>=15的节点)

*/
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

// Lower Bound 递归实现
Node* lowerBound(Node* root, int target) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // 如果当前节点等于目标值，直接返回
    if (root->val == target) {
        return root;
    }
    
    // 如果当前节点小于目标值，去右子树寻找
    if (root->val < target) {
        return lowerBound(root->right, target);
    }
    
    // 当前节点大于目标值，可能有更小的满足条件的节点在左子树
    Node* leftResult = lowerBound(root->left, target);
    
    // 如果左子树找到了满足条件的节点，返回左子树的结果
    // 否则返回当前节点
    if (leftResult != nullptr) {
        return leftResult;
    } else {
        return root;
    }
}

int main() {
    int n, val;
    cin >> n;
    
    Node* root = nullptr;
    
    // 读取输入并构建BST
    for(int i = 0; i < n; i++){
        cin >> val;
        insert(root, val);
    }

    // 输入目标值
    int target;
    cin >> target;
    
    // 计算并输出结果
    Node* result = lowerBound(root, target);
    
    // 只输出lower bound结果
    cout << "Lower bound of " << target << " is ";
    if (result != nullptr) {
        cout << result->val;
    } else {
        cout << "null";
    }
    cout << endl;
    
    return 0;
}