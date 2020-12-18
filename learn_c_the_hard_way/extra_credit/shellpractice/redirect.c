#include <stdio.h>

int main(void)
{
  FILE *fd1 = stdout;
  FILE *fd2 = stderr;

  fprintf(fd1, "stdout_1\n");
  fprintf(fd2, "stdout_1\n");

  // redirect (> file)
  fd1 = fopen("./file.txt", "w");

  fprintf(fd1, "stdout_2\n");
  fprintf(fd2, "stdout_2\n");

  fd2 = fd1;

  fprintf(fd1, "stdout_3\n");
  fprintf(fd2, "stdout_3\n");

  fclose(fd1);
  if (fd1 != fd2)
  {
    fclose(fd2);
  }

  return 0;
}
