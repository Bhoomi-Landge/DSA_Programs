#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for a stack
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(sizeof(int) * capacity);
    if (stack->array == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->array[stack->top--];
}

// Function to evaluate an arithmetic expression
int evaluateExpression(char* expression) {
    struct Stack* stack = createStack(strlen(expression));
    int i, operand1, operand2;

    for (i = 0; expression[i]; i++) {
        if (isspace(expression[i])) {
            continue; // Skip whitespace
        } else if (isdigit(expression[i])) {
            // If it's a digit, push it onto the stack
            push(stack, expression[i] - '0');
        } else {
            // If it's an operator, pop two operands and perform the operation
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error!\n");
                        exit(1);
                    }
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
        }
    }
    
    if (!isEmpty(stack) && stack->top == 0) {
        return stack->array[stack->top];
    } else {
        printf("Invalid expression!\n");
        exit(1);
    }
}

int main() {
    char expression[100];
    
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluateExpression(expression);
    
    printf("Result: %d\n", result);

    return 0;
}
