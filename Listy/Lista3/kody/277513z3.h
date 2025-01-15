#include <iostream>
using namespace std;

const int MAX_M = 100;
const int MAX_N = 100;

int LCS_Rec(char X[], char Y[], int m, int n, int c[MAX_M + 1][MAX_N + 1], unsigned long long& assignments, unsigned long long& comparisons) {
    if (m == 0 || n == 0) {
        return 0;
    }

    if (X[m - 1] == Y[n - 1]) {
        comparisons++;
        assignments++;
        c[m][n] = 1 + LCS_Rec(X, Y, m - 1, n - 1, c, assignments, comparisons);
    } else {
        comparisons++;
        assignments++;
        c[m][n] = max(LCS_Rec(X, Y, m - 1, n, c, assignments, comparisons),
                            LCS_Rec(X, Y, m, n - 1, c, assignments, comparisons));
    }

    return c[m][n];
}

void LCS_it(char X[], char Y[], int m, int n, int c[MAX_M + 1][MAX_N + 1], char b[MAX_M + 1][MAX_N + 1], unsigned long long& assignments, unsigned long long& comparisons) {
    for (int i = 0; i <= m; ++i) {
        c[i][0] = 0;
        assignments++;
    }
    for (int j = 0; j <= n; ++j) {
        c[0][j] = 0;
        assignments++;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            comparisons++;
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\'; // "↖"
                assignments++;
            } else {
                comparisons++;
                if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = '|'; // "↑"
                    assignments++;
                } else {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = '-'; // "←"
                    assignments++;
                }
            }
        }
    }
}

void Print_Solution_LCS(char b[MAX_M + 1][MAX_N + 1], char X[], int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == '\\') {
        Print_Solution_LCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    } else if (b[i][j] == '|') {
        Print_Solution_LCS(b, X, i - 1, j);
    } else {
        Print_Solution_LCS(b, X, i, j - 1);
    }
}
