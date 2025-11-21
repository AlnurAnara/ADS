#include <iostream>
using namespace std;

/*To clarify, you are given a poem of N words as a single linked list. Your task is to write function that
shifts linked list by K positions and returns the head of new linked list.
i.e
5 2
the show must go on
must go on the show

5 3
another one bites the dust
the dust another one bites

*/
struct Node {
    string data;
    Node* next;
    Node(string val) : data(val), next(NULL){}
};
    
int main() {
    
    int n, k;
    string s;
    
    cin >> n >> k;
    
    int cnt = 0;

    Node *head = NULL, *tail = NULL;
    
    for(int i = 1; i <= n; i++){
        cin >> s;
        Node* node = new Node(s);
        if(head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    Node* current = head;
    while(current != NULL){
        if(cnt >= k) cout << current->data << ' ';
        current = current->next;
        cnt++;
    }
    cnt = 0; current = head;
    while(cnt < k) {
        cout << current->data << ' ';
        current = current->next;
        cnt++;
    }
    
    return 0;
}