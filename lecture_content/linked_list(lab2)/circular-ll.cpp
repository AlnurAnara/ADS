#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head; // 指向某一个节点（通常指头结点）

public:
    CircularLinkedList() : head(nullptr) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    // 在尾部插入一个节点：O(n)
    void push_back(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            // 空链表：新节点指向自己
            head = newNode;
            newNode->next = newNode;
            return;
        }

        // 找到最后一个节点：它的 next 指向 head
        Node* cur = head;
        while (cur->next != head) {
            cur = cur->next;
        }

        cur->next = newNode;   // 原尾部指向新节点
        newNode->next = head;  // 新节点的 next 指回 head
    }

    // 在头部插入一个节点：O(n)（因为要更新最后一个节点）
    void push_front(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;
            return;
        }

        // 找到最后一个节点
        Node* cur = head;
        while (cur->next != head) {
            cur = cur->next;
        }

        // newNode 插到 head 前面
        newNode->next = head;
        cur->next = newNode; // 尾节点连向新的头
        head = newNode;      // 更新 head
    }

    // 打印整个循环链表
    void print() const {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* cur = head;
        do {
            cout << cur->data << " ";
            cur = cur->next;
        } while (cur != head);
        cout << "\n";
    }

    // 删除第一个值为 value 的节点（如果存在）
    void remove(int value) {
        if (head == nullptr) return;

        Node* cur = head;
        Node* prev = nullptr;

        // 特殊情况：链表只有一个节点
        if (head->next == head) {
            if (head->data == value) {
                delete head;
                head = nullptr;
            }
            return;
        }

        // 先处理可能删除 head 的情况
        // 找到最后一个节点 tail
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        // 如果 head 需要被删
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;  // 头后移
            tail->next = head;  // 尾结点重新指向新的 head
            delete toDelete;
            return;
        }

        // 删除非头结点：正常在圈里找
        cur = head->next;
        prev = head;

        while (cur != head) {
            if (cur->data == value) {
                prev->next = cur->next;
                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        // 没找到就什么都不做
    }

    // 析构：释放所有节点，防止内存泄漏
    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* cur = head->next;
        while (cur != head) {
            Node* nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
        delete head;
        head = nullptr;
    }
};

int main() {
    CircularLinkedList cll;

    cll.push_back(10);
    cll.push_back(20);
    cll.push_back(30);
    cout << "After push_back: ";
    cll.print();  // 10 20 30

    cll.push_front(5);
    cout << "After push_front: ";
    cll.print();  // 5 10 20 30

    cll.remove(20);
    cout << "After remove(20): ";
    cll.print();  // 5 10 30

    cll.remove(5);
    cout << "After remove(5): ";
    cll.print();  // 10 30

    return 0;
}
