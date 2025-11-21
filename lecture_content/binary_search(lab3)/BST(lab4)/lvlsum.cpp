#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

/*You need to ﬁnd how many levels are there and sum the of values for each level.
    题目描述：
    给定一个整数序列，构建一个二叉搜索树（BST）。
    计算并输出这棵树的高度 k（从 0 开始计数）。
    同时，输出每一层的节点值总和。
i.e.                     4
                       / \
                      3   5       level =4
                     /           sum of the each level
                    1
                    \
                     2 
5                                            
4 3 5 1 2
output:
4
4 8 1 2

*/

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

// 计算高度
int height(Node* root) {
    if (root == NULL) {
        return 0;  // 空树高度为0
    }
    return max(height(root->left), height(root->right)) + 1;
}

int max_lvl = 0;
int cnt[5005];// 存储每层节点值总和的数组

//
void levelSum(Node* root, int lvl){
    if(root == nullptr) return;

    cnt[lvl] += root->data; //将当前节点的值累加到对应层级的计数器中
    levelSum(root->left, lvl+1); //递归处理左子树,层级增加1（因为往下一层）
    levelSum(root->right, lvl+1);//递归处理右子树
    max_lvl = max(max_lvl, lvl);//更新最大层级
}

int main() {
    
    int n, x;
    Node* root = NULL;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> x, insert(root, x);
    
    levelSum(root, 0); //计算层级总和
    
    cout << max_lvl + 1 << '\n'; //输出树的高度
    
    //输出每层节点值总和
    for(int i = 0; i <= max_lvl; i++) cout << cnt[i] << ' '; 
    
    return 0;
}