// 10. Solve 0/1 Knapsack using Dynamic Programming
// Profit P = (15, 25, 13, 23), Weight W = (2, 6, 12, 9), Capacity C = 20, n = 4
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int P[] = {15, 25, 13, 23}; // profits
    int W[] = {2, 6, 12, 9};    // weights
    int C = 20;                 // knapsack capacity

    int dp[n + 1][C + 1];

    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= C; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (W[i - 1] <= w) {
                // Either include item i-1 or exclude it, take the max
                int include = P[i - 1] + dp[i - 1][w - W[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = max(include, exclude);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Profits:  ";
    for (int i = 0; i < n; i++) cout << P[i] << " ";
    cout << endl;

    cout << "Weights:  ";
    for (int i = 0; i < n; i++) cout << W[i] << " ";
    cout << endl;

    cout << "Capacity: " << C << endl;

    cout << "\nMaximum profit that can be obtained: " << dp[n][C] << endl;

    return 0;
}

/*
Sample Output:
Profits:  15 25 13 23
Weights:  2 6 12 9
Capacity: 20

Maximum profit that can be obtained: 63
*/