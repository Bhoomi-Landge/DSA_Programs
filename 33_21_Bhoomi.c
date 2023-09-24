#include<stdio.h>

void bubblesort(int A[],int n){
    int temp;
    int flag;

    for(int i=0;i<n-1;i++){
        flag=0;
            for(int j=0;j<n-1-i;j++){
                if(A[j]>A[j+1]){
                    temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                    flag = 1;
                }
            }
            if(flag==0){
                break;
            }
    }
}

    int main(){
        int A[]={64,32,25,12,11,90};
        int n = sizeof(A)/sizeof(A[0]);

        printf("Original array:");
        for(int i =0;i<n-1;i++){
            printf("\n %d ",A[i]);
        }

        bubblesort(A,n);
        printf("\n Sorted array:");
        for(int i=0;i<n;i++){
            printf("\n %d ",A[i]);
        }
        return 0;
    }


