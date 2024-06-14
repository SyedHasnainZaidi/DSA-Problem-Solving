#include <iostream>
#include <cstdlib>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void reverseList() {
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        head = temp->prev;
    }
}

int findMin() {
    if (head == nullptr)
        return -1; // Assuming list contains no negative numbers
    
    int minVal = head->data;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->data < minVal) {
            minVal = current->data;
        }
        current = current->next;
    }
    return minVal;
}

int findMax() {
    if (head == nullptr)
        return -1; // Assuming list contains no negative numbers
    
    int maxVal = head->data;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->data > maxVal) {
            maxVal = current->data;
        }
        current = current->next;
    }
    return maxVal;
}

int main() {
    // Insert elements into the list
    insert(5);
    insert(3);
    insert(8);
    insert(1);
    insert(10);

    std::cout << "Original List: ";
    printList();

    // Reverse the list
    reverseList();
    std::cout << "Reversed List: ";
    printList();

    // Find minimum element in the list
    std::cout << "Minimum element in the list: " << findMin() << std::endl;

    // Find maximum element in the list
    std::cout << "Maximum element in the list: " << findMax() << std::endl;

    return 0;
}
