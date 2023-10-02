#include<stdio.h>
void mergesort(int a[], int lb, int ub) {
    int mid;
    if (lb < ub) {
        mid = (ub + lb) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int c[8], k = 0;

    while (i <= mid && j <= ub) {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    while (i <= mid)
        c[k++] = a[i++];

    while (j <= ub)
        c[k++] = a[j++];

    for (i = lb, j = 0; i <= ub; j++, i++) {
        a[i] = c[j];
    }
}

int main() {
    int a[] = {45, 12, 5, 78, 19, 2, 56, 1, 62};
    int low = 0;
    int high = 8;
    mergesort(a, low, high);
    printf("Sorted array is\n");
    for (int i = 0; i < 9; i++) {
        printf("%d\n", a[i]);
    }
}
