#include <iostream>
using namespace std;

/*use BST to calculate the sum of value - level for each node
利用二叉搜索树计算每个节点的 value - level 之和

i.e. 
        5       lvl= 0
       / \
      3   8     lvl= 1
     / \   \
    2   4   10  lvl= 2

The sum is (5-0)+(3-1)+(8-1)+(2-2)+(4-2)+(10-2)=26

*/
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

long long total_sum = 0; // 用于累加 value - level

// 修改插入函数，增加深度参数
void insert(Node*& root, int val, int depth) {
    if (root == NULL) {
        root = new Node(val);
        total_sum += (val - depth); // 插入时累加 value - level
        return;
    }
    
    if (val < root->data) {
        insert(root->left, val, depth + 1);
    } else {
        insert(root->right, val, depth + 1);
    }
}

int main() {
    int n, val;
    cin >> n;
    
    Node* root = NULL;
    for(int i = 0; i < n; i++) {
        cin >> val;
        insert(root, val, 0); // 根节点深度为0
    }
    
    cout << total_sum << endl;
    return 0;
}