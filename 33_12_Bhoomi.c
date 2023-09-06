#include<stdio.h>
#include<stdlib.h>

int stack[5];
int top=-1;



void push(int);
void pop();
void display();

void main(){
    int ch;
    int n;
    while(1){
        printf("\n1.Push an element into the stack");
        printf("\n2.pop an element into the stack");
        printf("\n3.Display an element into the stack");
        printf("\n4.Display");
        printf("\nExit");

        printf("Enter choice");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:printf("Enter element to be pushed");
        scanf("%d",&n);
        push(n);
            break;
        case 2: pop();
        break;
        case 3:display();
        break;
        case 4:exit(1);
        
        default: printf("Wrong choice");
            break;
        }
    }
}
void push(int x)
{
    if (top==4)
    {
        printf("Stack is full");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int a;
    if (top==-1)
    {
        printf("Stack empty");

    }
    else
    {
        a=stack[top];
        top--;
        printf("Element popped",&a);

    }
    
}
void display()
{
    int i;
    if (top==-1)
    {
        printf("Stack empty");
    }
    else
    {
        printf("Elements in stack are:");
        for(i=top;i>=0;i--)
        {
            printf("\n%d",&stack[i]);
        }
    }
    
    
}