/*
the task is add all nodes which are in the range (low,heigh)
i.e. find the sum of the nodes which are greater than  3 and lower than 8
     answer: 5+4+6+7
           5
        /    \
       2      7
     /   \   /  \
    1     4 6    9
*/

#include <iostream>
using namespace std;

// 定义二叉树节点结构体
struct Node {
    int val;
    Node* left;
    Node* right;

    // 构造函数
    Node(int val) {
        this->val =val;
        left = right = NULL;
    }
};

class BinarySearchTree {
private:
    Node* root;
    Node* RangeSum(Node* root, int low,int high) {
        // 如果当前节点为空，则返回空指针
        if (root == NULL) {
            return 0;
        }
        if (root->val < low)  {
            return RangeSum(root->right, low,high);
        }

        else if (root->val > high)  {
            return RangeSum(root->left, low,high);
        }
        
        else {
            return  (RangeSum(root->right, low,high) + RangeSum(root->left, low,high) + root->val);
    };// 中序遍历，用于打印树的内容（有序）
    void inorderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->val << " ";
        inorderTraversal(node->right);
    }


public:
    // 构造函数：初始化空树
    BinarySearchTree() : root(NULL) {}

    // 公有删除方法
    void remove(int data) {
        root = deletion(root, data);
    }

    // 公有打印方法（中序遍历）
    void printTree() {
        inorderTraversal(root);
        cout << endl;
    }
    
}
