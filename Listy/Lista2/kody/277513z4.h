#include <iostream>

using namespace std;
struct Node {
    double data;
    Node* next;
};

void insert(Node*& head, double value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void insertionSort(Node*& head, unsigned long long& comparisons, unsigned long long& assignments) {
    if (head == nullptr) return;
    comparisons++;
    Node* sorted = nullptr;

    while (head) {
        Node* current = head;
        head = head->next;
        assignments += 2;
        if (!sorted || sorted->data >= current->data) {
            comparisons++;
            current->next = sorted;
            sorted = current;
            assignments+=2;
        } else {
            Node* temp = sorted;
            assignments++;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
                comparisons++;
                assignments++;
            }
            current->next = temp->next;
            temp->next = current;
            assignments += 2;
        }
    }
    head = sorted;
    assignments++;
}

void bucketSort(double arr[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    if (n <= 0) return;

    double minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            assignments++;
        }
        if (arr[i] > maxVal){
            maxVal = arr[i];
            assignments++;
        }
        comparisons += 2;
    }

    int numBuckets = n;
    double bucketRange = (maxVal - minVal);

    Node** buckets = new Node*[numBuckets]();

    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - minVal) / (maxVal - minVal) * n;
        if (bucketIndex == numBuckets) bucketIndex--;
        insert(buckets[bucketIndex], arr[i]);
    }

    for (int i = 0; i < numBuckets; i++) {
        insertionSort(buckets[i], comparisons, assignments);
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        Node* current = buckets[i];
        assignments++;
        while (current != nullptr) {
            comparisons++;
            arr[index++] = current->data;
            Node* temp = current;
            current = current->next;
            assignments += 3;
            delete temp;
        }
    }
    delete[] buckets;
}

void printArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
