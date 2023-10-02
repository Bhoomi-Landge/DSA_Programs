#include<stdio.h>

void quick(int a[],int lb,int ub)
{
    int pivot;
    if(lb<ub)
    {
        pivot = partition(a,lb,ub);
        quick(a,lb,pivot-1);
        quick(a,pivot+1,ub);
    }
}
int partition(int a[],int lb, int ub)
{
    int pivot,temp;
    int i=lb;
    int j=ub;
    pivot=a[lb];
    while(i<j)
    {
        while (a[i]<=pivot && i<ub)
        
            i++;
            while(a[j]>pivot)
            j--;
        
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;

        }
    } 
        
    a[lb]=a[j];
    a[j]=pivot;
    printf("%d\n",j);
    return j;
    }
int main(){
    int a[]={45,12,5,78,19,2,56,1,62};
    int low=0;
    int high=8;
    quick(a,low,high);
    printf("Sorted array is\n");
    for(int i=0;i<9;i++){
       printf("\n%d",a[i]);
    }
}