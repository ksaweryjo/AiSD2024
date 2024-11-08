#include <iostream>

void merge(float arr[], int left, int mid, int right, unsigned long long& comparisons, unsigned long long& assignments) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    float* L = new float[n1];
    float* R = new float[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        assignments++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        assignments++;
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        comparisons++;
        assignments++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        assignments++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        assignments++;
    }

    delete[] L;
    delete[] R;
}

void merge3way(float arr[], int left, int mid1, int mid2, int right, unsigned long long& comparisons, unsigned long long& assignments) {
    float temp[right - left + 1];
    int i = left, j = mid1 + 1, k = mid2 + 1, idx = 0;

    while (i <= mid1 && j <= mid2 && k <= right) {
        if (arr[i] <= arr[j] && arr[i] <= arr[k]) temp[idx++] = arr[i++];
        else if (arr[j] <= arr[i] && arr[j] <= arr[k]) temp[idx++] = arr[j++];
        else temp[idx++] = arr[k++];
        comparisons += 2;
        assignments++;  // Przypisanie do temp
    }
    
    while (i <= mid1 && j <= mid2) {
        temp[idx++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
        comparisons++;
        assignments++;
    }
    while (j <= mid2 && k <= right) {
        temp[idx++] = arr[j] <= arr[k] ? arr[j++] : arr[k++];
        comparisons++;
        assignments++;
    }
    while (i <= mid1 && k <= right) {
        temp[idx++] = arr[i] <= arr[k] ? arr[i++] : arr[k++];
        comparisons++;
        assignments++;
    }

    while (i <= mid1) {
        temp[idx++] = arr[i++];
        assignments++;
    }
    while (j <= mid2) {
        temp[idx++] = arr[j++];
        assignments++;
    }
    while (k <= right) {
        temp[idx++] = arr[k++];
        assignments++;
    }

    for (int l = 0; l < idx; ++l) {
        arr[left + l] = temp[l];
        assignments++;
    }
}

void mergeSort(float arr[], int left, int right, unsigned long long& comparisons, unsigned long long& assignments) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisons, assignments);
        mergeSort(arr, mid + 1, right, comparisons, assignments);

        merge(arr, left, mid, right, comparisons, assignments);
    }
}

// Sortowanie przez scalanie z trzema punktami podziału
void mergeSort3way(float arr[], int left, int right, unsigned long long& comparisons, unsigned long long& assignments) {
    if (left < right) {
        int third = (right - left) / 3;
        int mid1 = left + third;
        int mid2 = right - third;

        mergeSort3way(arr, left, mid1, comparisons, assignments);
        mergeSort3way(arr, mid1 + 1, mid2, comparisons, assignments);
        mergeSort3way(arr, mid2 + 1, right, comparisons, assignments);

        merge3way(arr, left, mid1, mid2, right, comparisons, assignments);
    }
}
