#include <iostream>
using namespace std;

const int SIZE = 5;

int queueArr[SIZE];
int front = -1;
int rear  = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % SIZE == front;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot add " << value << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queueArr[rear] = value;
    cout << value << " added to the queue." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Nothing to remove." << endl;
        return;
    }

    cout << queueArr[front] << " removed from the queue." << endl;

    if (front == rear) {
        front = -1;
        rear  = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue items: ";
    int i = front;
    while (true) {
        cout << queueArr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue (add)" << endl;
        cout << "2. Dequeue (remove)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number to add: ";
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
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
