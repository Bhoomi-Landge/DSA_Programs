#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front =-1;
int rear=-1;
int Q[MAX];
int temp;
void enque(int x)
{
    if(rear=MAX-1)
    {
        printf("Q is full");
    }
    if(front==-1)
    front=0;
    rear=rear+1;
    Q[rear]=x;
}
int deque()
{
    if(front==-1 || front>rear)
    printf("Q is empty");
    temp= Q[front];
    front = front+1;
    return (temp);
}
void display()
{
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("Display is %d\n",Q[i]);
    }
}
 void main()
{
    int ch;
    int x;
     while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit(1)\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("Enter the element to be enqueued:");
            scanf("%d",&x);
            enque(x);
            break;
            case 2:
            deque();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Incorrect choice \n");
        } 

    } 
} 
 