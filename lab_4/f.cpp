#include <iostream>
using namespace std;

/*给定 N 个整数，按给定顺序插入形成一棵二叉搜索树（BST）。
画水平线穿过相同高度的节点。然后会看到由节点和边组成的三角形。
任务是计算最小三角形的数量。
从例子来看，“最小三角形”指的是一个父节点和它的两个子节点形成的三角形（即完整的三节点结构）

i.e.                                3
N=3                                / \    
a = [3, 5, 1]                     1   5 -> 1 trinagle 

N=3
a = [1, 3, 5]                        1
                                      \
                                       3
                                        \
                                         5  -> 0 trinagles
*/
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(Node* &root, int val){
    if(root == NULL) {
        root = new Node(val);
        return;
    }
    else {
        if(val < root->val) insert(root->left, val);
        else insert(root->right, val);
    }
}

int sum = 0;

void travel(Node* &root){
    if(root == NULL) return;
    else {
        if(root->left != NULL && root->right != NULL) sum++;
        travel(root->left);
        travel(root->right);
    }
}

int main() {

    int n, x;
    Node* root = NULL;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        insert(root, x);
    }
    
    travel(root);
    
    cout << sum;
    
    return 0;
}