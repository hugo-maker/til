// Code from stackoverflow
// https://stackoverflow.com/questions/17224165/freading-a-dynamically-allocated-struct

void Database_load(struct Connection *conn)
{

     int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);

     if(rc != 1) die("Failed to load database.", conn);

     const int MAX_ROWS = conn->db->MAX_ROWS;
     const int MAX_DATA = conn->db->MAX_DATA;
     int i = 0;

         // I want to allocate memory for the rows and the strings here...
         // Clearly the freads are failing, how would I actually allocate properly?
     for(i = 0; i < MAX_ROWS; i++)
     {
       rc = fread(conn->db->rows, sizeof(struct Address),
                 1 , conn->file);

       if(rc != 1) die("Failed to load rows.", conn);
       rc = fread(&conn->db->rows[i], sizeof(char),
                  MAX_DATA, conn->file);
       if(rc != MAX_DATA) die("Failed to load characters.", conn);
     }
}

/**************************************************************************************************************/

conn->db->rows = malloc(max_rows * sizeof(struct Address));
  
for (i = 0; i < max_rows; i++)
{
  rc = read(&conn->db->rows[i], sizeof(struct Address), 1, conn->file);
  if (rc != 1)
  {
    die("Failed to load rows!", conn);
  }

  conn->db->rows[i].name = malloc(max_data);
  conn->db->rows[i].email = malloc(max_data);

  rc = fread(&conn->db->rows[i]->name, sizeof(char), max_data, conn->file);
  if (rc != max_data)
  {
    die("Failed to load name!", conn);
  }

  rc = fread(&conn->db->rows[i]->email, sizeof(char), max_data, conn->file);
  if (rc != max_data)
  {
    die("Failed to load email!", conn);
  }
}
