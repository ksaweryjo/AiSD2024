#include <iostream>
using namespace std;

struct Node_2 {
    double data;
    Node_2* next;
};

void insert(Node_2*& head, double value) {
    Node_2* newNode_2 = new Node_2{value, head};
    head = newNode_2;
}

void insertionSort(Node_2*& head) {
    if (!head) return;

    Node_2* sorted = nullptr;

    while (head) {
        Node_2* current = head;
        head = head->next;

        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node_2* temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    head = sorted;
}

void printList(Node_2* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}