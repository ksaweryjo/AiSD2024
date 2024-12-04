#include <iostream>
using namespace std;

int partition(double arr[], int low, int high, unsigned long long& comparisons, unsigned long long& assignments) {
    int pivot = arr[high];
    assignments++;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            assignments += 3;
            comparisons++;
        }
    }

    swap(arr[i + 1], arr[high]);
    assignments += 3;
    return i + 1;
}

void quickSort(double arr[], int low, int high, unsigned long long& comparisons, unsigned long long& assignments) {
    if (low < high) {
        int pivot = partition(arr, low, high, comparisons, assignments);
        quickSort(arr, low, pivot - 1, comparisons, assignments);
        quickSort(arr, pivot + 1, high, comparisons, assignments);
    }
}

void dualPivotPartition(double arr[], int low, int high, int& lp, int& rp, unsigned long long& comparisons, unsigned long long& assignments) {
    if (arr[low] > arr[high]) {
        swap(arr[low], arr[high]);
        assignments += 3;
    }

    int pivot1 = arr[low];
    int pivot2 = arr[high];
    assignments += 2;

    int i = low + 1, lt = low + 1, gt = high - 1;

    while (i <= gt) {
        if (arr[i] < pivot1) {
            swap(arr[i], arr[lt]);
            lt++;
            comparisons++;
            assignments += 3;
        } else if (arr[i] > pivot2) {
            swap(arr[i], arr[gt]);
            gt--;
            i--;
            comparisons++;
            assignments += 3;
        }
        i++;
    }

    lt--;
    gt++;

    swap(arr[low], arr[lt]);
    swap(arr[high], arr[gt]);
    assignments += 6;
    lp = lt;
    rp = gt;
}

void dualPivotQuickSort(double arr[], int low, int high, unsigned long long& comparisons, unsigned long long& assignments) {
    if (low < high) {
        int lp, rp;
        dualPivotPartition(arr, low, high, lp, rp, comparisons, assignments);

        dualPivotQuickSort(arr, low, lp - 1, comparisons, assignments);
        dualPivotQuickSort(arr, lp + 1, rp - 1, comparisons, assignments);
        dualPivotQuickSort(arr, rp + 1, high, comparisons, assignments);
    }
}
