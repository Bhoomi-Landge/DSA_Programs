#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5 // Define a constant for the maximum stack size

int stack[MAX_SIZE];
int top = -1;

void push(int);
void pop();
void display();

int main() { // Change 'void' to 'int' for 'main' and add 'return 0' to indicate successful execution
    int ch;
    int n;
    while (1) {
        printf("\n1.Push an element into the stack");
        printf("\n2.Pop an element from the stack"); // Corrected typo in the menu
        printf("\n3.Display elements in the stack"); // Corrected typo in the menu
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
                exit(0); // Change exit(1) to exit(0) to indicate successful termination

            default:
                printf("Wrong choice\n");
                break;
        }
    }
    return 0; // Add return statement to indicate successful execution
}

void push(int x) {
    if (top == MAX_SIZE - 1) { // Check if the stack is full using MAX_SIZE
        printf("Stack is full\n");
    } else {
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n"); // Corrected message to indicate stack is empty
    } else {
        int a = stack[top]; // Move the declaration of 'a' to the top of the else block
        top--;
        printf("Element popped: %d\n", a); // Corrected the format specifier
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Elements in stack are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]); // Removed '&' before stack[i] in printf
        }
    }
}



