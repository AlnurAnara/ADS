/*
Implement a function that prints the values in a SINGLE LINKED LIST in reverse order
*/
Node* reverse(Node* head){
    if (head == NULL) {
        return NULL;
    }

    Node* prev = NULL;
    Node* current = head;
    
    while(current){
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
