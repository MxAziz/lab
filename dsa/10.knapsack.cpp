#include <iostream>
using namespace std;

int main() {
    int n, C;
    cout << "Enter the number of items: ";
    cin >> n;
    int profit[n], weight[n];

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++) cin >> profit[i];

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) cin >> weight[i];

    cout << "Enter the knapsack capacity: ";
    cin >> C;

    int dp[n+1][C+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= C; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], profit[i-1] + dp[i-1][w - weight[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "Maximum profit: " << dp[n][C] << endl;
    return 0;  }

/*
Sample Input:
Enter number of items: 3
Enter profits of items: 60 100 120
Enter weights of items: 10 20 30
Enter knapsack capacity: 50

Sample Output:
Maximum profit that can be obtained: 220
*/