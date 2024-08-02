#include <stdio.h>
int main(void) {
    int sum = 0, num;

    do {
        scanf("%d", &num);
        if (num % 2 == 0) {
            sum += num;
        }
    } while (num != 0);
    printf("Sum of even numbers: %d\n", sum);
    return 0;
}
