#include <iostream>
#include <cstdlib>

struct Node {
    int data;
    int index;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->index = 0; // Initialize index to 0 initially
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
        newNode->prev = nullptr;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // Update index for the newly inserted node
    Node* current = head;
    int index = 1;
    while (current != nullptr) {
        current->index = index++;
        current = current->next;
    }
}

void print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i, j);
        }
    }

    i = (i == nullptr) ? low : i->next;
    swap(i, high);
    return i;
}

void quickSort(Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        quickSort(low, pivot->prev);
        quickSort(pivot->next, high);
    }
}

void sort() {
    if (head == nullptr || head == tail)
        return;
    quickSort(head, tail);
}

int main() {
    // Insert elements into the list
    insert(3);
    insert(8);
    insert(1);
    insert(6);
    insert(4);

    std::cout << "Original List: ";
    print();

    // Apply Quick Sort on the list
    sort();

    std::cout << "Sorted List: ";
    print();

    return 0;
}
