// 11. Solve the Tower of Hanoi problem for N disks
#include <iostream>
using namespace std;

int moveCount = 0;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 0) return;

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    moveCount++;
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;

    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');

    cout << "Total moves: " << moveCount << endl;

    return 0;
}

/*
Sample Input:
Enter number of disks: 3

Sample Output:
Move disk 1 from rod A to rod C
Move disk 2 from rod A to rod B
Move disk 1 from rod C to rod B
Move disk 3 from rod A to rod C
Move disk 1 from rod B to rod A
Move disk 2 from rod B to rod C
Move disk 1 from rod A to rod C
Total moves: 7
*/