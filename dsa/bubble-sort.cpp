#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
// Bubble Sort with swap tracking
    for (int i = 0; i < n - 1; i++) {
        cout << "\nPass " << i + 1 << ":\n";
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
              cout << "Swapping " << arr[j] << " and " << arr[j + 1] << endl;
              swap(arr[j], arr[j + 1]);
              swapped = true;
            }
        }
// Print the array after each pass
        cout << "Array after pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
    }
        cout << endl;
        if (!swapped) break; // Stop if already sorted
    }
    cout << "\nFinal sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
    }