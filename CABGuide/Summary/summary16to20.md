# Summary of Chapter 16 to 20

## break and continue

- Don't use break or continue without a preceding if statement of some kind

## switch statement

switch (expression)
{
    case (expression1); {one or more C statements;}
    case (expression2); {one or more C statements;}
    case (expression3); {one or more C statements;}
    default; {one or more C statements;}
}

- Use switch to code menu selections and other types of applications that need to select from a variety of values
- Don't use float and double values in switch statement
- Don't use nested if statements when a switch statement will work instead

## putchar() and getchar()

- input and output single characters
- Use a standalone getchar() to get rid of the Enter keypress if you don't want to capture it
- Use getch() to get unbuffered single characters as soon as the user types them
- Use an int variable with character Input Output function (Don't use character variables)
- Use putch() with getch() if you want to echo what the user types

## built-in chapter-testing and chapter-mapping functions

- Use gets() and puts() to print strings
- Use gets() when you must get strings that might contains spaces
- Use strcat() to merge two string
- Make sure that the first character array can hold the strings after they are merged
- puts() automatically adds a newline to the end of strings

**Caution**

- C11 doesn't support the gets() function, so instead of it, use the fgets() function
- fgets() recieves the Enter keypress
- I could not find the way of getting rid or Enter keypress 

## built-in math functions

- floor(), ceil(), and fabs(), convert one number to another
- Be sure to seed the random number generator with the time of day if you want random numbers with rand() to be different every time you run a program
- Don't use an integer variable to hold the return value from these math functions
