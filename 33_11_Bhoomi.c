#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front = -1;
int rear = -1;
int Q[MAX];
int temp;

void enque(int x) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        Q[rear] = x;
    }
}

int deque() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1; // Return a special value or handle the error as needed
    }
    temp = Q[front];
    front = front + 1;
    return temp;
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        for (i = front; i <= rear; i++) {
            printf("Element at position %d: %d\n", i, Q[i]);
        }
    }
}

int main() {
    int ch;
    int x;
    while (1) {
        printf("1. Enqueue Operation\n");
        printf("2. Dequeue Operation\n");
        printf("3. Display the Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice of operations: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &x);
                enque(x);
                break;
            case 2:
                temp = deque();
                if (temp != -1) {
                    printf("Dequeued element: %d\n", temp);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Incorrect choice\n");
        }
    }
    return 0;
}




