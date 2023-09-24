#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5 

int stack[MAX_SIZE];
int top = -1;

void push(int);
void pop();
void display();

int main() { 
    int ch;
    int n;
    while (1) {
        printf("\n1.Push an element into the stack");
        printf("\n2.Pop an element from the stack"); 
        printf("\n3.Display elements in the stack"); 
        printf("\n4.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0); 

            default:
                printf("Wrong choice\n");
                break;
        }
    }
    return 0; 
}

void push(int x) {
    if (top == MAX_SIZE - 1) { 
        printf("Stack is full\n");
    } else {
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n"); 
    } else {
        int a = stack[top]; 
        top--;
        printf("Element popped: %d\n", a); 
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Elements in stack are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]); 
        }
    }
}