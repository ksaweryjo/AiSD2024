#include <iostream>

void heapify(float arr[], int n, int i, unsigned long long& comparisons, unsigned long long& assignments) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        if (arr[left] > arr[largest]) {
            comparisons++;
            largest = left;
        }
    }

    if (right < n) {
        if (arr[right] > arr[largest]) {
            comparisons++;
            largest = right;
        }
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        assignments += 3; // Trzy przypisania w swapie

        heapify(arr, n, largest, comparisons, assignments);
    }
}

void heapSort(float arr[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons, assignments);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        assignments += 3; // Trzy przypisania w swapie

        heapify(arr, i, 0, comparisons, assignments);
    }
}

void ternaryHeapify(float arr[], int n, int i, unsigned long long& comparisons, unsigned long long& assignments) {
    int largest = i;
    int left = 3 * i + 1;
    int middle = 3 * i + 2;
    int right = 3 * i + 3;

    if (left < n && ++comparisons && arr[left] > arr[largest]) largest = left;
    if (middle < n && ++comparisons && arr[middle] > arr[largest]) largest = middle;
    if (right < n && ++comparisons && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        assignments += 3;  // Przypisania dla zamiany
        ternaryHeapify(arr, n, largest, comparisons, assignments);
    }
}


// Sortowanie przez kopcowanie
void ternaryHeapSort(float arr[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    for (int i = n / 3; i >= 0; --i) ternaryHeapify(arr, n, i, comparisons, assignments);

    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        assignments += 3;  // Przypisania dla zamiany
        ternaryHeapify(arr, i, 0, comparisons, assignments);
    }
}
