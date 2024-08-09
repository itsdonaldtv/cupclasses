Pointer Problems
There is an error in each of the following. What is it?
(a) int value = NULL;
(b) int* pointer;
pointer = 42;
(c) int* pointer; *pointer = 42;
(d) char ch; char** pointer; pointer = &ch;
(e) double value = 42.0; void* pointer = (void*)&value; *pointer = 84.0;
(f) void (*pointer)(int, int); (*pointer)(5, 10);
(g) int function1 (void) { return 42.0; }
void function2(void) {
void (*pointer)(int);
pointer = &function1;
Referencing and Dereferencing
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
(d) Can an int pointer be equal to a char pointer?
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