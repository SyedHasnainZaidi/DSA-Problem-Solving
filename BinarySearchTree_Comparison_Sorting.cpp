#include <iostream>
#include <cstdlib>
#include <stack>

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into the binary search tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to check if two binary search trees are equal
bool isEqual(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    return (root1->data == root2->data) && isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
}

// Function to check if two binary search trees have the same structure
bool hasSameStructure(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    return hasSameStructure(root1->left, root2->left) && hasSameStructure(root1->right, root2->right);
}

// Function to sort the nodes in descending order using in-order traversal
void sortDescending(Node* root) {
    std::stack<Node*> stk;
    Node* current = root;

    while (current != nullptr || !stk.empty()) {
        while (current != nullptr) {
            stk.push(current);
            current = current->right;
        }
        current = stk.top();
        stk.pop();
        std::cout << current->data << " ";
        current = current->left;
    }
}

int main() {
    // Construct the first binary search tree
    Node* root1 = nullptr;
    root1 = insert(root1, 50);
    insert(root1, 30);
    insert(root1, 70);
    insert(root1, 20);
    insert(root1, 40);

    // Construct the second binary search tree
    Node* root2 = nullptr;
    root2 = insert(root2, 50);
    insert(root2, 30);
    insert(root2, 70);
    insert(root2, 20);
    insert(root2, 40);

    // Check if the trees are equal
    std::cout << "Are the trees equal? " << (isEqual(root1, root2) ? "Yes" : "No") << std::endl;

    // Check if the trees have the same structure
    std::cout << "Do the trees have the same structure? " << (hasSameStructure(root1, root2) ? "Yes" : "No") << std::endl;

    // Sort the nodes in descending order
    std::cout << "Nodes in descending order: ";
    sortDescending(root1);
    std::cout << std::endl;

    return 0;
}
