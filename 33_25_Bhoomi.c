#include<stdio.h>
int BinarySearch(int a[],int n,int data){
    int low=0,high=n-1;
    while(low<=high){
        int mid;
        mid=(low+high)/2;
        if(data==a[mid])
        return mid;
        else if(data<a[mid])
        high=mid-1;
        else
        low=mid+1;
    
    }
    return -1;
}
int main(){
    int a[]={2,5,1,3,5,6};
    int n=6;
    int data;
    printf("Enter the element you want to search for: ");
    scanf("%d", &data);

    int result = BinarySearch(a, n, data);

    if (result != -1) {
        printf("Element %d found at index %d.\n", data, result);
    } else {
        printf("Element %d not found in the array.\n", data);
    }

    return 0;
}