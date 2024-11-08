#include <iostream>

void insertionSort(float arr[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        assignments++;  // Przypisanie dla key
        int j = i - 1;
        while (j >= 0  && arr[j] > key) {  // Porównanie i przesunięcie
            comparisons++;
            arr[j + 1] = arr[j];
            assignments++;  // Przypisanie dla przesunięcia
            j--;
        }
        arr[j + 1] = key;
        assignments++;  // Przypisanie dla wstawienia key
    }
}

// Modyfikacja z wstawianiem dwóch elementów naraz
void insertionSortDouble(float arr[], int n, unsigned long long& comparisons, unsigned long long& assignments) {    
    for (int i = 2; i < n; i += 2) {
        float key1 = arr[i];
        float key2 = arr[i - 1];
        assignments += 2;  // Przypisania dla key1 i key2

        if (++comparisons && key1 < key2) {
            std::swap(key1, key2);
            assignments += 3;  // Przypisania dla zamiany
        }

        int j = i - 2;

        while (j >= 0 && ++comparisons && arr[j] > key2) {
            arr[j + 2] = arr[j];
            assignments++;  // Przypisanie dla przesunięcia
            j--;
        }

        arr[j + 1] = key2;
        assignments++;  // Przypisanie dla key2

        while (j >= 0 && ++comparisons && arr[j] > key1) {
            arr[j + 1] = arr[j];
            assignments++;  // Przypisanie dla przesunięcia
            j--;
        }

        arr[j + 2] = key1;
        assignments++;  // Przypisanie dla key1
    }
    if ((n+1) % 2 == 0) {
        int lastKey = arr[n - 1];
        assignments++;  // Przypisanie dla lastKey
        int j = n - 2;

        while (j >= 0 && ++comparisons && arr[j] > lastKey) {
            arr[j + 1] = arr[j];
            assignments++;  // Przypisanie dla przesunięcia
            j--;
        }
        
        arr[j + 1] = lastKey;
        assignments++;  // Przypisanie dla lastKey
    }
}
