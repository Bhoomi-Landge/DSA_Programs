#include <stdio.h>
#define MAX 5

int Q[MAX];
int front = -1;
int rear = -1;

void enque(int x) {
    if (front == 0 && rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1 && rear == -1) {
            front++;
            rear++;
            Q[rear] = x;
        } else {
            rear = (rear + 1) % MAX;
            Q[rear] = x;
        }
    }
}

void deque() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    int i;
    if (rear == -1) {
        printf("Queue is underflow\n");
    } else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice = 1, x;

    while (choice != 0) {
        printf("\n1: Insert an element");
        printf("\n2: Delete an element");
        printf("\n3: Display elements");
        printf("\n0: Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            enque(x);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 0:
            printf("Exiting program\n");
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    }

    return 0;
}


