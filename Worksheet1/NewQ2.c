#include <stdio.h>
#define SIZE 5

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main(void) {
    int numbers[SIZE];
    fillArray(numbers, SIZE);
    printf("Maximum: %d\n", findMax(numbers, SIZE));
    return 0;
}