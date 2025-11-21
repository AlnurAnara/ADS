#include <iostream>
#include <string> 
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Node*& root 表示通过引用传递 Node* 指针，这样可以修改指针本身。
void insert(Node*& root, int val){

    if(root == NULL) {
        root = new Node(val);
        return;
    }
   
    // BST 规则：小于根节点的值放在左侧
    else if(val < root->data) {
        insert(root->left, val);
    }
    // 大于或等于根节点的值放在右侧
    else {
        insert(root->right, val);
    }
}


bool check(string s, Node* node){
    Node* cur = node;
    for(int i = 0; i < s.size(); i++){
        // 路径中断，目标不存在
        if(cur == NULL) return false;
        
        if(s[i] == 'L') {
            cur = cur->left;
        }
        else { // s[i] == 'R'
            cur = cur->right;
        }
    }
    
    // 遍历完路径后，检查是否成功停留在某个节点上（到达了一个山峰）
    if(cur != NULL) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, x;
    string s;
    Node* root = NULL;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) { 
        cin >> x;
        insert(root, x);
    }
    
   
    for(int i = 0; i < m; i++){ 
        cin >> s;
        if(check(s, root)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}