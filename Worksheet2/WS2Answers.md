PreLab
1.  Preprocessor Directives
(a) #include <marvellous.h>
This directive tells the preprocessor to include the contents of the system header file "marvellous.h". The angle brackets <> indicate that the compiler should look for this file in the standard system directories.
(b) #include "marvellous.h"
Similar to (a), but the quotation marks "" tell the compiler to look for the file in the current directory first, before checking system directories.
(c) #define LENGTH 100
This creates a macro named LENGTH with the value 100. Anywhere LENGTH appears in the code, it will be replaced with 100 during preprocessing.
(d) #define CUBE(x) ((x) * (x) * (x))
This defines a function-like macro CUBE that takes an argument x and expands to ((x) * (x) * (x)). The extra parentheses ensure proper order of operations.
(e) #define CALC(x,y,z) ((x) + CUBE(y) + CUBE(CUBE(z)))
This defines a more complex macro CALC that takes three arguments and uses the previously defined CUBE macro in its expansion.
(f) ```
#ifdef LENGTH
printf("%d", LENGTH);
#endif
text
This is a conditional compilation directive. If LENGTH is defined, the printf statement will be included in the compiled code. If LENGTH is not defined, this code block will be omitted.

(g) ```
#ifndef THEFILE
#define THEFILE
void f(void)
{
printf("Hello world\n");
}
#endif

This is an include guard. It prevents the enclosed code from being included multiple times. If THEFILE is not defined, it defines it and includes the function definition. If THEFILE is already defined, this entire block is skipped.

2. Global Variables and Static Functions
Global variables are generally considered bad programming practice for several reasons:
Lack of encapsulation: Global variables can be accessed and modified from any part of the program, making it difficult to track changes and understand dependencies.
Reduced modularity: Global variables create implicit couplings between different parts of the code, making it harder to reuse or modify components independently.
Namespace pollution: Global variables clutter the global namespace, increasing the risk of naming conflicts.
Concurrency issues: In multi-threaded programs, global variables can lead to race conditions and require careful synchronization.
Difficulty in testing: Functions that rely on global state are harder to test in isolation.
Reduced code readability: It becomes challenging to understand a function's behavior without knowing the state of all relevant global variables.
Unintended side effects: Changes to global variables in one part of the program can have unexpected impacts elsewhere.
Initialization order problems: In C++, the order of initialization for global variables across different translation units is not guaranteed, potentially leading to bugs.
As for why you would never declare a static function in a header file:
Static functions in C/C++ have internal linkage, meaning they are only visible within the translation unit where they are defined. Declaring a static function in a header file would be counterproductive because:
The function would be duplicated in every translation unit that includes the header, leading to code bloat.
Each copy of the function would be separate and inaccessible from other translation units, defeating the purpose of putting it in a shared header file.
It could lead to unexpected behavior if different translation units end up with different versions of the "same" function.

Lab Questions
1. Headers
(a) Which file(s) does main.c include?
main.c directly includes "database.h".
(b) Which file(s) include util.h?
"database.h", "util.c", and "interface.c" include util.h.
(c) What .o files would be created during compilation?
The following .o files would be created:
main.o
database.o
util.o
interface.o
(d) If database.h is modified, which .o file(s) would need to be recompiled?
If database.h is modified, the following files would need to be recompiled:
main.o
database.o
(e) If util.h is modified, which .o file(s) would need to be recompiled?
If util.h is modified, the following files would need to be recompiled:
main.o (indirectly through database.h)
database.o (indirectly through database.h)
util.o
interface.o
(f) If util.c is modified, which .o file(s) would need to be recompiled?
If util.c is modified, only util.o would need to be recompiled.

2. Powers.c
#include <stdio.h>

unsigned int power_of_two(void) {
    static unsigned int power = 1;
    power *= 2;
    return power;
}

int main(void) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("Power of 2: %u\n", power_of_two());
    }
    return 0;
}

Key points:
The static keyword is crucial here. It allows the power variable to maintain its value between function calls, enabling the sequence of powers of 2.
We use unsigned int to allow for larger values before overflow occurs.
The function takes no parameters and relies solely on its internal state.
This implementation will work correctly for the first 31 calls (2^1 to 2^31). After that, integer overflow will occur, as noted in the problem statement.   

3. Macros
macros.h
#ifndef MACROS_H
#define MACROS_H

/* Define TRUE and FALSE macros */
#define TRUE 1
#define FALSE 0

#endif /* MACROS_H */

Header guards:
#ifndef MACROS_H checks if MACROS_H is not defined
#define MACROS_H defines MACROS_H
#endif /* MACROS_H */ at the end closes the conditional compilation block
These guards prevent multiple inclusions of the header file, which could lead to compilation errors.
Macros for TRUE and FALSE:
#define TRUE 1 defines TRUE as 1
#define FALSE 0 defines FALSE as 0
These macros allow you to use TRUE and FALSE in your code, which can improve readability, especially in boolean contexts.

Usage:
int result = TRUE;
if (result == TRUE) {
    /* Do something */
}

3. Bounds checking
#include <stdio.h>
#include "macros.h"

int between_int(int low, int high, int value) {
    return (value >= low && value <= high) ? TRUE : FALSE;
}

int between_double(double low, double high, double value) {
    return (value >= low && value <= high) ? TRUE : FALSE;
}

int between_char(char low, char high, char value) {
    return (value >= low && value <= high) ? TRUE : FALSE;
}

int main(void) {
    // Test integer bounds checking
    printf("Integer bounds check (1, 10, 5): %d\n", between_int(1, 10, 5));
    printf("Integer bounds check (1, 10, 15): %d\n", between_int(1, 10, 15));

    // Test double bounds checking
    printf("Double bounds check (0.5, 5.5, 3.14): %d\n", between_double(0.5, 5.5, 3.14));
    printf("Double bounds check (0.5, 5.5, 6.28): %d\n", between_double(0.5, 5.5, 6.28));

    // Test character bounds checking
    printf("Character bounds check ('a', 'z', 'm'): %d\n", between_char('a', 'z', 'm'));
    printf("Character bounds check ('a', 'z', 'A'): %d\n", between_char('a', 'z', 'A'));

    return 0;
}

Key points about this implementation:
We include "macros.h" to use the TRUE and FALSE macros defined earlier.
Three separate functions are created for integer, double, and character bounds checking.
Each function returns TRUE if the value is within the bounds (inclusive) and FALSE otherwise.
The main function tests each of these functions with both in-bounds and out-of-bounds values.
The ternary operator (?:) is used for concise conditional return statements.
To compile and run this program:
Ensure that macros.h is in the same directory as bounds.c.
Compile the program: gcc -Wall -pedantic -ansi -Werror bounds.c -o bounds
Run the program: ./bounds
The output should demonstrate the correct functioning of all three bounds checking functions for various inputs.

4. Functions to macro
Add to macros.h
#define BETWEEN(low, high, value) (((value) >= (low) && (value) <= (high)) ? TRUE : FALSE)

bounds.c modified
#include <stdio.h>
#include "macros.h"

int main(void) {
    // Test integer bounds checking
    printf("Integer bounds check (1, 10, 5): %d\n", BETWEEN(1, 10, 5));
    printf("Integer bounds check (1, 10, 15): %d\n", BETWEEN(1, 10, 15));

    // Test double bounds checking
    printf("Double bounds check (0.5, 5.5, 3.14): %d\n", BETWEEN(0.5, 5.5, 3.14));
    printf("Double bounds check (0.5, 5.5, 6.28): %d\n", BETWEEN(0.5, 5.5, 6.28));

    // Test character bounds checking
    printf("Character bounds check ('a', 'z', 'm'): %d\n", BETWEEN('a', 'z', 'm'));
    printf("Character bounds check ('a', 'z', 'A'): %d\n", BETWEEN('a', 'z', 'A'));

    return 0;
}
We've removed the three separate functions (between_int, between_double, and between_char) as they're no longer needed.
The BETWEEN macro is used directly in the printf statements, replacing the function calls.
The macro works for all three data types (int, double, and char) without any need for type-specific functions.
The macro name is in ALL_CAPS, following the naming convention for macros.

gcc -Wall -pedantic -ansi -Werror bounds.c -o bounds

5. Multiple C files

In powers.c, keep only the power_of_two() function and remove the main() function:

unsigned int power_of_two(void) {
    static unsigned int power = 1;
    power *= 2;
    return power;
}

Modify bounds.c
#include <stdio.h>
#include "macros.h"

// Function declaration for power_of_two
unsigned int power_of_two(void);

int main(void) {
    int input;
    int i;

    do {
        printf("Enter a number between 1 and 31: ");
        scanf("%d", &input);
    } while (!BETWEEN(1, 31, input));

    printf("Powers of 2:\n");
    for (i = 0; i < input; i++) {
        printf("%d: %u\n", i + 1, power_of_two());
    }

    return 0;
}

Key points about this implementation:
We include the function declaration for power_of_two() in bounds.c.
We use a do-while loop to ensure valid input between 1 and 31, using the BETWEEN macro.
We call power_of_two() the number of times specified by the user input.

Compile bounds.c:
gcc -Wall -pedantic -ansi -Werror -c bounds.c

Compile powers.c:
gcc -Wall -pedantic -ansi -Werror -c powers.c

Link the object files:
gcc bounds.o powers.o -o bounds

6. Conditional Compilation
Modify powers.c
#include <stdio.h>

unsigned int power_of_two(void) {
    static unsigned int power = 1;
    power *= 2;

    #ifdef DEBUG
    printf("Debug: Current power value is %u\n", power);
    #endif

    return power;
}

Key points about this implementation:
We use the #ifdef DEBUG preprocessor directive to conditionally include the debug print statement.
The debug print will only be compiled and executed if DEBUG is defined during compilation.
The rest of the function remains unchanged.

Debug prints
gcc -Wall -pedantic -ansi -Werror -c bounds.c
gcc -Wall -pedantic -ansi -Werror -c powers.c -D DEBUG=1
gcc bounds.o powers.o -o bounds

No debug
gcc -Wall -pedantic -ansi -Werror -c bounds.c
gcc -Wall -pedantic -ansi -Werror -c powers.c
gcc bounds.o powers.o -o bounds

7. Makefiles
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -pedantic -ansi -Werror

# Source files
SOURCES = bounds.c powers.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Executable name
EXECUTABLE = bounds

# Default target
all: $(EXECUTABLE)

# Link object files to create executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Phony targets
.PHONY: all clean

Defines variables for the compiler (CC), compiler flags (CFLAGS), source files (SOURCES), object files (OBJECTS), and the executable name (EXECUTABLE).
The default target all depends on the executable.
Rules for linking object files and compiling source files are provided.
A clean rule is included to remove object files and the executable.

Adding debug 
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -pedantic -ansi -Werror

# Debug flags (empty by default)
DEBUG_FLAGS =

# Source files
SOURCES = bounds.c powers.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Executable name
EXECUTABLE = bounds

# Default target
all: $(EXECUTABLE)

# Debug target
debug: DEBUG_FLAGS += -D DEBUG=1
debug: $(EXECUTABLE)

# Link object files to create executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Phony targets
.PHONY: all debug clean

Key changes:
Added a DEBUG_FLAGS variable.
Created a debug target that adds the -D DEBUG=1 flag to DEBUG_FLAGS.
Modified the compilation rule to include DEBUG_FLAGS.
Now you can use the Makefile as follows:
For normal compilation: make
For compilation with DEBUG enabled: make debug
To clean up: make clean