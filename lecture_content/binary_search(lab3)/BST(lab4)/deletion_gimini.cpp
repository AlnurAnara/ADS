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

/*for deletion we have 3 main cases:
1.Node to be deleted has no children: Simply remove the node.

2.Node has one child: The parent node of the deleted node links directly to the deleted node's child.

3.Node has two children: 
Find the smallest value in the right subtree (known as the candidate), replace the deleted node's value with the candidate's value, and then delete the candidate node.
Find the highest value in the left subtree (known as the candidate), replace the deleted node's value with the candidate's value, and then delete the candidate node.
*/


// 查找最小值节点（用于删除有两个子节点的节点）
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// 删除节点
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root; // 树为空或节点不存在
    }
    
    // 查找要删除的节点
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // 找到要删除的节点
        
        // 情况1：没有子节点或只有一个子节点
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // 情况2：有两个子节点
        // 找到右子树的最小值节点（或左子树的最大值节点）
        Node* temp = findMin(root->right);
        
        // 用最小值替换当前节点的值
        root->val = temp->val;
        
        // 删除右子树中的最小值节点
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// 中序遍历
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 查找节点
bool search(Node* root, int data) {
    if (root == nullptr) return false;
    if (root->val == data) return true;
    if (data < root->val) return search(root->left, data);
    return search(root->right, data);
}

int main() {
    Node* root = nullptr;

    // 构建测试树
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    for (int val : values) {
        insert(root, val);
    }

    cout << "Original tree (inorder): ";
    inorder(root);
    cout << endl;

    // 测试删除各种情况的节点
    
    // 删除叶子节点 (10)
    cout << "\nDeleting leaf node 10: ";
    root = deleteNode(root, 10);
    inorder(root);
    cout << endl;

    // 删除有一个子节点的节点 (20)
    cout << "Deleting node with one child 20: ";
    root = deleteNode(root, 20);
    inorder(root);
    cout << endl;

    // 删除有两个子节点的节点 (30)
    cout << "Deleting node with two children 30: ";
    root = deleteNode(root, 30);
    inorder(root);
    cout << endl;

    // 删除根节点 (50)
    cout << "Deleting root node 50: ";
    root = deleteNode(root, 50);
    inorder(root);
    cout << endl;

    // 尝试删除不存在的节点
    cout << "Deleting non-existent node 100: ";
    root = deleteNode(root, 100);
    inorder(root);
    cout << endl;

    return 0;
}