## 1. Preprocessor Directives
Explain the effect of the following preprocessor directives:
1) `#define MAX(a,b) ((a) > (b) ? (a) : (b))`
    Answer: ```This defines a macro named MAX that takes two arguments, a and b. It expands to a ternary operator that returns the larger of the two values. The parentheses around (a) and (b) ensure proper order of operations when the macro is used with complex expressions```
2) 
```c
#ifdef DEBUG
printf("Debug: x = %d\n", x);
#endif
```
Answer:
``` This is a conditional compilation directive. If DEBUG is defined (usually by compiling with -DDEBUG flag), the printf statement will be included in the compiled code. If DEBUG is not defined, this code block will be omitted during compilation. It's commonly used for including debug output in development builds but excluding it from release builds. ```

3) `#define STRINGIFY(x) #x`
Answer:```This macro uses the # operator to convert its argument into a string literal. For example, STRINGIFY(hello) would expand to "hello". It's useful for converting macro definitions or variable names into strings```  


4) `#define CONCAT(a, b) a##b`
Answer: ```This macro uses the ## operator to concatenate its two arguments. For instance, CONCAT(foo, bar) would expand to foobar. It's often used to create new identifiers by combining existing ones```

## 2. Static and Extern Keywords
1) What is the difference between a static global variable and a regular global variable?
2) How does the extern keyword affect variable declaration and definition?

## 3. Recursive
Create a file named fibonacci.c. Write a recursive function to calculate Fibonacci numbers. Use a static variable to keep track of the number of function calls. Your function should print this count before returning.

## 4. Function-like Macros
In a new file advanced_macros.h, create the following macros:
1) A macro to calculate the absolute value of a number
2) A macro to swap two variables of any type
Include appropriate header guards.

## 5. Bit Manipulation
Create a file bitwise.c. Write functions to:
1) Set a specific bit in an integer
2) Clear a specific bit in an integer
3) Toggle a specific bit in an integer
Use bitwise operators for these operations.

## 6. Union and Struct
In a file named data_structures.c, create a union that can store either an integer, a float, or a character. Then, create a struct that contains this union and an enum to indicate which type of data is stored.

## 7. Conditional Compilation for Platform-Specific Code
Modify your main.c to include platform-specific code using conditional compilation. For example, print different messages based on whether the code is compiled for Windows or Unix-like systems.

## 8. Advanced Makefile
Create a Makefile that:
1) Compiles all .c files in the current directory
2) Has separate rules for debug and release builds
3) Includes a rule to generate documentation using a tool like Doxygen
4) Uses pattern rules to generate object files
Test using the shell commands below
```sh
make
make debug
make docs
make clean
```