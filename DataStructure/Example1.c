#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
    }*head;
       void create_node(int n)
    {
    struct node *tmp,*p;
	 tmp=(struct node*)malloc(sizeof(struct node)); 
    tmp->data=n;
    if(head==NULL){
    //printf("The list is empty\n");
         tmp->next=head;
        head=tmp;
    }
    else{ 
    p=head;
    while(p->next!=NULL)
    {
    p=p->next;
    
	}
       
	    tmp->next=p->next;
        p->next=tmp;
    }
    }
    void insert(int pos,int d){
    	struct node *p,*tmp;
    	tmp=(struct node *)malloc(sizeof(struct node));
    	tmp->data=d;
    	p=head;
    	int i;
    	for(i=1;i<pos-1;i++)
    {
    	p=p->next;
    	
	}
	tmp->next=p->next;
	p->next=tmp;
	
	}
    void disp(){
        struct node *p;
		int count=0;
        p=head;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
            count++;
            
        }
        printf("\n");
        printf("count is %d\n",count);
    }
    
	void del1()
	{
	
        struct node *tmp;
        
        	tmp=head;
        	head=head->next;
        	free(tmp);

    	
	}
	void search(int d){
		struct node *p;
		p=head;
		while(p->next!=NULL)
		{
			if(p->data==d){
				printf("number found");
			return;
			}
			
		
		
			p=p->next;
		}
		printf("number not found");
		
		
		
	}
    void del(int pos){
    	struct node *p, *tmp;
    	int i;
        p=head;
        	
        
        for(i=1;i<pos-1;i++)
        {p=p->next;
    }
        tmp=p->next;
        p->next=tmp->next;
        free(tmp);
		}
    	
	
     int main(){
         create_node(10);
         create_node(20);
         
         create_node(30);
         disp();
          search(10);
         insert(2,100);
         disp();
         del1();
         printf("\n after deletion\n");
         disp();
         del(2);
         disp();
        
         return 0;
     }