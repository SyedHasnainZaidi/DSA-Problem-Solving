#include <iostream>
#include <cstdlib>

struct Node {
    float data;
    Node* left;
    Node* right;
};

Node* createNode(float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void insert(Node* root, float value) {
    if (root->left == nullptr)
        root->left = createNode(value);
    else if (root->right == nullptr)
        root->right = createNode(value);
    else {
        insert(root->left, value);
    }
}

bool search(Node* root, float value) {
    if (root == nullptr)
        return false;
    if (root->data == value)
        return true;
    return search(root->left, value) || search(root->right, value);
}

void findPredecessorAndSuccessor(Node* root, float value, float& predecessor, float& successor) {
    if (root == nullptr)
        return;
    
    if (root->data == value) {
        // Find predecessor
        Node* temp = root->left;
        while (temp && temp->right)
            temp = temp->right;
        if (temp)
            predecessor = temp->data;

        // Find successor
        temp = root->right;
        while (temp && temp->left)
            temp = temp->left;
        if (temp)
            successor = temp->data;

        return;
    }

    if (value < root->data) {
        successor = root->data;
        findPredecessorAndSuccessor(root->left, value, predecessor, successor);
    } else {
        predecessor = root->data;
        findPredecessorAndSuccessor(root->right, value, predecessor, successor);
    }
}

int countNodes(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Create the binary tree
    Node* root = createNode(10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);

    // Search for an element
    float x = 7;
    if (search(root, x)) {
        std::cout << x << " is present in the tree.\n";

        float predecessor = -1, successor = -1;
        findPredecessorAndSuccessor(root, x, predecessor, successor);
        std::cout << "Predecessor of " << x << " is: " << predecessor << std::endl;
        std::cout << "Successor of " << x << " is: " << successor << std::endl;
    } else {
        std::cout << x << " is not present in the tree.\n";
    }

    // Count total number of nodes in the tree
    int totalNodes = countNodes(root);
    std::cout << "Total number of nodes in the tree: " << totalNodes << std::endl;

    return 0;
}
