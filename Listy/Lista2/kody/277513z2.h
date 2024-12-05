#include <iostream>
using namespace std;

int getMax(int arr[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    int maxNum = arr[0];
    assignments++;
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
            assignments++;
        }
    }
    return maxNum;
}

void countingSort(int arr[], int n, int pos, int base, unsigned long long& comparisons, unsigned long long& assignments) {
    auto output = new int[n];
    int count[base] = {0};
    for (int i = 0; i < n; i++) {
        count[(arr[i] / pos) % base]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
        assignments++;
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / pos) % base] - 1] = arr[i];
        count[(arr[i] / pos) % base]--;
        assignments++;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        assignments++;
    }
}

void radixSort(int arr[], int n, int base, unsigned long long& comparisons, unsigned long long& assignments) {
    int maxNum = getMax(arr, n, comparisons, assignments);

    for (int pos = 1; maxNum / pos > 0; pos *= base)
        countingSort(arr, n, pos, base, comparisons, assignments);
}

void radixSort_negative(int arr[], int n, int base, unsigned long long& comparisons, unsigned long long& assignments) {
    const int size = base * 2 - 1;
    auto output = new int[n];

    for (int pos = 1; ; pos *= base) {
        int counter[size]{};

        bool done = true;
        for (int i = 0; i < n; i++) {
            int d = arr[i] / pos;
            assignments++;
            ++counter[d % base + size / 2];
            done &= (d == 0);
        }
        if (done)
            break;

        for (int i = 1; i < size; i++) {
            counter[i] += counter[i - 1];
            assignments++;
        }

        for (int i = n; i-- > 0; ) {
            output[--counter[arr[i] / pos % base + size / 2]] = arr[i];
            assignments++;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
            assignments++;
        }
    }

    delete[] output;
}
