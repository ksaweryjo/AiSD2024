#include <iostream>
using namespace std;

int Cut_Rod(int p[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    if (n == 0) {
        return 0;
    }
    int q = -1;
    for (int i = 1; i <= n; i++) {
        comparisons++;
        q = max(q, p[i] + Cut_Rod(p, n - i, comparisons, assignments));
        assignments++;
    }
    return q;
}

int Memorized_Cut_Rod(const int p[], int* r, int* s, int n, unsigned long long& comparisons, unsigned long long& assignments) {
    if (r[n] >= 0) {
        comparisons++;
        return r[n];
    }
    if (n == 0) {
        r[n] = 0;
        assignments++;
        return 0;
    }
    int q = -1;
    for (int i = 1; i <= n; i++) {
        comparisons++;
        int curr = p[i] + Memorized_Cut_Rod(p, r, s, n - i, comparisons, assignments);
        assignments++;
        if (curr > q) {
            q = curr;
            s[n] = i;
            assignments++;
        }
    }

    r[n] = q;
    assignments++;
    return q;
}

void Print_Solution(const int p[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    int* r = new int[n + 1];
    int* s = new int[n + 1];

    for (int i = 0; i <= n; i++) {
        r[i] = -1;
        s[i] = 0;
    }

    Memorized_Cut_Rod(p, r, s, n, comparisons, assignments);

    while (n > 0) {
        //cout << s[n] << " ";
        n -= s[n];
    }
    //cout << endl;
}

void Bottom_Up_Cut_Rod(const int p[], int* r, int* s, int n, unsigned long long& comparisons, unsigned long long& assignments) {
    r[0] = 0;
    assignments++;
    for (int j = 1; j <= n; j++) {
        int q = -1;
        for (int i = 1; i <= j; i++) {
            comparisons++;
            if (q < p[i] + r[j - i]) {
                q = p[i] + r[j - i];
                s[j] = i;
                assignments += 2;
            }
        }
        r[j] = q;
        assignments++;
    }
}

void Print_Solution_2(const int p[], int n, unsigned long long& comparisons, unsigned long long& assignments) {
    int* r = new int[n + 1]();
    int* s = new int[n + 1]();

    Bottom_Up_Cut_Rod(p, r, s, n, comparisons, assignments);

    while (n > 0) {
        //cout << s[n] << " ";
        n -= s[n];
    }
    //cout << endl;
}
