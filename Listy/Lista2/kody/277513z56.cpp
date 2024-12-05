#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "277513z2.h"
#include "277513z1.h"
#include "277513z4.h"
#include "277513z3.h"

const int SIZE = 10;

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

void copyArray(int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

void generateRandomArrayd(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

void copyArrayd(double source[], double destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

void testRadixSorts(int arr[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    int arrCopy[SIZE];
/*
    for (int i = 10; i <= 100; i += 10) {
        comparisons = assignments = 0;
        cout << "\n\nPodstawa: " << i;
        copyArray(arr, arrCopy, n);
        auto start = chrono::high_resolution_clock::now();
        radixSort(arrCopy, n, i, comparisons, assignments);
        auto end = chrono::high_resolution_clock::now();
        cout << "\nCzas: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " μs";
        cout << "\nPorownania: " << comparisons << "\nPrzypisania: " << assignments;
    }
*/
    for (int i = 10; i <= 10; i += 10) {
        comparisons = assignments = 0;
        cout << "\n\nPodstawa: " << i;
        copyArray(arr, arrCopy, n);
        auto start = chrono::high_resolution_clock::now();
        radixSort_negative(arrCopy, n, i, comparisons, assignments);
        auto end = chrono::high_resolution_clock::now();
        cout << "\nCzas: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " μs";
        cout << "\nPorownania: " << comparisons << "\nPrzypisania: " << assignments << "\n";
        /*
        for (int i = 0; i < SIZE; i++) {
            cout << arrCopy[i] << "\n";
        }
         */
    }
}

void testBucket(double arr[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    double arrCopy[SIZE];

    for (int i = 0; i < 1; i++) {
        comparisons = assignments = 0;
        copyArrayd(arr, arrCopy, n);
        auto start = chrono::high_resolution_clock::now();
        bucketSort(arrCopy, n, comparisons, assignments);
        auto end = chrono::high_resolution_clock::now();
        cout << "\nCzas: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " μs";
        cout << "\nPorownania: " << comparisons << "\nPrzypisania: " << assignments;
    }
}

void testQuick(double arr[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    double arrCopy[SIZE];

    for (int i = 0; i < 1; i++) {
        comparisons = assignments = 0;
        copyArrayd(arr, arrCopy, n);
        auto start = chrono::high_resolution_clock::now();
        quickSort(arrCopy, 0, n-1, comparisons, assignments);
        auto end = chrono::high_resolution_clock::now();
        cout << "\nCzas: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " μs";
        cout << "\nPorownania: " << comparisons << "\nPrzypisania: " << assignments;
    }

    for (int i = 0; i < 1; i++) {
        comparisons = assignments = 0;
        copyArrayd(arr, arrCopy, n);
        auto start = chrono::high_resolution_clock::now();
        dualPivotQuickSort(arrCopy, 0, n-1, comparisons, assignments);
        auto end = chrono::high_resolution_clock::now();
        cout << "\nCzas: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " μs";
        cout << "\nPorownania: " << comparisons << "\nPrzypisania: " << assignments;
    }
}

int main() {
    unsigned long long comparisons, assignments;
    srand(static_cast<unsigned>(time(0)));

    int originalArray[SIZE];
    generateRandomArray(originalArray, SIZE);
    double originalArray1[SIZE];
    generateRandomArrayd(originalArray1, SIZE);
    int tak[SIZE] = {-1,10,3,4,-2};
    //testRadixSorts(tak, SIZE, comparisons, assignments);
    //testBucket(originalArray1, SIZE, comparisons, assignments);
    //testQuick(originalArray1, SIZE, comparisons, assignments);
    /*
    Node_2* head = nullptr;
    insert(head, 4);
    insert(head, 1);
    insert(head, 7);
    insert(head, 2);
    insert(head, 3);
    insert(head, 10);
    printList(head);
    insertionSort(head);
    printList(head);
     */
    return 0;
}

