Explain the meaning of each of the following:
(a) int a [14];
(b) double b[] = {3.3 , 0.0 , 1.1 , 2.2};
(c) float c [5][10];
(d) int *d [10];
(e) void **e [3][4];
(f) char s[] = " Hello ";
(g) char *s = " Hello ";

(a) int a;
This declares a fixed-size 1D array of integers named 'a' with 14 elements. The elements can be accessed using indices from a to a.
(b) double b[] = {3.3, 0.0, 1.1, 2.2};
This is an example of array initialization using the brace notation. It creates a 1D array of doubles named 'b' with 4 elements. The size of the array is automatically determined by the number of initializers provided.
(c) float c;
This declares a 2D array of floats named 'c' with 5 rows and 10 columns. It can be visualized as a matrix with 5 rows and 10 columns, where each element is a float.
(d) int *d;
This declares an array of 10 pointers to integers. Each element of 'd' is a pointer that can point to an integer value. This is different from a 2D array - it's an array of pointers.
(e) void **e;
This declares a 2D array of pointers to pointers to void. It has 3 rows and 4 columns, where each element is a pointer to a pointer to void. This is a complex data structure that can be used for very flexible memory arrangements.
(f) char s[] = "Hello";
This declares a character array 's' and initializes it with the string "Hello". The size of the array is automatically determined to be 6 - 5 for the visible characters plus 1 for the null terminator '\0'.
(g) char *s = "Hello";
This declares a pointer to char named 's' and initializes it to point to a string literal "Hello". Unlike the previous declaration, this doesn't create a modifiable array. The string literal is stored in read-only memory, and 's' points to its first character.
Key differences to note:
In (f), 's' is an array that can be modified.
In (g), 's' is a pointer to a read-only string literal.
Both will allow you to read the string, but only (f) allows modification of the characters.
These declarations demonstrate various ways arrays can be used in C, from simple 1D arrays to complex arrangements of pointers, showcasing the flexibility and power of C's array system.

Consider the following code:
int a[] = {10 , 15 , 20 , 25};
int b[] = {50 , 60 , 70 , 80 , 90};
int * x[] = {a, b};
int * y[] = {a + 2 , b + 3};
int * p;
int * q;
int ** r;
p = a;
q = y [1];
r = &q;
*p = &p[3] - y [0];
r [0][1] = **r - y [0][1];
Arrays and Strings
(a) How can I draw a diagram to show the pointer relationships and what are the pointer relationships?

a: [10][15][20][25]
    ^        ^
    |        |
b: [50][60][70][80][90]
              ^
              |
x: [*][*]
    |  |
    |  v
    v  b
    a

y: [*][*]
    |  |
    |  v
    v  b+3
    a+2

p: *
   |
   v
   a

q: *
   |
   v
   b+3

r: *
   |
   v
   q

x points to the start of array a
x[1] points to the start of array b
y points to a+2 (third element of a)
y[1] points to b+3 (fourth element of b)
p points to the start of array a
q points to b+3 (fourth element of b)
r points to q


(b) Show the contents of a and b at the end.

Contents of a and b at the end:
Let's go through the operations that modify a and b:
*p = &p - y;
p points to a
&p is the address of a
y points to a[2]
So this operation calculates the difference between these pointers, which is 1
Therefore, a becomes 1
r[1] = **r - y[1];
r is q, which points to b
**r is the value at b, which is 80
y[1] is a, which is 25
So this operation calculates 80 - 25 = 55
Therefore, b becomes 55
Final contents:
a: 
b:
In summary, the array a has its first element changed to 1, and array b has its last element changed to 55.

Consider the following 2D fixed array:
int c [5][4] = {{ 1 , 2 , 3 , 4} ,
{ 5 , 6 , 7 , 8} ,
{ 9 , 10 , 11 , 12} ,
{13 , 14 , 15 , 16} ,
{17 , 18 , 19 , 20}};
Given this code, explain the meaning of each of the following expressions:
(a) c [2][1]
(b) c
(c) c[2]
(d) c + 2
(e) *(c + 2)
(f) c[2] + 1
(g) *(c[2] + 1)
(h) *(*( c + 1) + 2)
(i) c [0][6]
(j) *(( c + 2) + 1)

(a) c
This refers to the element in the 3rd row (index 2) and 2nd column (index 1) of the array. The value is 10.
(b) c
This is a pointer to the first row of the array. It's equivalent to &c, which is the address of the first element of the first row.
(c) c
This is a pointer to the first element of the 3rd row (index 2). It's equivalent to &c.
(d) c + 2
This is a pointer to the 3rd row of the array. It's equivalent to &c.
(e) *(c + 2)
This is the same as c, a pointer to the first element of the 3rd row. Its value is the address of c.
(f) c + 1
This is a pointer to the second element of the 3rd row. It's equivalent to &c.
(g) *(c + 1)
This dereferences the pointer to the second element of the 3rd row. It's equivalent to c, which is 10.
(h) (( c + 1) + 2)
This is equivalent to c, which is the element in the 2nd row (index 1) and 3rd column (index 2). The value is 7.
(i) c
This is out of bounds for the array. Accessing this element would result in undefined behavior, as the array only has 4 columns.
(j) *((c + 2) + 1)
This is equivalent to *(c + 1), which is the same as c. The value is 10.
These expressions demonstrate various ways to access and manipulate elements in a 2D array using pointer arithmetic and array indexing. It's important to note that in C, array names can be used as pointers, and pointer arithmetic on multi-dimensional arrays follows specific rules based on the array's structure.

Write suitable malloc() statements to dynamically allocate the following:
(a) An array of 25 ints.
(b) An array of 25 pointers to floats.
(c) An array of 25 pointers, each pointing to an array of 15 chars.
(Hint: use a for loop.)

(a) An array of 25 ints:
c
int *intArray = (int *)malloc(25 * sizeof(int));

This allocates a contiguous block of memory large enough to hold 25 integers.
(b) An array of 25 pointers to floats:
c
float **floatPtrArray = (float **)malloc(25 * sizeof(float *));

This allocates an array of 25 pointers, each of which can point to a float.
(c) An array of 25 pointers, each pointing to an array of 15 chars:
c
char **charArrayPtrs = (char **)malloc(25 * sizeof(char *));
for (int i = 0; i < 25; i++) {
    charArrayPtrs[i] = (char *)malloc(15 * sizeof(char));
}

This first allocates an array of 25 pointers to char. Then, it uses a for loop to allocate 15 chars for each of those 25 pointers, effectively creating a 2D array of characters.
Remember to always check if malloc() was successful (i.e., didn't return NULL) and to free the allocated memory when it's no longer needed to prevent memory leaks. For the last example, you'd need to free each sub-array before freeing the main array.

5. Miscellaneous Questions
(a) What is the difference between a pointer to an array of ints (“x”) and a pointer
to the first element of the same array (“y”)?
(b) What is the only character that cannot appear in a string, and why?


(a) The difference between a pointer to an array of ints ("x") and a pointer to the first element of the same array ("y"):
While these two pointers may seem similar, there is a subtle but important difference:
Pointer to an array of ints (x):
This is a pointer to the entire array.
Its type would be int (*)[N], where N is the size of the array.
It points to the array as a whole, not just the first element.
Incrementing this pointer would move it by the size of the entire array.
Pointer to the first element of the array (y):
This is a pointer to just the first integer in the array.
Its type would be int*.
It points specifically to the first element, not the array as a whole.
Incrementing this pointer would move it to the next integer in the array.
In practice, these pointers often have the same numeric value (address), but they are treated differently by the compiler due to their different types. This affects pointer arithmetic and how they're used in expressions.
(b) The only character that cannot appear in a string, and why:
The character that cannot appear in a C string is the null character, represented as '\0'. Here's why:
In C, strings are represented as arrays of characters terminated by a null character.
The null character serves as the string terminator, indicating the end of the string.
If a null character appeared within the string, it would prematurely signal the end of the string, causing functions that process the string to stop reading at that point.
This would lead to incorrect string handling and potential bugs in the program.
For example, if you had a string like "Hello\0World", most C string functions would treat it as just "Hello" because they stop processing at the first null character they encounter. The "World" part would be ignored.
This is why the null character is reserved for string termination and cannot be used as part of the actual string content in C.

Note: The following practical exercises relate to a single C program. As before, you
should organise your code into different .c and .h files as needed, and create a suitable
makefile.
1. Pointers to Functions
Note: This question related to last weeks prac. You just just modify that code directly.
The following questions is a whole new question
Back inside order.c, define another function called order(). This function should
take a single char as a parameter, and return a function pointer. When passed “A”,
return a pointer to ascending3(). For “D”, return a pointer to descending3() instead.
If the parameter is neither “A” nor “D”, return NULL.
To help simplify your code, write a typedef declaration for the function pointer type,
placing it in the appropriate header file.
Modify your main() function again to make use of order(). Rather than calling
ascending3() directly, you should use the function pointer returned by order().

In your header file (e.g., order.h):
Add a typedef for the function pointer type:
c
typedef int (*CompareFunc)(int, int, int);

Declare the new order() function:
c
CompareFunc order(char direction);

In your implementation file (e.g., order.c):
Implement the order() function:
c
CompareFunc order(char direction)
{
    switch(direction)
    {
        case 'A':
            return ascending3;
        case 'D':
            return descending3;
        default:
            return NULL;
    }
}

In your main.c file:
Modify the main() function to use order():
c
#include <stdio.h>
#include "order.h"

int main()
{
    int a, b, c;
    char direction;
    CompareFunc compareFunc;

    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Enter 'A' for ascending or 'D' for descending: ");
    scanf(" %c", &direction);

    compareFunc = order(direction);

    if (compareFunc == NULL)
    {
        printf("Invalid direction. Please enter 'A' or 'D'.\n");
        return 1;
    }

    printf("The %s order is: %d\n", 
           (direction == 'A') ? "ascending" : "descending", 
           compareFunc(a, b, c));

    return 0;
}

This modification uses the order() function to get the appropriate comparison function based on user input. It then uses this function pointer to perform the comparison.
Update your Makefile:
Ensure your Makefile includes all the necessary files and dependencies. It might look something like this:
makefile
CC = gcc
CFLAGS = -Wall -pedantic -ansi

order: main.o order.o
    $(CC) $(CFLAGS) -o order main.o order.o

main.o: main.c order.h
    $(CC) $(CFLAGS) -c main.c

order.o: order.c order.h
    $(CC) $(CFLAGS) -c order.c

clean:
    rm -f *.o order

These changes implement the new order() function that returns a function pointer based on the input character, and modify the main() function to use this new functionality. The typedef in the header file simplifies the declaration and use of function pointers throughout the code

2. Arrays and Functions
Write the following functions. Each takes an array of ints and the array length. The
return types differ.
You should also write a temporary main() function for testing purposes. Use the
array initialisation notation to create test arrays. (Later we’ll replace this with another
main() that takes user input via command-line parameters.)
(a) sum() — adds up all the array elements and returns the sum, an int. (For an
array containing {5, 10, 15}, sum() should return 30.)
(b) max() — returns the index of the largest element in the array. (For an array
containing {10, 5, 1}, max() should return 0. For the array {3, 15, 6, 500, 9} it
should return 3).

Worksheet 4: Arrays and Strings
(c) reverse() — reverses the order of the array elements. It doesn’t return anything.
(For an array containing {1, 2, 3, 4}, reverse() should change it to {4, 3, 2, 1}.)

#include <stdio.h>

int sum(int arr[], int length) {
    int total = 0;
    for (int i = 0; i < length; i++) {
        total += arr[i];
    }
    return total;
}

int max(int arr[], int length) {
    int maxIndex = 0;
    for (int i = 1; i < length; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void reverse(int arr[], int length) {
    for (int i = 0; i < length / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
}

int main() {
    int arr1[] = {5, 10, 15};
    int arr2[] = {10, 5, 1};
    int arr3[] = {3, 15, 6, 500, 9};
    int arr4[] = {1, 2, 3, 4};

    printf("Sum of arr1: %d\n", sum(arr1, 3));
    
    printf("Index of max element in arr2: %d\n", max(arr2, 3));
    printf("Index of max element in arr3: %d\n", max(arr3, 5));

    printf("Original arr4: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr4[i]);
    }
    printf("\n");

    reverse(arr4, 4);
    
    printf("Reversed arr4: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr4[i]);
    }
    printf("\n");

    return 0;
}

This code implements the three functions as requested:
sum() function adds up all elements in the array and returns the total.
max() function finds the index of the largest element in the array.
reverse() function reverses the order of elements in the array in-place.
The main() function demonstrates the use of these functions with test arrays. It prints the results of each function call to verify correct operation.
To compile and run this program, save it to a file (e.g., array_functions.c), then compile and execute it:

gcc -o array_functions array_functions.c
./array_functions

3. String Conversion
#include <stdio.h>
#include <stdlib.h>

void convertStringArrayToInt(char* strArray[], int intArray[], int length) {
    for (int i = 0; i < length; i++) {
        intArray[i] = atoi(strArray[i]);
    }
}

int main() {
    char* stringNumbers[] = {"7", "1", "14", "-5"};
    int length = sizeof(stringNumbers) / sizeof(stringNumbers[0]);
    int intNumbers[length];

    convertStringArrayToInt(stringNumbers, intNumbers, length);

    printf("Converted integers: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", intNumbers[i]);
    }
    printf("\n");

    return 0;
}

Let's break down the solution:
We include the necessary headers:
<stdio.h> for input/output operations
<stdlib.h> for the atoi() function
The convertStringArrayToInt function takes three parameters:
char* strArray[]: An array of strings (char pointers)
int intArray[]: An array to store the converted integers
int length: The length of both arrays
Inside the function, we use a for loop to iterate through each string in the strArray:
We use atoi(strArray[i]) to convert each string to an integer
The converted integer is stored in the corresponding position in intArray
In the main function, we demonstrate how to use this function:
We create a sample array of string-formatted integers
We calculate the length of the array
We create an integer array of the same length to store the converted values
We call the convertStringArrayToInt function
Finally, we print the converted integers to verify the result
The atoi() function is used here because it's simple and suitable for this task. However, it's worth noting that atoi() has some limitations:
It doesn't provide error checking (e.g., for non-numeric input)
It can't distinguish between a valid zero and an error condition
For more robust error handling, you could use strtol() instead of atoi(). strtol() allows you to check for conversion errors and detect if the entire string was successfully converted.
This solution effectively converts the array of string-formatted integers into an array of ints, meeting the requirements of the problem.

4. Array output
#include <stdio.h>

void outputArray(int arr[], int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
We start by printing the opening curly brace {.
We then use a for loop to iterate through the array elements:
The loop variable i goes from 0 to length - 1.
For each element, we print the integer value using printf("%d", arr[i]).
After printing each element (except the last one), we print a comma and a space , . We achieve this by checking if the current element is not the last one (i < length - 1).
After the loop, we print the closing curly brace } and a newline character.
This approach ensures that we get the correct number of commas - one after each element except the last one.
To test this function, you can use it in a main function like this:
int main() {
    int testArray[] = {4, 14, 5, 8, 2};
    int length = sizeof(testArray) / sizeof(testArray[0]);
    
    outputArray(testArray, length);
    
    return 0;
}
{4, 14, 5, 8, 2}
5. CL functions
array_functions.h
#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#define MAX_ARRAY_SIZE 100

int sum(int arr[], int length);
int max(int arr[], int length);
void reverse(int arr[], int length);
void outputArray(int arr[], int length);

#endif

array_functions.c
#include "array_functions.h"
#include <stdio.h>

int sum(int arr[], int length) {
    int total = 0;
    for (int i = 0; i < length; i++) {
        total += arr[i];
    }
    return total;
}

int max(int arr[], int length) {
    int maxIndex = 0;
    for (int i = 1; i < length; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void reverse(int arr[], int length) {
    for (int i = 0; i < length / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
}

void outputArray(int arr[], int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_functions.h"

int convertArguments(int argc, char *argv[], int arr[]) {
    int count = 0;
    for (int i = 2; i < argc && count < MAX_ARRAY_SIZE; i++) {
        arr[count++] = atoi(argv[i]);
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Error: At least two arguments are required.\n");
        return 1;
    }

    int arr[MAX_ARRAY_SIZE];
    int length = convertArguments(argc, argv, arr);

    if (strcmp(argv[1], "sum") == 0) {
        printf("Sum: %d\n", sum(arr, length));
    } else if (strcmp(argv[1], "max") == 0) {
        int maxIndex = max(arr, length);
        printf("Max: %d (at index %d)\n", arr[maxIndex], maxIndex);
    } else if (strcmp(argv[1], "reverse") == 0) {
        reverse(arr, length);
        printf("Reversed array: ");
        outputArray(arr, length);
    } else {
        fprintf(stderr, "Error: Invalid operation. Use 'sum', 'max', or 'reverse'.\n");
        return 1;
    }

    return 0;
}

Makefile
CC = gcc
CFLAGS = -Wall -pedantic -ansi

all: array_program

array_program: main.o array_functions.o
	$(CC) $(CFLAGS) -o array_program main.o array_functions.o

main.o: main.c array_functions.h
	$(CC) $(CFLAGS) -c main.c

array_functions.o: array_functions.c array_functions.h
	$(CC) $(CFLAGS) -c array_functions.c

clean:
	rm -f *.o array_program

It checks for at least two arguments.
It converts arguments 2 and onwards to integers.
It uses a maximum array size defined in the header file.
It calls the appropriate function based on the first argument.
It reports an error for invalid operations.
To compile and run the program:
Save all files in the same directory.
Run make to compile the program.
Run the program with arguments, e.g.:
./array_program sum 1 2 3 4 5
./array_program max 10 5 8 3 7
./array_program reverse 1 2 3 4 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int *arr, int length) {
    int total = 0;
    for (int i = 0; i < length; i++) {
        total += arr[i];
    }
    return total;
}

int max(int *arr, int length) {
    int maxIndex = 0;
    for (int i = 1; i < length; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void reverse(int *arr, int length) {
    for (int i = 0; i < length / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
}

void outputArray(int *arr, int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Error: At least two arguments are required.\n");
        return 1;
    }

    int length = argc - 2;  // Subtract 2 for program name and operation
    int *arr = (int *)malloc(length * sizeof(int));
    
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Convert arguments to integers
    for (int i = 0; i < length; i++) {
        arr[i] = atoi(argv[i + 2]);
    }

    if (strcmp(argv[1], "sum") == 0) {
        printf("Sum: %d\n", sum(arr, length));
    } else if (strcmp(argv[1], "max") == 0) {
        int maxIndex = max(arr, length);
        printf("Max: %d (at index %d)\n", arr[maxIndex], maxIndex);
    } else if (strcmp(argv[1], "reverse") == 0) {
        reverse(arr, length);
        printf("Reversed array: ");
        outputArray(arr, length);
    } else {
        fprintf(stderr, "Error: Invalid operation. Use 'sum', 'max', or 'reverse'.\n");
        free(arr);
        return 1;
    }

    free(arr);
    return 0;
}

int *arr = (int *)malloc(length * sizeof(int));

./program sum 1 2 3 4 5
./program max 10 5 8 3 7
./program reverse 1 2 3 4 5

7. Strings and chars
void toUpperCase(char* str);
#include <string.h>

void toUpperCase(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

without strlen
void toUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

wihout array indexing notation
void toUpperCase(char* str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 'a' + 'A';
        }
        str++;
    }
}

#include <stdio.h>
#include <string.h>

// Include one of the toUpperCase implementations here

int sum(int arr[], int length) {
    int total = 0;
    for (int i = 0; i < length; i++) {
        total += arr[i];
    }
    return total;
}

int max(int arr[], int length) {
    int maxIndex = 0;
    for (int i = 1; i < length; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void reverse(int arr[], int length) {
    for (int i = 0; i < length / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
}

void outputArray(int arr[], int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Error: At least two arguments are required.\n");
        return 1;
    }

    // Convert the first argument to uppercase
    toUpperCase(argv[1]);

    int length = argc - 2;
    int* arr = (int*)malloc(length * sizeof(int));
    
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < length; i++) {
        arr[i] = atoi(argv[i + 2]);
    }

    if (strcmp(argv[1], "SUM") == 0) {
        printf("Sum: %d\n", sum(arr, length));
    } else if (strcmp(argv[1], "MAX") == 0) {
        int maxIndex = max(arr, length);
        printf("Max: %d (at index %d)\n", arr[maxIndex], maxIndex);
    } else if (strcmp(argv[1], "REVERSE") == 0) {
        reverse(arr, length);
        printf("Reversed array: ");
        outputArray(arr, length);
    } else {
        fprintf(stderr, "Error: Invalid operation. Use 'sum', 'max', or 'reverse'.\n");
        free(arr);
        return 1;
    }

    free(arr);
    return 0;
}

./program sum 1 2 3 4 5
./program SUM 1 2 3 4 5
./program Sum 1 2 3 4 5