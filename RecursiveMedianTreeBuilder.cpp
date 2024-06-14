#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    int level;
    Node* left;
    Node* right;
};

// Function to find the median of an array
int findMedian(int arr[], int n) {
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    } else {
        return arr[n / 2];
    }
}

// Function to create a new node
Node* newNode(int data, int level) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->level = level;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insert(Node* root, int data, int level) {
    if (data <= root->data) {
        if (root->left != NULL) {
            insert(root->left, data, level + 1);
        } else {
            root->left = newNode(data, level + 1);
        }
    } else {
        if (root->right != NULL) {
            insert(root->right, data, level + 1);
        } else {
            root->right = newNode(data, level + 1);
        }
    }
}

// Function to traverse the tree and print node levels and heights
void traverse(Node* root) {
    if (root == NULL)
        return;
    cout << "Node: " << root->data << ", Level: " << root->level << endl;
    traverse(root->left);
    traverse(root->right);
}

// Function to divide the array and build the tree recursively
Node* buildTree(int arr[], int n, int level) {
    if (n <= 0)
        return NULL;

    int median = findMedian(arr, n);
    Node* root = newNode(median, level);
    int s1_index = 0, s2_index = 0, s3_index = 0, s4_index = 0;
    int s1[n], s2[n], s3[n], s4[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] <= median / 2) {
            s1[s1_index++] = arr[i];
        } else if (arr[i] > median / 2 && arr[i] < median) {
            s2[s2_index++] = arr[i];
        } else if (arr[i] > median && arr[i] < (2 * median) / 3) {
            s3[s3_index++] = arr[i];
        } else {
            s4[s4_index++] = arr[i];
        }
    }

    root->left = buildTree(s1, s1_index, level + 1);
    root->right = buildTree(s2, s2_index, level + 1);
    insert(root, median, level);
    root->left = buildTree(s3, s3_index, level + 1);
    root->right = buildTree(s4, s4_index, level + 1);
    traverse(root);
    return root;
}

int main() {
    int arr[] = {3, 6, 2, 8, 5, 7, 1, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = buildTree(arr, n, 0);
    return 0;
}
