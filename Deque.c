#include <stdio.h>

#define SIZE 5

int deque[SIZE];
int front = -1;
int rear  = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % SIZE == front;
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is FULL! Cannot insert %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear  = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }

    deque[front] = value;
    printf("%d inserted at the FRONT.\n", value);
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque is FULL! Cannot insert %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear  = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    deque[rear] = value;
    printf("%d inserted at the REAR.\n", value);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is EMPTY! Nothing to delete.\n");
        return;
    }

    printf("%d deleted from the FRONT.\n", deque[front]);

    if (front == rear) {
        front = -1;
        rear  = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is EMPTY! Nothing to delete.\n");
        return;
    }

    printf("%d deleted from the REAR.\n", deque[rear]);

    if (front == rear) {
        front = -1;
        rear  = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
}

void display() {
    int i;

    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque (front -> rear): ");
    i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n===== DEQUE MENU =====\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter a number: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
