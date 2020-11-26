#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "my_strncpy.h"

struct Address
{
  int id;
  int set;
  int phonenumber;
  char *name;
  char *email;
};

struct Database
{
  int MAX_ROWS;
  int MAX_DATA;
  struct Address *rows;
};

struct Connection
{
  FILE *file;
  struct Database *db;
};

void Database_close(struct Connection *conn)
{
  if (conn)
  {
    // free name and email
    for(int i = 0; i < conn->db->MAX_ROWS; i++)
    {
      struct Address *row = &conn->db->rows[i];

      if (row->name)
      {
        free(row->name);
      }
      if (row->email)
      {
        free(row->email);
      }
    }

    // free rows and db and file
    if (conn->db->rows)
    {
      free(conn->db->rows);
    }
    if (conn->db)
    {
      free(conn->db);
    }
    if (conn->file)
    {
      fclose(conn->file);
    }

    free(conn);
  }
}

void die_oneTimeOnly(const char *message)
{
  if (errno)
  {
    perror(message);
  }
  else
  {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

void die(const char *message, struct Connection *conn)
{
  if (errno) 
  {
    perror(message);
  }
  else 
  {
    printf("ERROR: %s\n", message);
  }

  Database_close(conn);
  exit(1);
}

void Address_print(struct Address *addr)
{
  printf("%d %d %s %s\n", addr->id, addr->phonenumber, addr->name, addr->email);
}

void Database_load(struct Connection *conn) // read the data from conn->file and storing it at conn->db.
{
  assert(conn->db && conn->file);

  if (fread(conn->db, sizeof(struct Database), 1, conn->file) != 1)
  {
    die("Failed to load database!", conn);
  }

  conn->db->rows = (struct Address *)malloc(sizeof(struct Address) * conn->db->MAX_ROWS);
    
  for (int i = 0; i < conn->db->MAX_ROWS; i++)
  {
    struct Address *row = &conn->db->rows[i];

    if (fread(&row->id, sizeof(int), 1, conn->file) != 1)
    {
      die("Failed to load id!", conn);
    }
    if (fread(&row->set, sizeof(int), 1, conn->file) != 1)
    {
      die("Failed to load set!", conn);
    }
    if (fread(&row->phonenumber, sizeof(int), 1, conn->file) != 1)
    {
      die("Failed to load phonenumber!", conn);
    }

    row->name = malloc(conn->db->MAX_DATA);
    row->email = malloc(conn->db->MAX_DATA);
    if (fread(row->name, conn->db->MAX_DATA, 1, conn->file) != 1)
    {
      die("Failed to load name!", conn);
    }
    if (fread(row->email, conn->db->MAX_DATA, 1, conn->file) != 1)
    {
      die("Failed to load email!", conn);
    }
  }
}

struct Connection *Database_open(const char *filename, char mode)
{
  struct Connection *conn = malloc(sizeof(struct Connection));
  if (!conn) // conn == NULL if malloc() failed to allocate memory, malloc() returns NULL
  {
    die("Memory error!: Failed to allocate memory of struct Connection *conn.", conn);
  }

  conn->db = malloc(sizeof(struct Database));
  if (!conn->db)
  {
    die("Memory error!: Failed to allocate memory of conn->db", conn);
  }
  
  // mode is action and action is command line parameter, argv[2][0]
  if (mode == 'c') // case action is c(=create)
  {
    conn->file = fopen(filename, "w"); //Truncate file to zero length or create text file for writing. The stream is positioned at the beginning of the file.
  }
  else // case action is g(=get), s(set), d(delete), l(list). In this case, file must have already existed. Thus, fopen(filename, "r+") is belowed.
  {
    conn->file = fopen(filename, "r+"); // if filename doesn't exist, function fails.
    if (conn->file)
    {
      // storing the 1 item of data(each size sizeof(struct Database)), which read from the conn->file, at conn->db.
      Database_load(conn);
    }
  }

  if (!conn->file) // if conn->file is NULL (In case fopen() failed)
  {
    die("Failed to open the file!", conn);
  }

  return conn;
}

void Database_create(struct Connection *conn)
{
  printf("MAX_ROWS: ");
  scanf("%d", &conn->db->MAX_ROWS);
  if (conn->db->MAX_ROWS <= 0)
  {
    die("MAX_ROWS must be positive!", conn);
  }

  printf("MAX_DATA: ");
  scanf("%d", &conn->db->MAX_DATA);
  if (conn->db->MAX_DATA <= 0)
  {
    die("MAX_DATA must be positive!", conn);
  }

  conn->db->rows = (struct Address *)malloc(sizeof(struct Address) * conn->db->MAX_ROWS);

  for (int i = 0; i < conn->db->MAX_ROWS; i++)
  {
    /*
    struct Address addr;
    addr.id = i;
    addr.set = 0;
    addr.name = (char *)malloc(conn->db->MAX_DATA);
    addr.email = (char *)malloc(conn->db->MAX_DATA);
    */
    char *a = (char *)malloc(conn->db->MAX_DATA);
    memset(a, 0, conn->db->MAX_DATA);
    char *b = (char *)malloc(conn->db->MAX_DATA);
    memset(b, 0, conn->db->MAX_DATA);

    struct Address addr = {.id = i, .set = 0, .phonenumber = 0, .name = a, .email = b};

    conn->db->rows[i] = addr; 
  }
}


void Database_write(struct Connection *conn)
{
  rewind(conn->file);

  if (fwrite(conn->db, sizeof(struct Database), 1, conn->file) != 1)
  {
    die("Failed to write database!", conn);
  }

  for (int i = 0; i < conn->db->MAX_ROWS; i++)
  {
    if (fwrite(&((conn->db->rows[i]).id), sizeof(int), 1, conn->file) != 1)
    {
      die("Failed to write id!", conn);
    }
    if (fwrite(&((conn->db->rows[i]).set), sizeof(int), 1, conn->file) != 1)
    {
      die("Failed to write set!", conn);
    }
    if (fwrite(&((conn->db->rows[i]).phonenumber), sizeof(int), 1, conn->file) != 1)
    {
      die("Failed to write phonenumber!", conn);
    }
    if (fwrite((conn->db->rows[i]).name, conn->db->MAX_DATA, 1, conn->file) != 1)
    {
      die("Failed to write name!", conn);
    }
    if (fwrite((conn->db->rows[i]).email, conn->db->MAX_DATA, 1, conn->file) != 1)
    {
      die("Failed to write email!", conn);
    }
  }

  fflush(conn->file);
}

void Database_set(struct Connection *conn, int id, int phonenumber, char *name, char *email)
{
  struct Address *addr = &conn->db->rows[id];
  if (addr->set)
  {
    die("Already set, delete it first!", conn);
  }

  addr->set = 1;
  addr->phonenumber = phonenumber;

  my_strncpy(addr->name, name, conn->db->MAX_DATA);
  my_strncpy(addr->email, email, conn->db->MAX_DATA);
}

void Database_get(struct Connection *conn, int id)
{
  struct Address *addr = &conn->db->rows[id];

  if (addr->set)
  {
    Address_print(addr);
  }
  else
  {
    die("ID is not set!", conn);
  }
}

void Database_delete(struct Connection *conn, int id)
{
  char *a = (char *)malloc(conn->db->MAX_DATA);
  char *b = (char *)malloc(conn->db->MAX_DATA);

  free(conn->db->rows[id].name);
  free(conn->db->rows[id].email);

  struct Address addr = {.id = id, .set = 0, .phonenumber = 0, .name = a, .email = b};
  conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
  for (int i = 0; i < conn->db->MAX_ROWS; i++)
  {
    if (conn->db->rows[i].set)
    {
      Address_print(&(conn->db->rows[i]));
    }
  }
}

void Database_find(struct Connection *conn, char *keyword)
{
  int i = 0;
  int count = 0;
  int input_phonenumber = atoi(keyword);

  while (i < conn->db->MAX_ROWS)
  {
    while (i < conn->db->MAX_ROWS)
    {
      if (conn->db->rows[i].set == 1)
      {
        if (strstr(conn->db->rows[i].name, keyword) != NULL || strstr(conn->db->rows[i].email, keyword) != NULL)
        {
          break;
        }
        else if (input_phonenumber == conn->db->rows[i].phonenumber)
        {
          break;
        }
      }
      i++;
    }

    if (i >= conn->db->MAX_ROWS)
    {
      break;
    }

    Address_print(&(conn->db->rows[i]));
    count++;
    i++;
  }

  if (count == 0)
  {
    printf("Try some other words\n");
  }
}
/**************************************************************************************************************************/

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    die_oneTimeOnly("USAGE: ex17 <dbfile> <action> [action params]");
  }

  int id = 0;
  if (argc > 3)
  {
    id = atoi(argv[3]);
  }
  int phonenumber = 0;
  if (argc == 7)
  {
    phonenumber = atoi(argv[4]);
  }

  char *filename = argv[1];
  char action = argv[2][0];
  struct Connection *conn = Database_open(filename, action);

  switch (action)
  {
    case 'c': // case 'create'
    {
      Database_create(conn);
      Database_write(conn);
      break;
    }
    case 'g': // case 'get'
    {
      if (argc != 4)
      {
        die("Need an id to get!", conn);
      }
      Database_get(conn, id);
      break;
    }
    case 's': // case 'set'
    {
      if (argc != 7)
      {
        die("Need id, phonenumber, name, email to set!", conn);
      }

      Database_set(conn, id, phonenumber, argv[5], argv[6]);
      Database_write(conn);
      break;
    }
    case 'd': // case 'delete'
    {
      if (argc != 4)
      {
        die("Need id to delete!", conn);
      }
      Database_delete(conn, id);
      Database_write(conn);
      break;
    }
    case 'l': // case 'list'
    {
      Database_list(conn);
      break;
    }
    case 'f':
    {
      if (argc != 4)
      {
        die("Need keyword to search.", conn);
      }
      Database_find(conn, argv[3]);
      break;
    }
    default:
    {
      die("Invalid action: c=create, g=get, s=set, d=del, l=list, f=find", conn);
    }
  }

  Database_close(conn);
  return 0;
}
