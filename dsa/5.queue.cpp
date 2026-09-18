// 5. Implement a Queue data structure along with its typical operations
#include <iostream>
using namespace std;

#define SIZE 5

int arr[SIZE];
int front = -1, rear = -1;

int main() {
    int choice, value;
    while (true) {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (rear == SIZE - 1) {
                cout << "Queue Overflow!" << endl;
                continue;
            }
            cout << "Enter value to enqueue: ";
            cin >> value;
            if (front == -1) front = 0;
            arr[++rear] = value;
            cout << "Inserted " << value << " into the queue." << endl;
        }
        else if (choice == 2) {
            if (front == -1 || front > rear) {
                cout << "Queue Underflow!" << endl;
                continue;
            }
            cout << "Removed " << arr[front++] << " from the queue." << endl;
        }
        else if (choice == 3) {
            if (front == -1 || front > rear) {
                cout << "Queue is empty!" << endl;
                continue;
            }
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}