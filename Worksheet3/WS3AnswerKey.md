1. Pointer Problems
There is an error in each of the following. What is it?
(a) int value = NULL;
Error: NULL is typically used for pointers, not for integer variables. NULL is a macro that expands to a null pointer constant, which is not compatible with an integer type.
Correction: If you want to initialize an integer with a "null" value, use 0 or define a specific value to represent "not set":

(b) int* pointer;
pointer = 42;

Error: You're trying to assign an integer value (42) directly to a pointer variable. Pointers should hold memory addresses, not integer values.
Correction: If you want to point to an integer with value 42, you need to:

(c) int* pointer; *pointer = 42;
Error: You're dereferencing an uninitialized pointer. This can lead to undefined behavior or a segmentation fault.
Correction: First allocate memory or point to a valid integer variable:

(d) char ch; char** pointer; pointer = &ch;
Error: Type mismatch. You're trying to assign the address of a char to a pointer-to-pointer-to-char.
Correction: Either change the pointer type or the assignment:

(e) double value = 42.0; void* pointer = (void*)&value; *pointer = 84.0;
Error: You can't dereference a void pointer directly. The compiler doesn't know the size or type of data it points to.
Correction: Cast the void pointer back to the original type before dereferencing:


(f) void (*pointer)(int, int); (*pointer)(5, 10);
Error: The function pointer is not initialized before being called.
Correction: Assign a valid function to the pointer before calling it:

(g) int function1 (void) { return 42.0; } void function2(void) {
void (*pointer)(int);
pointer = &function1;
Error: There are two issues here. First, function1 is declared to return an int but is returning a double (42.0). Second, the function pointer in function2 is declared with a different signature than function1.
int function1(void) { return 42; }

Correction:
void function2(void) {
    int (*pointer)(void);
    pointer = &function1;
}

2. Referencing and Dereferencing
Given these declarations:

int a = 2;
int b = 10;
int* x = NULL;
int* y = NULL;
int** s = NULL;
int** t = NULL;
What are the values of a and b after each of the following? Draw a small diagram showing which variables point to which other variables. (Assume variables are "reset" after each example.)
(a) x = &a;
*x = b;
(b) s = &x;
x = &a;
y = &b;
t = s;
**t = **t * *y;
(c) int i;
x = &a;
y = &b;
for(i = 1; i <= *x; i++)
{
*y = *y * 2;
}
(d) x = &b;
y = &a;
t = &y;
*t = x;
if (**t > 5) {
s = t;
}
else {
s = &x;
}
**s = **s / *x;
(e) x = (int*) malloc(sizeof(int));
y = (int*)malloc(sizeof(int));
*x = 8;
*y = 8;
if (x == y) {
a = *x;
}
if (*x == *y) {
b = *y;
}
(f) s = (int**) malloc(sizeof(int*));
s = (int)malloc(sizeof(int));
t = s;
x = s;
t = b;
s = (int)malloc(sizeof(int));
*s = &a;
**s = *x;
Miscellaneous Questions
(a) Why does scanf() produce a segmentation fault when you pass it an int without the &?
(b) If you have an int pointer, why would it be wrong to put a & in front of it when passing it to scanf()?
(c) Without any other information, can you determine what type of value is stored at the address of a void pointer?
(d) Can an int pointer be equal to a char pointer
Practical Exercises
Valgrind
Obtain memerrors.c and compile it. Run it with different arguments (1-5) and observe errors. Then run with Valgrind to identify memory errors.
Passing by Reference
Create order.c with functions:
ascending2(): Takes two int pointers, orders them in ascending order.
ascending3(): Takes three int pointers, orders them in ascending order.
descending3(): Takes three int pointers, orders them in descending order.
Create numbers.c with main() to test these functions.
Scanf with Pointers
Create user_input.c with function readInts() to read three ints and one char from user input.
Modify main() to:
Call readInts()
Pass the three ints to ascending3()
Output the result
This plain text version preserves the essential content and structure of the worksheet while removing formatting specifics and LaTeX notation.


3. Miscellaneous Questions
(a) Why does scanf() produce a segmentation fault when you pass it an int without the &?
scanf() expects the address of the variable where it should store the input. If you pass an int directly instead of its address, scanf() will try to write to that value as if it were an address, causing a segmentation fault.
(b) If you have an int pointer, why would it be wrong to put a & in front of it when passing it to scanf()?
An int pointer already contains an address. If you use & on a pointer, you're passing the address of the pointer itself, not the address it points to. This would cause scanf() to overwrite the pointer value, not the int it points to.
(c) Without any other information, can you determine what type of value is stored at the address of a void pointer?
No, you cannot. A void pointer can point to any data type, and without additional context or type information, it's impossible to know what type of data it's pointing to or how to interpret that data correctly.
(d) Can an int pointer be equal to a char pointer?
In terms of the address they hold, yes, they can be equal if they point to the same memory location. However, they interpret the data at that location differently. It's generally not good practice to use pointers of different types to access the same memory, as it can lead to undefined behavior.