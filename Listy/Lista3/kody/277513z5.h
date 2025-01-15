#include <iostream>

using namespace std;

struct Activity {
    int start;
    int finish;
};

void recursiveActivitySelector(Activity activities[], int k, int n, int selected[], int &selectedCount, unsigned long long& comparisons, unsigned long long& assignments) {
    int m = k + 1;
    assignments++;
    while (m <= n && activities[m].start < activities[k].finish) {
        comparisons++;
        m++;
        assignments++;
    }
    if (m <= n) {
        comparisons++;
        selected[selectedCount++] = m;
        assignments += 2;
        recursiveActivitySelector(activities, m, n, selected, selectedCount, comparisons, assignments);
    }
}

void iterativeActivitySelector(Activity activities[], int n, int selected[], int &selectedCount, unsigned long long& comparisons, unsigned long long& assignments) {
    int k = 0;
    selected[selectedCount++] = k;
    assignments += 2;

    for (int m = 1; m < n; ++m) {
        comparisons++;
        if (activities[m].start >= activities[k].finish) {
            comparisons++;
            selected[selectedCount++] = m;
            k = m;
            assignments += 3;
        }
    }
}

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void dynamicActivitySelector(Activity activities[], int n, int selected[], int& selectedCount, unsigned long long& comparisons, unsigned long long& assignments) {
    int dp[n];

    std::sort(activities, activities + n, compare);
    assignments++;

    dp[0] = 1;
    assignments++;

    for (int i = 1; i < n; ++i) {
        dp[i] = 1;
        assignments++;

        for (int j = i - 1; j >= 0; --j) {
            comparisons++;
            if (activities[i].start >= activities[j].finish) {
                dp[i] = std::max(dp[i], dp[j] + 1);
                assignments++;
            }
        }
    }

    int maxActivities = dp[n - 1];
    int currentTime = activities[n - 1].finish;
    selectedCount = 0;

    for (int i = n - 1; i >= 0; --i) {
        comparisons++;
        if (dp[i] == maxActivities && activities[i].finish <= currentTime) {
            selected[selectedCount++] = i;
            assignments += 2;
            maxActivities--;
            currentTime = activities[i].start;
        }
    }

    for (int i = 0; i < selectedCount / 2; ++i) {
        int temp = selected[i];
        selected[i] = selected[selectedCount - 1 - i];
        selected[selectedCount - 1 - i] = temp;
        assignments += 3;
    }
}