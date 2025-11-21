/*从一个可能包含连续重复姓名的列表中，去除所有连续的重复项，
然后输出剩余（去重后）的名单总数和所有学生的名字。

Input
3
kek
wow
wow
Output
All in all: 2
Students:
wow
kek
*/

#include <iostream>
using namespace std;

struct Node {
    string val;
    Node* next;
    Node(string x) : val(x), next(NULL) {}
};

void printReverse(Node* head) {
    if (head == NULL) {
        return;
    }
    
    // 递归调用：先处理下一个节点，将当前节点的打印操作推迟到栈上
    printReverse(head->next);

    // 打印操作：在所有后续节点打印完毕后，打印当前节点的值
    cout << head->val << '\n';
}

void name_list() {
    int n;
    if (!(cin >> n)) return;

    Node *head = NULL; 
    Node *tail = NULL;
    int count = 0;  
    string name;

    for (int i = 0; i < n; ++i) {
        cin >> name;
        
        if (head == NULL || name != tail->val) {
            Node* new_node = new Node(name);
            
            if (head == NULL) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
            
            count++;// 每成功添加一个非重复学生，计数器加 1
        }
    }


    cout << "All in all: " << count << '\n';
    cout << "Students:\n";
    printReverse(head);
    
    // --- 内存清理 (良好的 C++ 习惯) ---
    Node* current = head;
    while(current != NULL) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
}

int main() {    
    name_list();
    
    return 0;
}