// errno.h to use errno(=error No.) and perror()(=print error)
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

// fixed size structure
struct Address
{
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

// fixed size structure
struct Database
{
  struct Address rows[MAX_ROWS];
};

// variable size structure
struct Connection
{
  FILE *file;
  struct Database *db;
};

// function to kill the program with an error
void die(const char *message)
{
  if (errno) // other than 0
  {
    // void perror(const char *s);
    // The perror() function produces a message on standard error describing the last error encountered during a call to a system or library function.
    perror(message);
  }
  else // errno == 0
  {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

void Address_print(struct Address *addr)
{
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
  /*
   * size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
   * The function fread() reads nmemb items of data, each size bytes long, from the stream pointed to by stream, storing them at the location given by ptr.
   * On success, fread() and fwrite() return the number of items read or written.
   * In this case, rc is the number of items which were read by fread(), so rc must be 1.
   */
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
  {
    die("Failed to load database!");
  }
}

struct Connection *Database_open(const char *filename, char mode)
{
  /* Uninitialised value was created by a heap allocation ==6275==
   * at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
   * ==6275==    by 0x1093FD: Database_open (ex17.c:73)
   * ==6275==    by 0x109930: main (ex17.c:244)
   */

  struct Connection *conn = malloc(sizeof(struct Connection));
  if (!conn)
  {
    die("Memory error!");
  }

  /* I forgot to write this part! In this line, initializing the conn. */
  conn->db = malloc(sizeof(struct Database));
  if (!conn->db)
  {
    die("Memory error!");
  }

  if (mode == 'c')
  {
    conn->file = fopen(filename, "w");
  }
  else
  {
    /* r+     Open for reading and writing.  The stream is positioned at the beginning of the file.
     * Upon successful completion fopen() returns a FILE pointer.  Otherwise, NULL is returned and errno is set to indicate the error.
     * In this case, conn->file must be other than NULL
     */
    conn->file = fopen(filename, "r+");

    if (conn->file)
    {
      Database_load(conn);
    }
  }

  // case that fopen() returns NULL
  if (!conn->file)
  {
    die("Failed to open the file!");
  }

  return conn;
}

void Database_close(struct Connection *conn)
{
  if (conn)
  {
    if (conn->file)
    {
      // The fclose() function flushes the stream pointed to by stream (writing any buffered output data using fflush()) and closes the underlying file descriptor.
      fclose(conn->file);
    }
    
    if (conn->db)
    {
      free(conn->db);
    }

    free(conn);
  }
}

void Database_write(struct Connection *conn)
{
  /* The  rewind()  function  sets  the file position indicator for the stream pointed to by stream to the beginning of the file.
   * It is equivalent to: (void) fseek(stream, 0L, SEEK_SET) except that the error indicator for  the  stream  is  also  cleared.
   * The rewind() function returns  no  value. 
   */
  rewind(conn->file);

  /* The  function  fwrite() writes nmemb items of data, each size bytes long,
   * to the stream pointed to by stream,  obtaining  them  from  the  location given by ptr.
   * On success, fread() and fwrite() return the number of items read or written.
   * In this case, rc must be 1.
   */

  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
  {
    die("Failed to write database!");
  }

  /* For  output  streams, 
   * fflush() forces a write of all user-space buffered data for the given output or update stream via  the  stream's  underlying write function.
   * Upon successful completion 0 is returned. Otherwise, EOF is returned and errno is set to indicate the error.
   */
  rc = fflush(conn->file);
  if (rc == -1)
  {
    die("Cannot flush database!");
  }
}

void Database_create(struct Connection *conn)
{
  int i = 0;

  for (i = 0; i < MAX_ROWS; i++)
  {
    // make a prototype to initialize it
    struct Address addr = {.id = i, .set = 0};
    // then just assign it
    // conn is pointer to db db is pointer to rows

    /* Use of uninitialized value of size 8
     * Database_create  by main :266     
     * Invalid write of size 8
     * Database_create by main :266
     * Address 0x0 is not stack'd, malloc'd or (recently) free'd */

    conn->db->rows[i] = addr; 
  }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
  // &conn->db->rows[i] means
  // get the i element of rows, which is in db, which is in conn, then get the address of i element.
  struct Address *addr = &conn->db->rows[id];
  // set is initialized with 0
  if (addr->set)
  {
    die("Already set, delete it first!");
  }

  addr->set = 1;
  // WARNING: bug, read the "How To Break It" and fix this
  char *res = strncpy(addr->name, name, MAX_DATA);
  // demonstrate the strncpy bug
  if (!res)
  {
    die("Name copy failed!");
  }

  res = strncpy(addr->email, email, MAX_DATA);
  if (!res)
  {
    die("Email copy failed!");
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
    die("ID is not set!");
  }
}

void Database_delete(struct Connection *conn, int id)
{
  struct Address addr = {.id = id, .set = 0};
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
    die("USAGE: ex17 <dbfile> <action> [action params]");
  }

  char *filename = argv[1];
  char action = argv[2][0];
  struct Connection *conn = Database_open(filename, action);
  int id = 0;

  if (argc > 3)
  {
    /* The atoi() function converts the initial portion of the string pointed to by nptr to int.
     * The behavior is the same as strtol(nptr, NULL, 10); except that atoi() does not detect errors.
     * atoi() returns the converted value.
     */

    id = atoi(argv[3]);
  }

  if (id >= MAX_ROWS)
  {
    die("There's not that many records!");
  }

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
        die("Need an id to get!");
      }
      Database_get(conn, id);
      break;
    }
    case 's': // case 'set'
    {
      if (argc != 6)
      {
        die("Need id, name, email to set!");
      }

      Database_set(conn, id, argv[4], argv[5]);
      Database_write(conn);
      break;
    }
    case 'd': // case 'delete'
    {
      if (argc != 4)
      {
        die("Need id to delete!");
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
      die("Invalid action: c=create, g=get, s=set, d=del, l=list");
    }
  }

  Database_close(conn);

  return 0;
}
