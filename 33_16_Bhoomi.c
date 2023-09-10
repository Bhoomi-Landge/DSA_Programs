#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;

}*top = NULL;
 void push()
{
    printf("\npushed caled");
    struct node *tmp;
    int pushed_item;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Input the new value to be pushed on the stack:");
    scanf("%d",&pushed_item);
    tmp->info=pushed_item;
    tmp->link=top;
    top=tmp;
}

  void pop()
 {
    struct node *tmp;
    if(top==NULL){
        printf("\nStack is empty");
    }
    tmp = top;
     printf("%d",tmp->info);
    top = top->link; 
    free(tmp);
}
void display(){
    printf("\nDispaly called");
    struct node *tmp;
    tmp=top;
    while(tmp!=NULL){
        printf("\n%d\n",tmp->info);
        tmp=tmp->link;
    }
}

 int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
           break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong Choice\n");

        }
    }
    return 0;
}

 