# Summary of Chapter 25 to 28

## Pointers and Arrays

- Use character pointers to assgn string literals directly
- Use either array subscript notation or pointer dereferencing to access array and pointer values
- Use fgets() instead of gets() (gets() function might cause memory overflow!)

## Heap

- Use malloc() and free() to allocate and reallocate heap memory
- Tell malloc() the correct size of each allocation by using the sizeof() operator inside malloc()'s prarentheses
- Allocate only the pointer variables at the top of your function
- If you must track several chunks of heap memory, use an array of pointers
- Check to make sure malloc() worked properly (malloc() returns a 0 if the allocation fails)
- Using the heap lets you use memory resources efficiently

## Structure

- Define structures when you want to group items of different data types
- Declare a structure before defining a surucuture variable
- Use the dot operator to access individual data members within a structure variable
- Use the -> (the structure pointer oprator) to access individual data members within a structure pointed to by a pointer variable
- Don't use member names as variables

## File

- Open a file with fopen() before you use the file
- Don't forget to close the file with fclose() when you're done
- Don't read from a file without checking for feof()
- Use the file pointer that you connected to the file with fopen()
- file pointer goes at the beginning of fprintf()
- file pointer goes at the end of fputs()'s argument list
