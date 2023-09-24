#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int priority;
    int data;
    struct node *next;
};
struct node*front=NULL;
struct node*tmp;
void insert(int p,int d){
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->priority=p;
    tmp->data=d;
    if(tmp==NULL){
        printf("\nMemory is not sufficient");
        exit(1);
    }
    if(front==NULL || p<front->priority){
        tmp->next=front;
        front=tmp;

    }
    else
    {
        struct node *p=front;
        while(p->next!=NULL && p->next->priority)
        p=p->next;
        tmp->next=p->next;
        p->next=tmp;

    }
}
int delete(){
    int d;
    if(front==NULL){
        printf("Enpty");
    }
    else{
    struct node *tmp =front;
     d=tmp->data;
    front=tmp->next;
    free(tmp);
    return d;
    }
}
void display(){
    if(front==NULL){
        printf("Queue is empty");
        exit(0);
    }
    struct node *p=front;
    while (p!=NULL){
        printf("\n %5d %5d",p->priority,p->data);
        p=p->next;

    }
}
int main()
{   
    int data;
    insert(2,100);
    insert(1,300);
    insert(3,200);
     display();
    data=delete();
     display();
     return 0;
}





