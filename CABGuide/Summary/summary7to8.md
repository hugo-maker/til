# Summary of Chapter7 to 8

## Includeing files

- \#include \<filename\>: include compiler-supplied header files
- \#include \"filename\": include your own header files

## Defining Constants

- Constants are not variables
- \#define tells C that every place in the program that the CONSTANT appears, replace it with the constantDefinition
- Use uppercase letters for the defined constant name(It helps you to distinguish constant names from regular variable names)

## scanf() Function

- scanf(controlString [, data]);
- A printf() before a scanf() sends a prompt to the user(The printf() requests the data form the user, and the scanf() gets the data that the user types)
- Put an ampersand(&) before nonarray variables in a scanf()
- Add a leading space before the first control string character (like " %d") to ensure correct character input
