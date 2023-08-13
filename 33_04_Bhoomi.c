#include<stdio.h>
struct list
{
    int percentage;
    int rollno;
}l[30];
void main()
{
    
    int i,j,temp;
    for(i=1;i<=5;i++)
    {
        printf("Enter the roll no");
        scanf("%d",&l[i].rollno);
        printf("Enter percentage");
        scanf("%d",&l[i].percentage);
    }
    for(i=0;i<=5;i++)
    for(j=0;j<=5;j++) 
    {
        if(l[i].percentage>l[j].percentage)
        {
            temp = l[i].percentage;
            l[i].percentage=l[j].percentage;
            l[j].percentage=temp;
        }
    }
    printf("Students list");
    for(i=1;i<=5;i++){
        printf("%d %d\n",l[i].rollno,l[i].percentage);
    }
}