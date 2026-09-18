// 8. Find an element using the Quick Sort algorithm
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
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

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int key;
    cout << "Enter element to find: ";
    cin >> key;

    int index = linearSearch(arr, n, key);
    if (index != -1)
        cout << "Element found at index " << index << " in sorted array." << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

/*
Sample Input:
Enter number of elements: 6
Enter 6 elements: 10 7 8 9 1 5
Enter element to find: 8

Sample Output:
Sorted array: 1 5 7 8 9 10
Element found at index 3 in sorted array.
*/