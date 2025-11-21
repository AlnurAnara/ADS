#include <iostream>
using namespace std;

/*
1. inserts - add a node on position p.
2. remove - remove the node from position p.
3. print - print all values of list separated by a space.
4. replace - move the node from position p1 and to position p2. Position p2 is considered at the moment
after its removal.
5. reverse - reverse the entire list.
6. cyclic_left - do a cyclic shift to the left x times.
7. cyclic_right - do a cyclic shift to the right x times.

*/

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL) {} //creates a node with a value 0
    Node(int x): val(x), next(NULL) {} //creates a node with a given value
    Node(Node* next): val(0), next(next) {} //creates a node with a value 0, points to an existing node
    Node(int x, Node* next): val(x), next(next) {} //creates a node with a specific value and specific pointer
};
 
Node* insert(Node* head, Node* node, int p){
    if (p == 0) {
        node->next = head;
        return node;
    }
    Node* cur = head;
    for(int i = 1; i <= p - 1 && cur != NULL; i++) cur = cur->next;
    node->next = cur->next;
    cur->next = node;
    return head;

}
 
Node* remove(Node* head, int p){

    if(!head) return 0;
    if(p == 0){
        Node* tmp = head->next;
        delete head;
        return tmp;
    }

    Node* cur = head;
    for(int i=1; i <= p-1 && cur !=NULL; i++) cur = cur->next;
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
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
    Node* prev = NULL;
    Node* cur = head;
    while(cur){
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
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
 
int main(){
    Node* head = NULL;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}