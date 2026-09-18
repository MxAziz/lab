// 3. Find an element using the Binary Search algorithm
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n); // Binary search requires a sorted array

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << " (sorted array)." << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}

/*
Sample Input:
Enter number of elements: 6
Enter 6 elements: 10 20 30 40 50 60
Enter element to search: 40

Sample Output:
Element found at index 3 (sorted array).
*/