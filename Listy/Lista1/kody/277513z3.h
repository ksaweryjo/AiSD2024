#include <iostream>

void ternaryHeapify(int arr[], int n, int i, int& comparisons, int& assignments) {
    int largest = i;
    int left = 3 * i + 1;
    int middle = 3 * i + 2;
    int right = 3 * i + 3;

    if (left < n && ++comparisons && arr[left] > arr[largest]) largest = left;
    if (middle < n && ++comparisons && arr[middle] > arr[largest]) largest = middle;
    if (right < n && ++comparisons && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        assignments += 2;  // Przypisania dla zamiany
        ternaryHeapify(arr, n, largest, comparisons, assignments);
    }
}


// Sortowanie przez kopcowanie
void ternaryHeapSort(int arr[], int n, int& comparisons, int& assignments) {
    for (int i = n / 3 - 1; i >= 0; --i) ternaryHeapify(arr, n, i, comparisons, assignments);

    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        assignments += 2;  // Przypisania dla zamiany
        ternaryHeapify(arr, i, 0, comparisons, assignments);
    }
}
