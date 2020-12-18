#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "my_strncpy.h"

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address
{
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

FILE *file;
struct Address rows[MAX_ROWS];

void Database_close(void)
{
  if (file)
  {
    fclose(file);
  }
}

void die(const char *message)
{
  if (errno)
  {
    perror(message);
  }
  else
  {
    printf("ERROR: %s\n", message);
  }

  Database_close();
  exit(1);
}

void Address_print(struct Address *addr)
{
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(void)
{
  assert(file);

  for (int i = 0; i < MAX_ROWS; i++)
  {
    if (fread(&(rows[i].id), sizeof(int), 1, file) != 1)
    {
      die("Failed to load id.");
    }
    if (fread(&(rows[i].set), sizeof(int), 1, file) != 1)
    {
      die("Failed to load set.");
    }
    if (fread(&(rows[i].name), MAX_DATA, 1, file) != 1)
    {
      die("Failed to load name.");
    }
    if (fread(&(rows[i].email), MAX_DATA, 1, file) != 1)
    {
      die("Failed to load email.");
    }
  }
}

void Database_open(const char *filename, char mode)
{
  if (mode == 'c')
  {
    file = fopen(filename, "w");
  }
  else
  {
    file = fopen(filename, "r+");
    if (file)
    {
      Database_load();
    }
  }

  if (!file)
  {
    die("Failed to open the file.");
  }
}

void Database_create(void)
{
  for (int i = 0; i < MAX_ROWS; i++)
  {
    struct Address addr = {.id = i, .set = 0};
    rows[i] = addr;
  }
}

void Database_write(void)
{
  rewind(file);

  for (int i = 0; i < MAX_ROWS; i++)
  {
    if (fwrite(&((rows[i]).id), sizeof(int), 1, file) != 1)
    {
      die("Failed to write id.");
    }
    if (fwrite(&((rows[i]).set), sizeof(int), 1, file) != 1)
    {
      die("Failed to write set.");
    }
    if (fwrite(rows[i].name, MAX_DATA, 1, file) != 1)
    {
      die("Failed to write name.");
    }
    if (fwrite(rows[i].email, MAX_DATA, 1, file) != 1)
    {
      die("Failed to write email.");
    }
  }

  fflush(file);
}

void Database_set(int id, char *name, char *email)
{
  struct Address *addr = &rows[id];
  if (addr->set) // Invalid read of size 4 /main:323 Address 0x4a53284 is 28 bytes before an unallocated block of size 4,193,600 in arena "client"
  {
    die("Already set, delete it first.");
  }

  addr->set = 1; // Invalid write of size 4 /main:323 Address 0x4a53284 is 28 bytes before an unallocated block of size 4,193,600 in arena "client"

  my_strncpy(addr->name, name, MAX_DATA);
  my_strncpy(addr->email, email, MAX_DATA);
}

void Database_get(int id)
{
  struct Address *addr = &rows[id];
  if (addr->set)
  {
    Address_print(addr);
  }
  else
  {
    die("ID is not set.");
  }
}

void Database_delete(int id)
{
  struct Address addr = {.id = id, .set = 0};
  rows[id] = addr;
}

void Database_list(void)
{
  for (int i = 0; i < MAX_ROWS; i++)
  {
    if (rows[i].set)
    {
      Address_print(&rows[i]);
    }
  }
}

void Database_find(char *keyword)
{
  int i = 0;
  int count = 0;

  while (i < MAX_ROWS)
  {
    while (i < MAX_ROWS)
    {
      if (rows[i].set == 1)
      {
        if (strstr(rows[i].name, keyword) != NULL || strstr(rows[i].email, keyword) != NULL)
        {
          break;
        }
      }
      i++;
    }

    if (i >= MAX_ROWS)
    {
      break;
    }

    Address_print(&rows[i]);
    count++;
    i++;
  }

  if (count == 0)
  {
    printf("Try some other words.\n");
  }
}

/****************************************************************************/
int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    die("USAGE: ex17 <dbfile> <action> [action params]");
  }

  int id = 0;
  if (argc > 3)
  {
    id = atoi(argv[3]);
  }

  char *filename = argv[1];
  char action = argv[2][0];
  Database_open(filename, action);

  switch (action)
  {
    case 'c':
    {
      Database_create();
      Database_write();
      break;
    }
    case 'g':
    {
      if (argc != 4)
      {
        die("Need an id to get.");
      }
      Database_get(id);
      break;
    }
    case 's':
    {
      if (argc != 6)
      {
        die("Need id, name, email to set.");
      }
      Database_set(id, argv[4], argv[5]);
      Database_write();
      break;
    }
    case 'd':
    {
      if (argc != 4)
      {
        die("Need id to delete.");
      }
      Database_delete(id);
      Database_write();
      break;
    }
    case 'l':
    {
      Database_list();
      break;
    }
    case 'f':
    {
      if (argc != 4)
      {
        die("Need keyword to search.");
      }
      Database_find(argv[3]);
      break;
    }
    default:
    {
      die("Invalid action: c=create, g=get, s=set, d=delete, l=list, f=find");
    }
  }

  Database_close();
  return 0;
}
