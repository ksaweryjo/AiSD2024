#include <iostream>
#include <cstdlib>
#include <ctime>
#include "277513z1.h"
#include "277513z2.h"
#include "277513z3.h"

const int SIZE = 100000;  // Rozmiar dużej tablicy testowej

void generateRandomArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;  // Generuje liczby losowe do 100000
    }
}

void copyArray(float source[], float destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

int main() {
    srand(time(0));
    float originalArray[SIZE];
    generateRandomArray(originalArray, SIZE);

    // Tablice dla kopii testowych
    float arr[SIZE];

    // Zmienne do przechowywania liczby porównań i przypisań
    int comparisons, assignments;

    // 1. Test Insertion Sort
    copyArray(originalArray, arr, SIZE);
    comparisons = assignments = 0;
    insertionSort(arr, SIZE, comparisons, assignments);
    std::cout << "Insertion Sort - Comparisons: " << comparisons << ", Assignments: " << assignments << std::endl;

    // 2. Test Insertion Sort (Modified Double Insertion)
    copyArray(originalArray, arr, SIZE);
    comparisons = assignments = 0;
    insertionSortDouble(arr, SIZE, comparisons, assignments);
    std::cout << "Insertion Sort (Double) - Comparisons: " << comparisons << ", Assignments: " << assignments << std::endl;

    // 3. Test Merge Sort
    copyArray(originalArray, arr, SIZE);
    comparisons = assignments = 0;
    mergeSort(arr, 0, SIZE - 1, comparisons, assignments);
    std::cout << "Merge Sort - Comparisons: " << comparisons << ", Assignments: " << assignments << std::endl;

    // 4. Test Merge Sort (Modified Three-Way Merge)
    copyArray(originalArray, arr, SIZE);
    comparisons = assignments = 0;
    mergeSort3way(arr, 0, SIZE - 1, comparisons, assignments);
    std::cout << "Merge Sort (Three-Way) - Comparisons: " << comparisons << ", Assignments: " << assignments << std::endl;

    // 5. Test Heap Sort
    copyArray(originalArray, arr, SIZE);
    comparisons = assignments = 0;
    heapSort(arr, SIZE, comparisons, assignments);
    std::cout << "Heap Sort - Comparisons: " << comparisons << ", Assignments: " << assignments << std::endl;

    // 6. Test Heap Sort (Modified Ternary Heap)
    copyArray(originalArray, arr, SIZE);
    comparisons = assignments = 0;
    ternaryHeapSort(arr, SIZE, comparisons, assignments);
    std::cout << "Heap Sort (Ternary Heap) - Comparisons: " << comparisons << ", Assignments: " << assignments << std::endl;

    return 0;
}
