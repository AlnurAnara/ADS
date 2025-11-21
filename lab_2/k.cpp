#include <iostream>
#include <map>
using namespace std;

/*
The task is to ﬁnd the ﬁrst (or leftmost)non-repeating character 
each time a character is inserted to the stream. If no non-repeating element occur, then print −1

假设输入字符流是 a a b c：

读入 a → 当前流 a，第一个不重复字符是 a

读入 a → 当前流 a a，没有不重复字符 → -1

读入 b → 当前流 a a b，第一个不重复字符是 b

读入 c → 当前流 a a b c，第一个不重复字符是 b

输出：a -1 b b
*/
struct Node {
    char val;
    Node* next;
    Node(char x) : val(x), next(NULL){} 
};

int cnt = 0;

int main() {
    
    int tt;
    
    cin >> tt;
    
    while(tt--){
        int n; char c;
        map<char, int> mp;
        cin >> n;
        
        Node *head = NULL, *tail = NULL;
        
        for(int i = 1; i <= n; i++){
            cin >> c;
            Node* node = new Node(c);
            if(head == NULL) head = tail = node;
            else {
                    tail->next = node;
                    tail = node;
                
            }

            Node* cur = head;// 从链表头开始遍历
            mp[c]++;
             // 循环：只要当前节点的值在 map 中的频率大于 1，就说明它已重复，需要跳过
            while(cur != NULL && mp[cur->val] > 1) {
                cur = cur->next;
            }
            if(cur == NULL) cout << -1 << ' ';
            else cout << cur->val << ' ';
                }
                
            cout << endl;
    }
    
    return 0;
}