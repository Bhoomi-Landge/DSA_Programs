#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Deque {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
};

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = -1;
    deque->rear = -1;
    deque->size = 0;
    return deque;
}

int isFull(struct Deque* deque) {
    return (deque->size == MAX_SIZE);
}

int isEmpty(struct Deque* deque) {
    return (deque->size == 0);
}

void addFront(struct Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot add front.\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front = (deque->front - 1) % MAX_SIZE;
    }
    deque->arr[deque->front] = item;
    deque->size++;
}

void addRear(struct Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot add rear.\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->arr[deque->rear] = item;
    deque->size++;
}

int removeFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove front.\n");
        return -1; // Assuming -1 is an invalid value in the deque
    }
    int item = deque->arr[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
    deque->size--;
    return item;
}

int removeRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove rear.\n");
        return -1; // Assuming -1 is an invalid value in the deque
    }
    int item = deque->arr[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX_SIZE - 1;
    } else {
        deque->rear = (deque->rear - 1) % MAX_SIZE;
    }
    deque->size--;
    return item;
}

int main() {
    struct Deque* deque = createDeque();
    
    addFront(deque, 1);
    addRear(deque, 2);
    addFront(deque, 3);
    
    printf("Deque: ");
    while (!isEmpty(deque)) {
        printf("%d ", removeFront(deque));
    }
    
    free(deque);
    
    return 0;
}
