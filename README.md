# # Clang
# Random notes:
### The main function
Doing `void main() {` basically means that the functions returns no data
Where as `int main() {` means that any number returned besides `0` is an error number.
`int main(void) {` void refers to the program not taking any parameters

When `main()` is called by the runtime system, two arguments are actually passed to the function.
• The first argument: `argc` for argument count is an integer that specifies the number of arguments typed in the command line

(The program name also counts as 1, so if we pass only 1 parameter to our program this will be equal to 2)
• The second argument `argv` for argument vector is an array of character pointers (strings)
The first entry in this array is a pointer to the name of the program that is executing and everything after that would be the arguments

```c
int main(int argc, char *argv[]) {
	int numberOfArguments = argc;
	char *argument1 = argv[0];
	char *argument2 = argv[1];

	printf("Number of arguments: %d\n", numberOfArguments);
	printf("Argument 1 is the program name: %s\n", argument1);
	printf("Argument 2 is the command line argument: %s\n", argument1);

	return 0;
}
```

### The C preprocessor
• The preprocessor runs /before/ the program is compiled.
• Preprocessor statements are identified by the presence of the pound sign, `#` which must be the first non-space character sign on the line

In general we can use the preprocessor to:
• create our own constants and macros with the `#define` statement
• build our own library files with the `#include` statement
• make more powerful programs with the conditional `#ifdef`, `#endif`,`#else`, and `#ifndef` statements

Where constants refers to variables that never change their value.

# The `#include` directive
Two ways to include header files in your program
• `#include <Jason.h>` tells the preprocessor to look for the file in one or more standard system directories
• `#include “Jason.h”` tells the preprocessor to first look in the current directory

# Random

### scanf
Some things to remember about `scanf`

• `scanf` returns the number of arguments it successfully reads
• It uses whitespace (newlines, tabs and spaces) to decide how to decide the input into separate fields
• It takes a pointer so you have to precede a `&` to the parameter (unless its a string because this is an array of characters)
• `scanf` is basically the inverse of `printf` (it takes the input as text and converts it to actual values of the correct type eg floating-point numbers)
example:
```c
char str[100];
int i;
printf("Enter a value :");
scanf("%d %s", &i, str);
printf("\nYou entered: %d:::::%s\n", i, str);
```
Reading a double:
```c
double x;
scanf("%lf", &x);
```
• Main issue with `scanf` is that when you read in, you’re only reading in until you see a space. So if you have multiple `scanf`s there is an issue basically that it misses the enter key and then when the next `scanf` runs it will immediately skip that line and its going to read the line feed.
@todo understand this better (is it just that the enter key is read by the next `scanf`  as a new line ?
A very easy way to get around that is right after you do a `scanf` you just call get char and then you call another scanner.

### Format Specifier for specific precision of floats

```c
float x = 3.9993232393;
printf("%2.f", x); // prints 3.99
```

@todo find table of format specifiers

## Variables
• Variables are basically the opposite of constants, they are the type of data that needs to change where as constants never need to change
• A variables is basically a name for an address in memory

## Data types
• The difference between the data types is the amount of memory they occupy and the range of values they hold.
• Depending on your machine the amount of bits per data type might be different *eg an integer might take 32bits on your machine or perhaps it might be stored in 64

### hexadecimal values
To assign a hexadecimal value to an integer, you have to prefix it with `0x`
Eg. `int rgbColor = 0xFFEE0D`

### float values
The following are valid assignments for the float type
• `float x = 3.;`
• `float x = -.0001;`
• `float x = 1.7e4;` // scientific notation 1.7 * (10 to the power 4) = 17000.0

### double values
Basically they are the same as float but used when the range provided by a float is not sufficient. (Can store twice as many significant digits so they have roughly double the precision)

• All floating-point constants are taken as double values by the C compiler
• To explicitly express a float constant, append either an `f` or `F` to the end of the number eg `12.5f`

### More specified versions for int, float, double
• C provides three adjective keywords to modify the basic integer type, these are `short`, `long`, and `unsigned`
• these can also be used by themselves

The type short for example may be used when the program needs a lot of memory and the amount of available memory is limited
So basically a `short int` will use less memory than an `int`

You can also do `long long int`
To do a constant of `long int` you have to suffix with `L` or `l` eg `long int someVar = 131071100L`
For a `long double` you would also use the letter `L` or `l`
You can also do suffixes for `short`
`unsigned` don’t contains negative values
You may also use `signed` but this is just to intent more explicitly that your number can also have negative values

### Enum
Enum is basically a data type that allows the developer to define a variable and specify the valid values that could be stored in that variable
• Defining an enum type `enum primaryColor {red, yellow, blue};`
• Creating two variables that must be of that type `enum primaryColor myColor, gregsColor;`
• assigning a value to one go these variables `myColor = red;`
Under the hood /the compiler treats enumeration identifiers as integer constants./ First name in list = 0.
So if you were to print `myColor` the value that would be printed would be `0` because red is the first enumeration identifier in our primaryColor enum type.

Alternatively /we can specific integer values to specific enumeration identifiers./
`enum direction { up, down, left = 10, right}`
So in that case `// up=0, down=1, left=11 and right=12`

Another thing to keep in mind is that assigning any arbitrary int to a variable of an enum type will not throw an error since enums are represented by the int type

Also when defining an enum variable without initialising it, this variable is going to be equal to 0 (@todo check if the default value is the same if the 1st enumeration identifier is mapped to another int)

### Char
Char represents a /single character/. We use /single quotes/ for this data type eg `'6'` or `';'`. If you use double quotes the compiler will think that you are using a string so for example `char someChar; someChar = "T"` would error.
Characters cal also be represented as numbers in the ASCII table, so even though it doesn’t make lots of sense you could do `unsigned char` and that would basically tell the compiler that your character is one of those that are represented by a positive number in the ASCII table.
`char grade = 65 /* OK for ASCII, but poor style */`

#### Escape Characters
Escape characters are special characters in C that represent actions.
`char x = '\n'; // represents a new line`
There is a big number of escape characters (@todo find the table online and link it here)

### The boolean data type
• For compilers using the /C89 standard/:
You can use `_Bool` to store just the values `0` or `1`
Eg `_Bool boolVar = 1` is valid
• For compilers using the /C99 standard/:
You have to `#include <stdbool.h>` and then you can do
`bool boolVar = true`

# Operators
• Operators are functions that use a symbolic name.
• `Operators` are the actual symbol where as `operands` are the arguments to that symbol.
• A logical operator (sometimes called boolean operator) is an operator that returns a boolean result.
• An arithmetic operator is a mathematical function that takes two operands and performs a calculation on them.
• Other operators include assignment(equals operator), relational (<.>,!=), bitwise (<<,>>,~)
• % (Modulus Operator and remainder of after an integer devision)
Eg	`20 % 12 = 8`
• `C *= A` is equivalent to `C = C * A`
• `C /= A` is equivalent to `C = C / A`
• `C %= A` is equivalent to `C = C % A`
• `C <<= 2` is equivalent to `C = C << 2` (Left shift AND assignment operator)
• `C >>= 2` is equivalent to `C = C >> 2` (Right shift AND assignment operator)
• `C &= 2` is equivalent to `C = C & 2` (Bitwise AND assignment operator)
• `C ^= 2` is equivalent to `C = C ^ 2` (Bitwise XOR and assignment operator)
• `C |= 2` is equivalent to `C = C | 2` (Bitwise OR and assignment operator)
## Bitwise Operators and Binary numbers
Why would we use binary numbers?  A binary number is a number that includes only ones and zeros. Basically we can use individual bits to store data that involve one of two choices. That makes it possible so that we can store a substantial amount of information with just a few bits.
For example you could use a single integer variable to store several characteristics of a person:
• store whether the person is male or female with 1 bit
• use two other bits to specify whether the person can speak French or German 
• another bit to record whether the person’s salary is $50,000 or more
In just 4 bits you have a substantial set of data recorded

### More about Binary Numbers
• each position for a binary value has a value
• for each digit, multiply the digit by its position value
• add up all of the products to get the final result
• in general the “position values” in binary values are the powers of two


## Expressions and Statements
For the most part: statements end in semicolons (where as expressions don’t). And expressions return values (statements don’t necessarily).
• An expression consists of a combination of operators and operands 
	• operands are what an operator operates on
	• operands can be constants, variables, or combinations of the two
	• every expression has a value
Examples of expressions
```c
/*
-6
4+21
a*(b + c/d)/20
q = 5*2
x = ++q % 3
q > 3
*/
```
• Statements form the basic program steps of C, and most statements are constructed from expressions.
• Statements are the building blocks of a program (declaration)
		• A program is a series of statements with special syntax ending with a semicolon (simple statements)
		• A complete instruction to the computer
Examples:
```c
int Jason; // Declaration statement;
Jason = 5; // Assignment statement;
printf("Jason") // Function call statement;
while (Jason < 20) Jason = Jason + 1; // Structure statement
return 0; // Return statement
```
• C considers any expression to be a statement if you append a semicolon (Expression Statements)
	• So `8;` or `3-4;` are perfectly valid in C
### Compound Statements
Two or more statements grouped together by enclosing them in brace (block) Eg.
```c
int index = 0;
while (index < 10)
{ // compound statement start
	printf("Hello"); 
	index = index + 1;
} // compound statement ends
```
a block of code === multiple statements === compound statement