#include <iostream>
using namespace std;

struct Node{
    Node * prev;
    Node * next;
    string val;
    Node(string _val): val(_val), next(NULL), prev(NULL) {}
};

Node * head = NULL;
Node * tail = NULL;
int cnt = 0;

// 判断空
bool empty(){
    return cnt == 0;
}

// 头插
void add_front(string s){
    Node* node = new Node(s);
    if (empty()) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    cnt++;
}

// 尾插
void add_back(string s){
    Node* node = new Node(s);
    if (empty()) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    cnt++;
}

// 删除头
void erase_front(){
    if (empty()) return;
    Node* temp = head;
    if (head == tail) { // 只有一个节点
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
    cnt--;
}

// 删除尾
void erase_back(){
    if (empty()) return;
    Node* temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
    cnt--;
}

// 得到头的值
string front(){
    return head->val;
}

// 得到尾的值
string back(){
    return tail->val;
}

// 清空
void clear(){
    while (!empty()) erase_front();
}

int main()
{
    string s;
    while(cin >> s){
        if(s == "add_front"){
            string t;
            cin >> t;
            add_front(t);
            cout << "ok" << endl;
        }
        if(s == "add_back"){
            string t;
            cin >> t;
            add_back(t);
            cout << "ok" << endl;
        }
        if(s == "erase_front"){
            if(empty()){
                cout << "error" << endl;
            }
            else
            {
                cout << front() << endl;
                erase_front();
            }
        }
        if(s == "erase_back"){
            if(empty()){
                cout << "error" << endl;
            }
            else{
                cout << back() << endl;
                erase_back();
            }
        }
        if(s == "front"){
            if(empty()){
                cout << "error" << endl;
            }
            else{
                cout << front() << endl;
            }
        }
        if(s == "back"){
            if(empty()){
                cout << "error" << endl;
            }
            else{
                cout << back() << endl;
            }
        }
        if(s == "clear"){
            clear();
            cout << "ok" << endl;
        }
        if(s == "exit"){
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}
