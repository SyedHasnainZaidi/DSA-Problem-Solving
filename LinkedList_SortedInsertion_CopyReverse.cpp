#include <iostream>
#include <cstdlib>

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Function to insert a node in sorted order
void insertSorted(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the list
void printList(Node* start) {
    Node* current = start;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to copy the list and reverse it
Node* copyAndReverse(Node* start) {
    Node* newHead = nullptr;
    Node* current = start;
    while (current != nullptr) {
        Node* newNode = new Node;
        newNode->data = current->data;
        newNode->next = newHead;
        newHead = newNode;
        current = current->next;
    }
    return newHead;
}

int main() {
    // Insert elements into the list in sorted order
    insertSorted(5);
    insertSorted(3);
    insertSorted(8);
    insertSorted(1);
    insertSorted(10);

    std::cout << "Original List (sorted): ";
    printList(head);

    // Copy the list and reverse it
    Node* reversedList = copyAndReverse(head);

    std::cout << "Reversed List: ";
    printList(reversedList);

    return 0;
}
