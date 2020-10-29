// Absolute Beginner's Guide to C, 3rd Edition Kindle
// Chapter4 sample code
#include <stdio.h>

int main(void)
{
  // These three lines show you how to use the most popular Escape Sequences
  printf("test a\ttest b\ttest c\n");
  printf("\nMy computer\'s Beep sounds Like This: \a!\n");
  printf("\"Let\'z\bs fix that typo and then show two backslash ");
  // If the number of backslash is even, compiler returns error.
  printf("characters \\\\\" she said\n");

  return 0;
}
