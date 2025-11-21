#include <iostream>
#include <map>
#include <set>

using namespace std;

// print the mode(s) of the linked list
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL){}
};
    
int main() {
    
    int n, x, MAX = 0;
    map<int, int> map;
    
    cin >> n;
    
    // create linked list,initialize the first and last node
    Node *head = NULL;
    Node *tail = NULL;   
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        map[x]++, MAX = max(map[x], MAX);
        Node* node = new Node(x);
        if(head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    
    Node* current = head;
    set<int> set;
    //set，用于存储所有出现次数等于最大频率 mx 的众数。set 的好处是会自动去重和排序
    
    while(current != NULL){
        if(map[current->val] == MAX) set.insert(current->val);
        current = current->next;
    }
    for(auto it = set.rbegin(); it != set.rend(); it++) cout << *it << ' ';
    
    
    return 0;
}