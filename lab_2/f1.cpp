#include <iostream>
using namespace std;  // 修正拼写错误

struct Node {  // 添加结构体名称
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr) {}
};

Node* insert(Node* head, int val, int p) {
    Node* newNode = new Node(val);  // 创建新节点
    
    if (p == 0) {
        newNode->next = head;
        return newNode;
    }
    
    Node* cur = head;
    for(int i = 1; i < p && cur != nullptr; i++) {
        cur = cur->next;
    }
    
    if (cur != nullptr) {
        newNode->next = cur->next;
        cur->next = newNode;
    }
    
    return head;
}

void printList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next != nullptr) {
            cout << " ";
        }
        cur = cur->next;
    }
    cout << endl;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int n;
    cin >> n;
    
    Node* head = nullptr;
    
    // 读取初始链表元素
    for(int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        
        // 插入到链表尾部
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = newNode;
        }
    }
    
    int val, pos;
    cin >> val;  // 要插入的值
    cin >> pos;  // 要插入的位置
    
    // 插入新节点
    head = insert(head, val, pos);
    
    // 打印结果链表
    printList(head);
    
    // 释放内存
    deleteList(head);
    
    return 0;
}