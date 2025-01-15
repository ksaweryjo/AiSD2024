#include <iostream>
#include <ctime>
#include <chrono>
#include "277513z1.h"
#include "277513z3.h"
#include "277513z5.h"
using namespace std;

void Test_Rods(unsigned long long& comparisons, unsigned long long& assignments, unsigned long long totalcomparisons, unsigned long long totalassignments) {
    int p[100000] = {};
    const int n = 100;
    for (int i = 0; i <= n; i++) {
        p[i] = rand() % 100000;
    }
    std::chrono::nanoseconds totalDuration = std::chrono::nanoseconds::zero();
    totalcomparisons = 0, totalassignments = 0;
    for (int i = 0; i < 10; i++) {
        comparisons = assignments = 0;
        auto start = std::chrono::high_resolution_clock::now();
        //int x =Cut_Rod(p, n, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();
        totalDuration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        totalassignments += assignments;
        totalcomparisons += comparisons;
    }
    cout << "CUT_ROD - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassignments/10 << ", Average Time: " << (totalDuration.count() / 10) << " nanoseconds" << std::endl;

    totalDuration = std::chrono::nanoseconds::zero();
    totalcomparisons = 0, totalassignments = 0;
    for (int i = 0; i < 10; i++) {
        comparisons = assignments = 0;
        auto start = std::chrono::high_resolution_clock::now();
        Print_Solution(p, n, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();
        totalDuration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        totalassignments += assignments;
        totalcomparisons += comparisons;
    }
    cout << "MEMORIZED_CUT_ROD - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassignments/10 << ", Average Time: " << (totalDuration.count() / 10) << " nanoseconds" << std::endl;

    totalDuration = std::chrono::nanoseconds::zero();
    totalcomparisons = 0, totalassignments = 0;
    for (int i = 0; i < 10; i++) {
        comparisons = assignments = 0;
        auto start = std::chrono::high_resolution_clock::now();
        Print_Solution_2(p, n, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();
        totalDuration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        totalassignments += assignments;
        totalcomparisons += comparisons;
    }
    cout << "BOT_UP_CUT_ROD - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassignments/10 << ", Average Time: " << (totalDuration.count() / 10) << " nanoseconds" << std::endl;

}

void Test_LCS(unsigned long long& comparisons, unsigned long long& assignments, unsigned long long totalcomparisons, unsigned long long totalassignments) {
    char X[] = {'A', 'B', 'C', 'B', 'D', 'A', 'C', 'B', 'D', 'A', 'B', 'C', 'B', 'B', 'C', 'B', 'D', 'A', 'C', 'B', 'D', 'A', 'B', 'C', 'B'};
    char Y[] = {'A', 'B', 'C', 'B', 'D', 'A', 'C', 'B', 'D', 'A', 'B', 'C', 'B', 'B', 'C', 'B', 'D', 'A'};
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);

    std::chrono::nanoseconds totalDuration = std::chrono::nanoseconds::zero();
    totalcomparisons = 0, totalassignments = 0;
    for (int i = 0; i < 10; i++) {
        comparisons = assignments = 0;
        auto start = std::chrono::high_resolution_clock::now();
        int c[MAX_M + 1][MAX_N + 1] = {0};
        char b[MAX_M + 1][MAX_N + 1] = {0};
        LCS_it(X, Y, m, n, c, b, assignments, comparisons);
        auto end = std::chrono::high_resolution_clock::now();
        totalDuration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        totalassignments += assignments;
        totalcomparisons += comparisons;
    }
    cout << "LCS_it - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassignments/10 << ", Average Time: " << (totalDuration.count() / 10) << " nanoseconds" << std::endl;

    totalDuration = std::chrono::nanoseconds::zero();
    totalcomparisons = 0, totalassignments = 0;
    for (int i = 0; i < 10; i++) {
        comparisons = assignments = 0;
        auto start = std::chrono::high_resolution_clock::now();
        int c[MAX_M + 1][MAX_N + 1] = {0};
        LCS_Rec(X, Y, m, n, c, assignments, comparisons);
        auto end = std::chrono::high_resolution_clock::now();
        totalDuration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        totalassignments += assignments;
        totalcomparisons += comparisons;
    }
    cout << "LCS_Rec - Avg Comparisons: " << totalcomparisons/10 << ", Avg Assignments: " << totalassignments/10 << ", Average Time: " << (totalDuration.count() / 10) << " nanoseconds" << std::endl;
}

void Test_ActivitySelector (unsigned long long& comparisons, unsigned long long& assignments, unsigned long long totalcomparisons, unsigned long long totalassignments) {
    Activity activities[] = {
        {0, 0},
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 9},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 14},
        {12, 16}
    };

    int n = sizeof(activities) / sizeof(activities[0]);
    int selectedRecursive[n];
    int selectedIterative[n];
    int selectedCountRecursive = 0;
    int selectedCountIterative = 0;

    std::chrono::nanoseconds totalDuration = std::chrono::nanoseconds::zero();
    totalcomparisons = 0, totalassignments = 0;
    for (int i = 0; i < 3; i++) {
        comparisons = assignments = 0;
        auto start = std::chrono::high_resolution_clock::now();
        recursiveActivitySelector(activities, 0, n - 1, selectedRecursive, selectedCountRecursive, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();
        totalDuration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        totalassignments += assignments;
        totalcomparisons += comparisons;
    }
    cout << "recursiveActivitySelector - Avg Comparisons: " << totalcomparisons/3 << ", Avg Assignments: " << totalassignments/3 << ", Average Time: " << (totalDuration.count() / 3) << " nanoseconds" << std::endl;

    totalDuration = std::chrono::nanoseconds::zero();
    totalcomparisons = 0, totalassignments = 0;
    for (int i = 0; i < 3; i++) {
        comparisons = assignments = 0;
        auto start = std::chrono::high_resolution_clock::now();
        iterativeActivitySelector(activities, n, selectedIterative, selectedCountIterative, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();
        totalDuration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        totalassignments += assignments;
        totalcomparisons += comparisons;
    }
    cout << "iterativeActivitySelector - Avg Comparisons: " << totalcomparisons/3 << ", Avg Assignments: " << totalassignments/3 << ", Average Time: " << (totalDuration.count() / 3) << " nanoseconds" << std::endl;

    totalDuration = std::chrono::nanoseconds::zero();
    totalcomparisons = 0, totalassignments = 0;
    for (int i = 0; i < 3; i++) {
        comparisons = assignments = 0;
        auto start = std::chrono::high_resolution_clock::now();
        dynamicActivitySelector(activities, n, selectedIterative, selectedCountIterative, comparisons, assignments);
        auto end = std::chrono::high_resolution_clock::now();
        totalDuration += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        totalassignments += assignments;
        totalcomparisons += comparisons;
    }
    cout << "dynamicActivitySelector - Avg Comparisons: " << totalcomparisons/3 << ", Avg Assignments: " << totalassignments/3 << ", Average Time: " << (totalDuration.count() / 3) << " nanoseconds" << std::endl;

}

int main () {
    srand(static_cast<unsigned>(time(nullptr)));
    unsigned long long comparisons, assignments;
    unsigned long long totalcomparisons, totalassignments;

    //Test_Rods(comparisons, assignments, totalcomparisons, totalassignments);
    Test_LCS(comparisons, assignments, totalcomparisons, totalassignments);
    //Test_ActivitySelector(comparisons, assignments, totalcomparisons, totalassignments);

    return 0;
}