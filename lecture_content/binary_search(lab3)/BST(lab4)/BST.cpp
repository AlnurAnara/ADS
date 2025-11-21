#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    /* Node(int val): data(val),left(NULL),right(NULL) {}
    */
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    // Insert operation - O(log n) average, O(n) worst case
    Node *insert(Node *node, int data) {
        // 如果当前节点为空，则创建新节点并返回
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        // 如果值小于当前节点，则向左子树递归
        if (data <= node->data) 
            node->left = insert(node->left, data);
        else// 如果值大于当前节点，则向右子树递归
            node->right = insert(node->right, data);

        return node;
    }

    /* In-order traversal  (Left → Root → Right)
    - gives sorted output
    
    */
    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Pre-order traversal (Root → Left → Right)
    void preOrder(Node *node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // Post-order traversal (Left → Right → Root)
    void postOrder(Node *node) {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    // Find minimum element - leftmost node
    Node *findMin(Node *node) {
        if (node == NULL)
            return NULL;
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    // Find maximum element - rightmost node
    Node *findMax(Node *node) {
        if (node == NULL)
            return NULL;
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    // Search for a value
    Node *search(Node *node, int data) {
        if (node == NULL || node->data == data)
            return node;
        
        if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }

    // Delete operation - most complex
    Node *deleteNode(Node *node, int data) {
        if (node == NULL)
            return NULL;
            
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else {
            // Node to be deleted found
            
            // Case 1: Node has no children (leaf node)
            if (node->right == NULL && node->left == NULL) {
                delete node;
                node = NULL;
            }
            // Case 2: Node has only right child
            else if (node->left == NULL) {
                Node *temp = node;
                node = node->right;
                delete temp;
            }
            // Case 3: Node has only left child
            else if (node->right == NULL) {
                Node *temp = node;
                node = node->left;
                delete temp;
            }
            // Case 4: Node has both children
            else {
                Node *tmp = findMax(node->left);  // Find inorder predecessor
                node->data = tmp->data;           // Replace data
                node->left = deleteNode(node->left, tmp->data);  // Delete predecessor
            }
        }
        return node;
    }

    // Helper function to get height of tree
    int getHeight(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // Count total nodes in tree
    int countNodes(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
};

int main() {
    BST *bst = new BST();
    
    // Insert nodes
    bst->root = bst->insert(bst->root, 10);
    bst->root = bst->insert(bst->root, 15);
    bst->root = bst->insert(bst->root, 16);
    bst->root = bst->insert(bst->root, 13);
    bst->root = bst->insert(bst->root, 12);
    bst->root = bst->insert(bst->root, 14);
    bst->root = bst->insert(bst->root, 9);
    bst->root = bst->insert(bst->root, 8);
    bst->root = bst->insert(bst->root, 10);  // Duplicate - goes to left
    bst->root = bst->insert(bst->root, 10);  // Another duplicate
    bst->root = bst->insert(bst->root, 17);

    cout << "In-order traversal (sorted): ";
    bst->inOrder(bst->root);
    cout << endl;

    cout << "Pre-order traversal: ";
    bst->preOrder(bst->root);
    cout << endl;

    cout << "Post-order traversal: ";
    bst->postOrder(bst->root);
    cout << endl;

    // Find min and max
    Node *node_min = bst->findMin(bst->root);
    Node *node_max = bst->findMax(bst->root);
    cout << "Min: " << node_min->data << ", Max: " << node_max->data << endl;

    // Search for a value
    Node *found = bst->search(bst->root, 13);
    if (found)
        cout << "Found: " << found->data << endl;
    else
        cout << "Not found" << endl;

    // Tree statistics
    cout << "Tree height: " << bst->getHeight(bst->root) << endl;
    cout << "Total nodes: " << bst->countNodes(bst->root) << endl;

    // Delete a node
    cout << "Deleting node 13..." << endl;
    bst->root = bst->deleteNode(bst->root, 13);
    cout << "In-order after deletion: ";
    bst->inOrder(bst->root);
    cout << endl;

    return 0;
}