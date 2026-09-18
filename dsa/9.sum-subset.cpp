#include <iostream>
using namespace std;

int S[] = {5, 10, 12, 13, 15, 18};
int n = 6;
int subset[20];
bool solutionFound = false;

void printSubset(int k) {
    cout << "{ ";
    for (int i = 0; i < k; i++)
        cout << subset[i] << " ";
    cout << "}" << endl;
}

void sumOfSubset(int index, int currentSum, int remainingSum, int d, int k) {
    if (currentSum == d) {
        solutionFound = true;
        printSubset(k);
        return; // remove this return to find ALL subsets
    }

    if (index == n || currentSum + remainingSum < d || currentSum > d)
        return;

    // Include S[index]
    subset[k] = S[index];
    sumOfSubset(index + 1, currentSum + S[index], remainingSum - S[index], d, k + 1);

    // Exclude S[index]
    sumOfSubset(index + 1, currentSum, remainingSum - S[index], d, k);
}

int main() {
    int d = 30;
    int total = 0;
    for (int i = 0; i < n; i++) total += S[i];

    cout << "Set S = {5, 10, 12, 13, 15, 18}, d = " << d << endl;
    cout << "Subsets with sum = " << d << ":" << endl;

    sumOfSubset(0, 0, total, d, 0);

    if (!solutionFound)
        cout << "No subset with the given sum exists." << endl;

    return 0;
}

/*
Sample Output:
Set S = {5, 10, 12, 13, 15, 18}, d = 30
Subsets with sum = 30:
{ 5 12 13 }
{ 12 18 }
{ 5 10 15 }
*/