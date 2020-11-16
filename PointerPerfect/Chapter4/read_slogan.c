#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLOGAN_MAX_LEN (1024)

void read_slogan(FILE *fp, char **slogan)
{
  char buf[1024];
  int slogan_len;
  int i;

  for (i = 0; i < 7; i++)
  {
    fgets(buf, SLOGAN_MAX_LEN, fp);

    slogan_len = strlen(buf);
    if (buf[slogan_len - 1] != '\n')
    {
      fprintf(stderr, "This slogan is too long!\n");
      exit(1);
    }

    // delete a newline character
    buf[slogan_len - 1] = '\0';

    // allocate the area of one slogan
    slogan[i] = malloc(sizeof(char) * (slogan_len));

    // copy a slogan
    strcpy(slogan[i], buf);

  }
}

int main(void)
{
  char *slogan[7];
  int i;

  read_slogan(stdin, slogan);

  // print the slogans read from user input
  for (i = 0; i < 7; i++)
  {
    printf("%s\n", slogan[i]);
  }
  
  return 0;
}
