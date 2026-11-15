#include <iostream>
using namespace std;

const int SIZE = 5;

int queueArr[SIZE];
int front = -1;
int rear  = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue OVERFLOW! The queue is full." << endl;
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queueArr[rear] = value;
    cout << value << " enqueued." << endl;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue UNDERFLOW! The queue is empty." << endl;
        return;
    }

    cout << queueArr[front] << " dequeued." << endl;
    front++;

    if (front > rear) {
        front = -1;
        rear  = -1;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue (front -> rear): ";
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
