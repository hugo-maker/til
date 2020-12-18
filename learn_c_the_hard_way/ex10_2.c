#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("ERROR: You need at least two argument.\n");
    // this is how you abort a program
    return 1;
  }

  int i = 1;
  int j = 0;

  for (i = 1; i < argc; i++)
  {
    for (j = 0; argv[i][j] != '\0'; j++)
    {
      char letter = toupper(argv[i][j]);

      switch (letter)
      {
        case 'A':
          printf("%d: 'A'\n", j);
          break;
        case 'E':
          printf("%d: 'E'\n", j);
          break;
        case 'I':
          printf("%d: 'I'\n", j);
          break;
        case 'O':
          printf("%d: 'O'\n", j);
          break;
        case 'U':
          printf("%d: 'U'\n", j);
          break;
        case 'Y':
          if (j > 2)
          {
            // it's only sometimes Y
            printf("%d: 'Y'\n", j);
          }
          break;
        default:
          printf("%d: %c is not a vowel.\n", j, letter);
      }
    }
  }

  return 0;
}
