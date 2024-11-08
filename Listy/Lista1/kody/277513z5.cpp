#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "277513z1.h"
#include "277513z2.h"
#include "277513z3.h"

const int SIZE = 10;  // Rozmiar dużej tablicy testowej

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

    // Zmienne do przechowywania liczby porównań i przypisań i czasu
    unsigned long long comparisons, assignments;
    unsigned long long totalcomparisons, totalassigments;
    std::chrono::duration<double> totalDuration;

    totalDuration = std::chrono::duration<double>::zero();
    totalcomparisons = 0, totalassigments = 0;
    for(int i = 0; i < 10; i++) {
        // 1. Test Insertion Sort
        copyArray(originalArray, arr, SIZE);
        comparisons = assignments = 0;

        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(arr, SIZE, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();

        totalDuration += end - start;
        totalassigments += assignments;
        totalcomparisons += comparisons;
    }
    std::cout << "Insertion Sort - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassigments/10 << ", Average Time: " << (totalDuration.count() / 10) << " seconds" << std::endl;

    totalDuration = std::chrono::duration<double>::zero();
    totalcomparisons = 0, totalassigments = 0;
    for(int i = 0; i < 10; i++) {
        // 2. Test Insertion Sort (Modified Double Insertion)
        copyArray(originalArray, arr, SIZE);
        comparisons = assignments = 0;

        auto start = std::chrono::high_resolution_clock::now();
        insertionSortDouble(arr, SIZE, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();

        totalDuration += end - start;
        totalassigments += assignments;
        totalcomparisons += comparisons;
    }
    std::cout << "Insertion Sort (Double) - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassigments/10 << ", Average Time: " << (totalDuration.count() / 10) << " seconds" << std::endl;

    totalDuration = std::chrono::duration<double>::zero();
    totalcomparisons = 0, totalassigments = 0;
    for(int i = 0; i < 10; i++) {
        // 3. Test Merge Sort
        copyArray(originalArray, arr, SIZE);
        comparisons = assignments = 0;

        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, SIZE - 1, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();

        totalDuration += end - start;
        totalassigments += assignments;
        totalcomparisons += comparisons;
    }
    std::cout << "Merge Sort - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassigments/10 << ", Average Time: " << (totalDuration.count() / 10) << " seconds" << std::endl;

    totalDuration = std::chrono::duration<double>::zero();
    totalcomparisons = 0, totalassigments = 0;
    for(int i = 0; i < 10; i++) {
        // 4. Test Merge Sort (Modified Three-Way Merge)
        copyArray(originalArray, arr, SIZE);
        comparisons = assignments = 0;

        auto start = std::chrono::high_resolution_clock::now();
        mergeSort3way(arr, 0, SIZE - 1, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();

        totalDuration += end - start;
        totalassigments += assignments;
        totalcomparisons += comparisons;
    }
    std::cout << "Merge Sort (Three-Way) - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassigments/10 << ", Average Time: " << (totalDuration.count() / 10) << " seconds" << std::endl;

    totalDuration = std::chrono::duration<double>::zero();
    totalcomparisons = 0, totalassigments = 0;
    for(int i = 0; i < 10; i++) {
        // 5. Test Heap Sort
        copyArray(originalArray, arr, SIZE);
        comparisons = assignments = 0;

        auto start = std::chrono::high_resolution_clock::now();
        heapSort(arr, SIZE, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();

        totalDuration += end - start;
        totalassigments += assignments;
        totalcomparisons += comparisons;
    }
    std::cout << "Heap Sort - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassigments/10 << ", Average Time: " << (totalDuration.count() / 10) << " seconds" << std::endl;

    totalDuration = std::chrono::duration<double>::zero();
    totalcomparisons = 0, totalassigments = 0;
    for(int i = 0; i < 10; i++) {
        // 6. Test Heap Sort (Modified Ternary Heap)
        copyArray(originalArray, arr, SIZE);
        comparisons = assignments = 0;

        auto start = std::chrono::high_resolution_clock::now();
        ternaryHeapSort(arr, SIZE, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();

        totalDuration += end - start;
        totalassigments += assignments;
        totalcomparisons += comparisons;
    }
    std::cout << "Heap Sort (Ternary Heap) - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassigments/10 << ", Average Time: " << (totalDuration.count() / 10) << " seconds" << std::endl;

    return 0;
}
