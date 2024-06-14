#include <iostream>
#include <cstdlib>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

// Function to insert a node in sorted order
void sortedInsert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else if (head->data >= value) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
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

// Function to copy the reverse of the list into a new list
void copyReverse() {
    Node* newHead = nullptr;
    Node* current = tail;
    while (current != nullptr) {
        Node* newNode = new Node;
        newNode->data = current->data;
        newNode->next = newHead;
        if (newHead != nullptr) {
            newHead->prev = newNode;
        } else {
            head = newNode;
        }
        newHead = newNode;
        current = current->prev;
    }
}

int main() {
    // Insert elements into the list in sorted order
    sortedInsert(5);
    sortedInsert(3);
    sortedInsert(8);
    sortedInsert(1);
    sortedInsert(10);

    std::cout << "Original List (sorted): ";
    printList(head);

    // Copy the reverse of the list into a new list
    copyReverse();

    std::cout << "Reversed Copy List: ";
    printList(head);

    return 0;
}
