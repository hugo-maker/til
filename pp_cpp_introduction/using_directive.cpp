#include <cstdio>

int main()
{
  using namespace std;

  if (FILE *fp = fopen("text.txt", "w"))
  {
    for (int i = 0; i < 10; ++i)
    {
      fprintf(fp, "%d\n", i);
    }
    fclose(fp);
  }
} // using namespace stdの有効範囲
