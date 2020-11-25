#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "my_strncpy.h"

static int MAX_DATA;
static int MAX_ROWS;
static int rc;

struct Address
{
  int id;
  int set;
  char *name;
  char *email;
};

struct Database
{
  int MAX_DATA;
  int MAX_ROWS;
  struct Address *rows;
};

struct Connection
{
  FILE *file;
  struct Database *db;
};

// Prototype declaration
void Database_close(struct Connection *conn);

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
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn) // read the data from conn->file and storing it at conn->db.
{
  conn->db->rows = (struct Address*)malloc(MAX_ROWS * sizeof(struct Address));
  //conn->db->rows = (struct Address*)malloc(sizeof(struct Address) * conn->db->MAX_ROWS);
    
  int i = 0;
  for (i = 0; i < MAX_ROWS; i++)
  {
    rc = fread(&conn->db->rows[i], sizeof(struct Address), 1, conn->file);
    if (rc != 1)
    {
      die("Failed to load rows!", conn);
    }

    conn->db->rows[i].name = malloc(MAX_DATA);
    conn->db->rows[i].email = malloc(MAX_DATA);

    rc = fread(&((conn->db->rows[i]).name), sizeof(char), MAX_DATA, conn->file);
    if (rc != MAX_DATA)
    {
      die("Failed to load name!", conn);
    }

    rc = fread(&((conn->db->rows[i]).email), sizeof(char), MAX_DATA, conn->file);
    if (rc != MAX_DATA)
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
    die("Memory error!", conn);
  }

  conn->db = malloc(sizeof(struct Database));
  if (!conn->db)
  {
    die("Memory error!", conn);
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

void Database_close(struct Connection *conn)
{
  int i = 0;
  struct Address *cur_row = NULL; // current row use for free name and email data one by one.

  if (conn)
  {
    if (conn->file)
    {
      fclose(conn->file);
    }
    
    if (conn->db)
    {
      if (conn->db->rows)
      {
        for(i = 0; i < conn->db->MAX_ROWS; i++)
        {
          cur_row = &conn->db->rows[i];
          if (cur_row)
          {
            free(cur_row->name);
            free(cur_row->email);
          }
        }
        free(conn->db->rows);
      }
      free(conn->db);
    }
    free(conn);
  }
}

/* have to rewrite like Database_load to accept dynamic rows */
void Database_write(struct Connection *conn)
{
  rewind(conn->file);

  int i = 0;
  rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
  {
    die("Failed to write database!", conn);
  }

  for (i = 0; i < MAX_ROWS; i++)
  {
    rc = fwrite(&((conn->db->rows[i]).id), sizeof(int), 1, conn->file);
    if (rc != 1)
    {
      die("Failed to write id!\n", conn);
    }

    rc = fwrite(&((conn->db->rows[i]).set), sizeof(int), 1, conn->file);
    if (rc != 1)
    {
      die("Failed to write set!\n", conn);
    }

    rc = fwrite((conn->db->rows[i]).name, MAX_DATA, 1, conn->file);
    if (rc != 1)
    {
      die("Failed to write name!\n", conn);
    }

    rc = fwrite((conn->db->rows[i]).email, MAX_DATA, 1, conn->file);
    if (rc != 1)
    {
      die("Failed to write email!\n", conn);
    }
  }

  rc = fflush(conn->file);
  if (rc == -1)
  {
    die("Cannot flush database!", conn);
  }
}

void Database_create(struct Connection *conn)
{
  printf("MAX_ROWS:");
  scanf(" %d", &MAX_ROWS);
  if (MAX_ROWS <= 0)
  {
    die("MAX_ROWS must be positive", conn);
  }

  printf("MAX_DATA:");
  scanf(" %d", &MAX_DATA);
  if (MAX_DATA <= 0)
  {
    die("MAX_DATA must be positive", conn);
  }

  conn->db->MAX_ROWS = MAX_ROWS;
  conn->db->MAX_DATA = MAX_DATA;
  conn->db->rows = (struct Address *)malloc(sizeof(struct Address) * conn->db->MAX_ROWS);

  int i = 0;
  for (i = 0; i < MAX_ROWS; i++)
  {
    struct Address addr;
    addr.id = i;
    addr.set = 0;
    addr.name = (char *)malloc(conn->db->MAX_DATA);
    addr.email = (char *)malloc(conn->db->MAX_DATA);

    conn->db->rows[i] = addr; 
  }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
  struct Address *addr = &conn->db->rows[id];
  if (addr->set)
  {
    die("Already set, delete it first!", conn);
  }

  addr->set = 1;
  // WARNING: bug, read the "How To Break It" and fix this
  char *res = my_strncpy(addr->name, name, MAX_DATA);
  // demonstrate the strncpy bug
  if (!res)
  {
    die("Name copy failed!", conn);
  }

  res = my_strncpy(addr->email, email, MAX_DATA);
  if (!res)
  {
    die("Email copy failed!", conn);
  }
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
  free(conn->db->rows[id].name);
  free(conn->db->rows[id].email);

  struct Address addr;

  addr.id = id;
  addr.set = 0;
  addr.name = (char *)malloc(conn->db->MAX_DATA);
  addr.email = (char *)malloc(conn->db->MAX_DATA);
  
  conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
  int i = 0;
  struct Database *db = conn->db;

  for (i = 0; i < MAX_ROWS; i++)
  {
    struct Address *cur = &db->rows[i];

    if (cur->set)
    {
      Address_print(cur);
    }
  }
}

/**************************************************************************************************************************/

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    die_oneTimeOnly("USAGE: ex17 <dbfile> <action> [action params]");
  }
  
  char *filename = argv[1];
  char action = argv[2][0];
  struct Connection *conn = Database_open(filename, action);

  int id = 0;
  if (argc > 3)
  {
    id = atoi(argv[3]);
  }
  /* if (id >= MAX_ROWS)
  {
    die("There's not that many records!", conn);
  }
  */

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
      if (argc != 6)
      {
        die("Need id, name, email to set!", conn);
      }

      Database_set(conn, id, argv[4], argv[5]);
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
    default:
    {
      die("Invalid action: c=create, g=get, s=set, d=del, l=list", conn);
    }
  }

  Database_close(conn);

  return 0;
}
