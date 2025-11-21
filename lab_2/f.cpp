#include <iostream>
using namespace std;

/* 将val添加到指定位置
    Task: Insert a value into a linked list at a specified position. and head's index is 0
    Input:
        - The first line contains an integer n -- the number of elements in the linked list.
        - each of the next n lines contains an interger ai - the values of the elements in the linked list.
        - The second-last line contains an integer val 
        -the last line contains the pos of the value to be inserted and the position to insert it.
    Output:
        - Print the linked list after the insertion.


i.e.
input
3
16
13
7
1
2

output
16 13 1 7

*/
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL){}
};
    
int main() {
    
    int n, x, pos, val;
    
    cin >> n; // the number of elements in the linked list
    
    Node *head = NULL, *tail = NULL;
    
    //create the initial linked list
    for(int i = 1; i <= n; i++){
        cin >> x;
        Node* node = new Node(x);
        if(head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    cin >> val >> pos;

    Node* new_node = new Node(val);
    
    if(pos == 0){ //and the val into the head 
        new_node->next = head;
        head = new_node;
    } else {    
        int cnt = 0;
        Node* current = head;
        while(++cnt != pos)
            current= current->next;
        new_node->next = current->next;
        current->next = new_node;
    }

    //print the ll
    Node* cur = head;
    while(cur != NULL){
        cout << cur->val << ' ';
        cur = cur->next;
    }
    
    return 0;
}