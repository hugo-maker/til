# Summary of Chapter 29 to 32

## Random Files

- Use a plus sigh in the fopen() mode string if you need to change data in a file
- fseek() moves a file pointer all around a random file so that you can read or write from the beginning, middle, or end

## Functions

- Structured Programming: breaking programs into smaller functions
- The only thing main() does is control the other functions by showing an overview of how they are called

## Local and Global Variables

- Most of the cases, local is safer
- A variable is global only if you define it before a function name
- A variable is local only if you define it after an opening brace.
- Don't define a global variable in the middle of a program
- Don't use global variables too much
- Use locals as much as you can

## Passing variables to the functions

- Pass variables by value if you want their values protected from the called function
- Pass variables by address if you want their values cahnged by the called function
- Place an & before non-array variables you want to pass by address
- If you want to pass arrays, you don't need to put &
- Don't pass an array variable by value

## Returning Data

- Place the return data type before a function name that returns a value
- In the calling function, do something with athe return value, print it or assign it to something
- Use void as the return data type or in the parameter list if you neither return nor pass values to a function
- Don't return more than one value from a function
- If you want to return a non-integer, you have to prototype
