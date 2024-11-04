#include <iostream>

void merge(int arr[], int left, int mid1, int mid2, int right, int& comparisons, int& assignments) {
    int temp[right - left + 1];
    int i = left, j = mid1 + 1, k = mid2 + 1, idx = 0;

    while (i <= mid1 && j <= mid2 && k <= right) {
        comparisons += 3;  // Trzy porównania
        if (arr[i] <= arr[j] && arr[i] <= arr[k]) temp[idx++] = arr[i++];
        else if (arr[j] <= arr[i] && arr[j] <= arr[k]) temp[idx++] = arr[j++];
        else temp[idx++] = arr[k++];
        assignments++;  // Przypisanie do temp
    }
    
    while (i <= mid1 && j <= mid2) {
        comparisons++;
        temp[idx++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
        assignments++;
    }
    while (j <= mid2 && k <= right) {
        comparisons++;
        temp[idx++] = arr[j] <= arr[k] ? arr[j++] : arr[k++];
        assignments++;
    }
    while (i <= mid1 && k <= right) {
        comparisons++;
        temp[idx++] = arr[i] <= arr[k] ? arr[i++] : arr[k++];
        assignments++;
    }

    while (i <= mid1) temp[idx++] = arr[i++];
    while (j <= mid2) temp[idx++] = arr[j++];
    while (k <= right) temp[idx++] = arr[k++];
    assignments += idx;

    for (int l = 0; l < idx; ++l) arr[left + l] = temp[l];
}

// Sortowanie przez scalanie z trzema punktami podziału
void mergeSort(int arr[], int left, int right, int& comparisons, int& assignments) {
    if (left < right) {
        comparisons++;
        int third = (right - left) / 3;
        int mid1 = left + third;
        int mid2 = right - third;

        mergeSort(arr, left, mid1, comparisons, assignments);
        mergeSort(arr, mid1 + 1, mid2, comparisons, assignments);
        mergeSort(arr, mid2 + 1, right, comparisons, assignments);

        merge(arr, left, mid1, mid2, right, comparisons, assignments);
    }
}
