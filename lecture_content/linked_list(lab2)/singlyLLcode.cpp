#include <iostream>
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL) {} //creates a node with a value 0
    Node(int x): val(x), next(NULL) {} //creates a node with a given value
    Node(Node* next): val(0), next(next) {} //creates a node with a value 0, points to an existing node
    Node(int x, Node* next): val(x), next(next) {} //creates a node with a specific value and specific pointer
};
 

Node* insertAtHead(Node* head, int val){
    Node* new_node = new Node(val); // 1. 创建新节点 N
    new_node->next = head; //新节点指向当前头节点
    return new_node; //(更新头指针为新节点）
}


// 正确的在尾部插入节点的函数
Node* insertAtTail(Node* head, Node* node) {
    // 确保新节点的 next 指针是 NULL，因为它将成为新的尾节点
    if (node != NULL) {
        node->next = NULL;
    } else {
        // 如果要插入的节点是空的，直接返回原链表
        return head;
    }

    // Case 1: 链表是空的
    // 如果 head 是 NULL，那么新节点就是唯一的节点，它自己就是头节点
    if (head == NULL) {
        return node;
    }

    // Case 2: 链表不为空
    // 找到当前的最后一个节点
    Node* current = head;
    while (current->next != NULL) {
        current = current->next; // 一直移动到链表的末尾
    }

    // 将原来的最后一个节点指向新节点
    current->next = node;

    // 返回原始的头节点，因为它没有改变
    return head;
}
 
// 头部删除 (DeleteHead)
Node* deleteAtHead(Node* head) {
    // Case 1: 链表是空的
    // 如果 head 是 NULL，说明链表里没有任何节点，无法删除。
    // 直接返回 NULL 即可。
    if (head == NULL) {
        return NULL;
    }

    // Case 2: 链表不为空
    // 1. 创建一个临时指针，指向当前的头节点（这是我们要删除的节点）。
    Node* tmp = head;

    // 2. 将 head 指针移动到下一个节点。
    //    这样，原来的第二个节点就成为了新的头节点。
    head = head->next;

    // 3. 删除原来的头节点，释放它占用的内存。
    delete tmp;

    // 4. 返回更新后的新头节点。
    return head;
}

Node* deleteAtTail(Node* head) {
    // Case 1: 链表是空的 (head is NULL)
    // 没有节点可以删除，直接返回 NULL。
    if (head == NULL) {
        return NULL;
    }

    // Case 2: 链表只有一个节点 (head is the only node)
    // 如果头节点的下一个是 NULL，说明它就是唯一的节点。
    if (head->next == NULL) {
        // 删除这个唯一的节点。
        delete head;
        // 链表现在变为空，所以返回 NULL。
        return NULL;
    }

    // Case 3: 链表有两个或更多节点
    // 我们需要找到倒数第二个节点。
    Node* second_last = head;
    
    // 循环会一直进行，直到 second_last 的下一个节点的下一个节点是 NULL。
    // 这意味着 second_last->next 就是最后一个节点。
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    // 此时，second_last 指向的是倒数第二个节点。
    // 我们要删除的节点是 second_last->next。
    Node* nodeToDelete = second_last->next;

    // 将倒数第二个节点的 next 指针设为 NULL，使其成为新的尾节点。
    second_last->next = NULL;

    // 删除原来的尾节点，释放内存。
    delete nodeToDelete;

    // 头节点没有改变，返回原来的 head。
    return head;
}

Node* replace(Node* head, int p1, int p2){
    if (!head || p1 == p2) return head;

    Node* prev = NULL;
    Node* cur1 = head;
    for (int i = 1; i <= p1; i++) {
        prev = cur1;
        cur1 = cur1->next;
    }

    if(prev != NULL) prev->next = cur1->next;
    else head = cur1->next;

    Node* node = cur1;

    if(p2 == 0){
        node->next = head;
        return node;
    }

    Node* cur2 = head;
    for (int i = 0; i < p2 - 1; i++) cur2 = cur2->next;
    node->next = cur2->next;
    cur2->next = node;

    return head;
}
 
Node* reverse(Node* head){
    if (head == NULL) {
        return NULL;
    }

    Node* prev = NULL;
    Node* current = head;
    
    while(current){ //循环会一直进行，直到 current 变为 NULL，这意味着我们已经处理完了链表中的所有节点。

        Node* next = current->next;
        current->next = prev; //current 节点的 next 指针不再指向它原始的下一个节点，而是指向 prev 指针所指向的节点。这就完成了单个节点的指针反转
        
        prev = current;
        current = next;
    }
    return prev;
}

void print(Node* head){
    Node* cur = head;
    while(cur != NULL) {
    cout << cur->val << ' ';
    cur = cur->next;
   }
   cout << endl;

}
 
Node* cyclic_left(Node* head, int x){
    if (!head || !head->next) return head;

    int len = 0;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    len++;

    x %= len;
    if (x == 0) return head;

    tail->next = head;
    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
 
Node* cyclic_right(Node* head, int x){
    if (!head || !head->next) return head;

    int len = 0;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    len++;

    x %= len;
    if (x == 0) return head;

    return cyclic_left(head, len - x);
}
 
