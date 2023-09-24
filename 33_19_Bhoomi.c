#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Stack data structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a new stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to return the precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    int i, j;
    struct Stack* stack = createStack(strlen(infix));
    for (i = 0, j = -1; infix[i]; i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            printf("%c", infix[i]);
        } else if (isOperator(infix[i])) {
            while (stack->top != -1 && precedence(infix[i]) <= precedence(stack->array[stack->top])) {
                printf("%c", pop(stack));
            }
            push(stack, infix[i]);
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack->top != -1 && stack->array[stack->top] != '(') {
                printf("%c", pop(stack));
            }
            if (stack->top == -1 || stack->array[stack->top] != '(') {
                printf("Invalid expression: Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            } else {
                pop(stack);
            }
        }
    }
    while (stack->top != -1) {
        if (stack->array[stack->top] == '(') {
            printf("Invalid expression: Mismatched parentheses\n");
            exit(EXIT_FAILURE);
        }
        printf("%c", pop(stack));
    }
    printf("\n");
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    printf("Postfix expression: ");
    infixToPostfix(infix);
    return 0;
}
