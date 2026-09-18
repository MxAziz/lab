// 7. Solve the N-Queens problem using backtracking
#include <iostream>
using namespace std;

int board[20];
int n;
int solutionCount = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void printSolution() {
    solutionCount++;
    cout << "\nSolution " << solutionCount << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

void solveNQueens(int row) {
    if (row == n) {
        printSolution();
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1);
            // backtrack automatically as board[row] gets overwritten
        }
    }
}

int main() {
    cout << "Enter the value of N: ";
    cin >> n;

    solveNQueens(0);

    if (solutionCount == 0)
        cout << "No solution exists for N = " << n << endl;
    else
        cout << "\nTotal solutions found: " << solutionCount << endl;

    return 0;
}

/*
Sample Input:
Enter the value of N: 4

Sample Output:
Solution 1:
. Q . .
. . . Q
Q . . .
. . Q .

Solution 2:
. . Q .
Q . . .
. . . Q
. Q . .

Total solutions found: 2
*/