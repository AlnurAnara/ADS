#include <iostream>
#include <algorithm>
using namespace std;
/*
要构建一棵完美平衡的 BST，根节点必须是整个序列中的中位数，这样才能保证左右子树的节点数量尽可能相等。

排序 (Sort)：首先，对原始数组进行升序排序。
根节点 (Root)：完美平衡树的根节点是整个排序数组的中位数。

递归 (Recursion)：
中位数成为当前的根，先于其所有子节点被输出。
对中位数左侧的子数组（较小的值）递归调用此过程，生成左子树的完美插入顺序。
对中位数右侧的子数组（较大的值）递归调用此过程，生成右子树的完美插入顺序。

输出顺序就是这个递归过程中的先序遍历顺序：根 → 左子树 → 右子树。
2
3 5 1
3 5 1
2
1 3 5
3 1 5

*/
struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* build(int a[], int l, int r){
    if(l > r) return NULL;
    int mid = (l + r) / 2; //中位数作为根
    Node* node = new Node(a[mid]);
    node->left = build(a, l, mid - 1); // 递归地使用左半部分（所有小于中位数的值）构建左子树。
    node->right = build(a, mid + 1, r); // 递归地使用右半部分（所有大于中位数的值）构建右子树。
    return node;
}

void print(Node* root){
    if(root == NULL) return;
    cout << root->val << ' ';
    print(root->left);
    print(root->right);
}

int main() {
    
    int n = 1, t, a[33000];
    
    cin >> t;
    
    for(int i = 1; i <= t; i++) n *= 2; n--;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a + 1, a + n + 1);
    
    print(build(a, 1, n));
    
    return 0;
}