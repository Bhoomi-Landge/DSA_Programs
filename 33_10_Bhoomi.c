#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Unique elements in the array: ");
    for (int i = 0; i < size; i++) {
        int Unique = 1;
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j]) {
                Unique = 0;
                break;
            }
        }
        if (Unique) {
            printf("%d ", array[i]);
        }
    }

    return 0;
}