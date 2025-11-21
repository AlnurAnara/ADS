#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// 创建链表（尾部插入）
Node* createLinkedList(int n) {
    if (n <= 0) return nullptr;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// 打印链表
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

// 获取链表长度
int getLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// 在头部插入
Node* insertAtHead(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

// 在尾部插入
Node* insertAtTail(Node* head, int value) {
    Node* newNode = new Node(value);
    
    if (head == nullptr) {
        return newNode;
    }
    
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// 在指定位置插入
Node* insertAtPosition(Node* head, int value, int position) {
    if (position < 0) return head;
    
    if (position == 0) {
        return insertAtHead(head, value);
    }
    
    Node* newNode = new Node(value);
    Node* current = head;
    
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }
    
    if (current == nullptr) {
        // 位置超出范围，插入到尾部
        return insertAtTail(head, value);
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// 删除头部节点
Node* deleteAtHead(Node* head) {
    if (head == nullptr) return nullptr;
    
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// 删除尾部节点
Node* deleteAtTail(Node* head) {
    if (head == nullptr) return nullptr;
    
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    
    delete current->next;
    current->next = nullptr;
    return head;
}

// 删除指定位置的节点
Node* deleteAtPosition(Node* head, int position) {
    if (head == nullptr || position < 0) return head;
    
    if (position == 0) {
        return deleteAtHead(head);
    }
    
    Node* current = head;
    for (int i = 0; i < position - 1 && current->next != nullptr; i++) {
        current = current->next;
    }
    
    if (current->next == nullptr) {
        return head; // 位置超出范围
    }
    
    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;
    return head;
}

// 查找元素
bool search(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// 反转链表
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// 释放链表内存
void deleteLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    int n;
    cout << "输入链表元素个数: ";
    cin >> n;
    
    cout << "输入 " << n << " 个元素: ";
    Node* head = createLinkedList(n);
    
    cout << "创建的链表: ";
    printLinkedList(head);
    
    cout << "链表长度: " << getLength(head) << endl;
    
    // 测试插入操作
    head = insertAtHead(head, 0);
    cout << "在头部插入0后: ";
    printLinkedList(head);
    
    head = insertAtTail(head, 100);
    cout << "在尾部插入100后: ";
    printLinkedList(head);
    
    head = insertAtPosition(head, 50, 3);
    cout << "在位置3插入50后: ";
    printLinkedList(head);
    
    // 测试删除操作
    head = deleteAtHead(head);
    cout << "删除头部后: ";
    printLinkedList(head);
    
    head = deleteAtTail(head);
    cout << "删除尾部后: ";
    printLinkedList(head);
    
    head = deleteAtPosition(head, 2);
    cout << "删除位置2后: ";
    printLinkedList(head);
    
    // 测试查找
    int searchValue = 50;
    cout << "查找" << searchValue << ": " << (search(head, searchValue) ? "找到" : "未找到") << endl;
    
    // 测试反转
    head = reverseLinkedList(head);
    cout << "反转后: ";
    printLinkedList(head);
    
    // 释放内存
    deleteLinkedList(head);
    
    return 0;
}