#include "lcthw/vl_get_random_chars_array.h"
#include "lcthw/dbg.h"

int my_rand(int min, int max)
{
  static int flag;
  if (flag == 0)
  {
    srand((unsigned int)time(NULL));
    rand();
    flag = 1;
  }
  int ret = min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
  return ret;
}

char get_random_char_lower(void)
{
  const char CHARS[] = "abcdefghijklmnopqrstuvwxyz";
  int index = my_rand(0, (strlen(CHARS)) - 1);
  char c = CHARS[index];

  return c;
}

void get_random_chars_lower(int length, char *result)
{
  int i = 0;
  for (i = 0; i < length; i++)
  {
    result[i] = get_random_char_lower();
  }
}

void fill_values(char **values, int num_values)
{
  int i = 0;
  int length = 5;
  for (i = 0; i < num_values; i++)
  {
    values[i] = malloc(sizeof(char) * (length + 1));
    check_mem(values[i]);
    get_random_chars_lower(length, values[i]);
  }

error:
  return;
}
