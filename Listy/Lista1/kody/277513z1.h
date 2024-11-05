#include <iostream>

void insertionSort(float arr[], int n, int& comparisons, int& assignments) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        assignments++;  // Przypisanie dla key
        int j = i - 1;
        while (j >= 0 && comparisons++ && arr[j] > key) {  // Porównanie i przesunięcie
            arr[j + 1] = arr[j];
            assignments++;  // Przypisanie dla przesunięcia
            j--;
        }
        arr[j + 1] = key;
        assignments++;  // Przypisanie dla wstawienia key
    }
}

// Modyfikacja z wstawianiem dwóch elementów naraz
void insertionSortDouble(float arr[], int n, int& comparisons, int& assignments) {
    for (int i = 2; i < n; i += 2) {
        float key1 = arr[i];
        float key2 = arr[i - 1];
        assignments += 2;  // Przypisania dla key1 i key2

        if (comparisons++ && key1 < key2) {
            std::swap(key1, key2);
            assignments += 2;  // Przypisania dla zamiany
        }

        int j = i - 2;
        while (j >= 0 && comparisons++ && arr[j] > key2) {
            arr[j + 2] = arr[j];
            assignments++;  // Przypisanie dla przesunięcia
            j--;
        }
        arr[j + 1] = key2;
        arr[j + 2] = key1;
        assignments += 2;  // Przypisania dla wstawienia key1 i key2
    }
}
