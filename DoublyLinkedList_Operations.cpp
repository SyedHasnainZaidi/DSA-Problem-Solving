#include <iostream>
#include <cstdlib>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to delete a node with given value
void deleteNode(int value) {
    if (head == nullptr)
        return;

    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current == nullptr)
        return;

    if (current == head && current == tail) {
        head = tail = nullptr;
    } else if (current == head) {
        head = head->next;
        head->prev = nullptr;
    } else if (current == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
}

// Function to print the nodes of the list
void printNodes() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to find the minimum value node and move it to the first node
void moveMinToFront() {
    if (head == nullptr || head == tail)
        return;

    Node* minNode = head;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data < minNode->data)
            minNode = current;
        current = current->next;
    }

    if (minNode != head) {
        minNode->prev->next = minNode->next;
        if (minNode != tail) {
            minNode->next->prev = minNode->prev;
        } else {
            tail = minNode->prev;
        }
        minNode->next = head;
        head->prev = minNode;
        head = minNode;
        head->prev = nullptr;
    }
}

// Function to find the maximum value node and move it to the last node
void moveMaxToLast() {
    if (head == nullptr || head == tail)
        return;

    Node* maxNode = head;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data > maxNode->data)
            maxNode = current;
        current = current->next;
    }

    if (maxNode != tail) {
        maxNode->prev->next = maxNode->next;
        if (maxNode != head) {
            maxNode->next->prev = maxNode->prev;
        } else {
            head = maxNode->next;
        }
        maxNode->next = nullptr;
        maxNode->prev = tail;
        tail->next = maxNode;
        tail = maxNode;
    }
}

// Function to find the total number of nodes in the list
int countNodes() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

// Function to find the middle value of the linked list
int findMiddleValue() {
    if (head == nullptr)
        return -1; // Assuming list contains no negative numbers
    
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main() {
    // Insert elements into the list
    insertNode(5);
    insertNode(3);
    insertNode(8);
    insertNode(1);
    insertNode(10);

    std::cout << "Original List: ";
    printNodes();

    // Delete node with value 3
    deleteNode(3);
    std::cout << "List after deleting node with value 3: ";
    printNodes();

    // Move minimum value node to the front
    moveMinToFront();
    std::cout << "List after moving minimum value node to the front: ";
    printNodes();

    // Move maximum value node to the last
    moveMaxToLast();
    std::cout << "List after moving maximum value node to the last: ";
    printNodes();

    // Find total number of nodes in the list
    std::cout << "Total number of nodes in the list: " << countNodes() << std::endl;

    // Find the middle value of the linked list
    std::cout << "Middle value of the linked list: " << findMiddleValue() << std::endl;

    return 0;
}
