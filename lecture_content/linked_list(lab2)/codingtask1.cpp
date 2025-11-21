/*You are implementing a double linked list 
with a head pointer that points to the first node in the list and a tail pointer that points to the last node in the list. 
You want to insert a new node at the end of the list. 
What would the PSEUDOCODE implementation
*/


//poseudo code
function insertAtEnd (val,head,tail):{
        // Create a new node with the given value
        Node* newNode = new Node(val);

        // If the list is empty, set both head and tail to the new node
        if (head == NULL) {
            head = tail = newNode;
        } else {
            // Link the new node to the current tail
            tail->next = newNode;
            newNode->prev = tail;
            // Update the tail to the new node
            tail = newNode;
        }
        // Return the new node
        return newNode;
    }













/*c++:
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

void insertAtEnd(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {   //check whether it is empty or not 
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

*/
