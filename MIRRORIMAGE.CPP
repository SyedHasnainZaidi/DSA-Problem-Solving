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

void mirrorTree(Node* root) {
    if (root == nullptr)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void printTree(Node* root) {
    if (root == nullptr)
        return;

    std::cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Create the binary tree
    Node* root = createNode(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    std::cout << "Original Tree: ";
    printTree(root);
    std::cout << std::endl;

    // Mirror the binary tree
    mirrorTree(root);

    std::cout << "Mirror Image Tree: ";
    printTree(root);
    std::cout << std::endl;

    return 0;
}
