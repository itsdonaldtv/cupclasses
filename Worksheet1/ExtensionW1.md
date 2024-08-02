## 1. More Function Prototypes
Consider a C file containing the following functions: main, initialize, process, calculate, and display. What function prototypes would you need if:
1. main calls all other functions in order.
2. main calls initialize and display, while initialize calls process, which calls calculate.
3. main calls process, which calls all other functions.
4. calculate is called by all other functions.

## 2. Conditional Statements and Loops
Write a C program that does the following:
1. Ask the user to enter a positive integer.
2. If the number is not positive, print an error message and ask again.
3. Once a valid number is entered, print all prime numbers up to and including that number.
(For example, if the user enters 10, your program should output "2 3 5 7")
Save this program as primes.c.

## 3. Functions and Arrays
Complete the following C code (save it as array_ops.c):
```c
#include <stdio.h>
#define SIZE 10

void readArray(int arr[], int size) {
    /* To be implemented */
}

double calculateAverage(int arr[], int size) {
    /* To be implemented */
}

void printReverse(int arr[], int size) {
    /* To be implemented */
}

int main(void) {
    int numbers[SIZE];
    
    readArray(numbers, SIZE);
    printf("Average: %.2f\n", calculateAverage(numbers, SIZE));
    printf("Array in reverse: ");
    printReverse(numbers, SIZE);
    
    return 0;
}
```

Implement the following functions:
1. readArray: Should prompt the user to enter size integers and store them in the array.
2. calculateAverage: Should calculate and return the average of all numbers in the array.
3. printReverse: Should print the array elements in reverse order.
4. Compile and run your program to ensure it works as expected.
5. Remember to use proper coding standards, including appropriate comments and error checking where necessary.