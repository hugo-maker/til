#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "dbg.h"

#define MAX_DATA 100

int read_string(char **out_string, int max_buffer)
{
  *out_string = calloc(1, max_buffer + 1);
  check_mem(*out_string);

  char *result = fgets(*out_string, max_buffer, stdin);
  check(result != NULL, "Input error.");

  return 0;
  
error:
  if (*out_string)
  {
    free(*out_string);
  }
  *out_string = NULL;
  return -1;
}

int read_int(int *out_int)
{
  char *input = NULL;
  int rc = read_string(&input, MAX_DATA);
  check(rc == 0, "Failed to read number.");

  *out_int = atoi(input);

  free(input);
  return 0;

error:
  if (input)
  {
    free(input);
  }
  return -1;
}

int read_scan(const char *fmt, ...)
{
  int i = 0;
  int rc = 0;
  int *out_int = NULL;
  char *out_char = NULL;
  char **out_string = NULL;
  int max_buffer = 0;

  va_list argp;
  va_start(argp, fmt);

  for (i = 0; fmt[i] != '\0'; i++)
  {
    if (fmt[i] == '%')
    {
      i++;
      switch (fmt[i])
      {
        case '\0':
        {
          sentinel("Invalid format, you ended with %%.");
          break;
        }
        case 'd':
        {
          out_int = va_arg(argp, int *);
          rc = read_int(out_int);
          check(rc == 0, "Failed to read int.");
          break;
        }
        case 'c':
        {
          out_char = va_arg(argp, char *);
          *out_char = fgetc(stdin);
          break;
        }
        case 's':
        {
          max_buffer = va_arg(argp, int);
          out_string = va_arg(argp, char **);
          rc = read_string(out_string, max_buffer);
          check(rc == 0, "Failed to read string.");
          break;
        }
        default:
        {
          sentinel("Invalid format.");
        }
      }
    }
    else
    {
      fgetc(stdin);
    }

    check(!feof(stdin) && !ferror(stdin), "Input error.");
  }

  va_end(argp);
  return 0;

error:
  va_end(argp);
  return -1;
}

int my_vfprintf(FILE *file, char const *fmt, va_list arg)
{
  int int_temp;
  char char_temp;
  char *string_temp;

  int length = 0;
  char ch = '\0';

  char buffer[512];

  while ((ch) = *fmt++)
  {
    if ('%' == ch)
    {
      switch ((ch) = *fmt++)
      {
        case '\0':
        {
          sentinel("Invalid format, you ended with %%.");
          break;
        }
        case '%':
        {
          fputc('%', file);
          length++;
          break;
        }
        case 'c':
        {
          char_temp = va_arg(arg, int);
          fputc(char_temp, file);
          length++;
          break;
        }
        case 's':
        {
          string_temp = va_arg(arg, char *);
          fputs(string_temp, file);
          length += strlen(string_temp);
          break;
        }
        case 'd':
        {
          int_temp = va_arg(arg, int);
          // itoa(int_temp, buffer, 10); linux doesn't have this function
          sprintf(buffer, "%d", int_temp);
          fputs(buffer, file);
          length += strlen(buffer);
          break;
        }
        default:
        {
          sentinel("Invalid format.");
        }
      }
    }
    else
    {
      putc(ch, file);
      length++;
    }
  }

  return length;
  
error:
  return -1;
}

int my_printf(char const *fmt, ...)
{
  va_list arg;
  int length;

  va_start(arg, fmt);
  length = my_vfprintf(stdout, fmt, arg);
  va_end(arg);
  return length;
}


int main(int argc, char *argv[])
{
  char *first_name = NULL;
  char initial = ' ';
  char *last_name = NULL;
  int age = 0;

  // printf("What is your first name? ");
  my_printf("%s", "What is your first name? ");
  int rc = read_scan("%s", MAX_DATA, &first_name);
  check(rc == 0, "Failed first name.");

  // printf("What is your initial? ");
  my_printf("%s", "What is your initial? ");
  rc = read_scan("%c\n", &initial);
  check(rc == 0, "Failed initial.");

  // printf("What is your last name? ");
  my_printf("%s", "What is your last name? ");
  rc = read_scan("%s", MAX_DATA, &last_name);
  check(rc == 0, "Failed last name.");

  // printf("How old are you? ");
  my_printf("%s", "How old are you? ");
  rc = read_scan("%d", &age);

  /* printf("----- RESULT -----\n");
  printf("First Name: %s", first_name);
  printf("Initial: '%c'\n", initial);
  printf("Last Name: %s", last_name);
  printf("Age: %d\n", age);
  */
  my_printf("%s", "------ RESULT ------\n");
  my_printf("%s%s", "First name: ", first_name);
  my_printf("%s'%c'%c", "Initial: ", initial, '\n');
  my_printf("%s%s", "Last name: ", last_name);
  my_printf("%s%d%c", "Age: ", age, '\n');

  free(first_name);
  free(last_name);
  return 0;

error:
  return -1;
}
