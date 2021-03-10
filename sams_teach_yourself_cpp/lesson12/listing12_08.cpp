#include <iostream>
#include <string.h>
using namespace std;
class my_string
{
private:
  char * buffer;

public:
  my_string(const char * initial_input)
  {
    if (initial_input != NULL)
    {
      buffer = new char[strlen(initial_input) + 1];
      strcpy(buffer, initial_input);
    }
    else
    {
      buffer = NULL;
    }
  }

  // copy assignment operator
  my_string & operator = (const my_string & copy_source)
  {
    if ((this != &copy_source) && (copy_source.buffer != NULL))
    {
      if (buffer != NULL)
      {
        delete[] buffer;

        // ensure deep copy by first allocating own buffer
        buffer = new char[strlen(copy_source.buffer) + 1];

        // copy from the source into local buffer
        strcpy(buffer, copy_source.buffer);
      }
    }

    return *this;
  }

  operator const char * ()
  {
    return buffer;
  }

  ~my_string()
  {
    delete[] buffer;
  }
};

int main()
{
  my_string string1("Hello ");
  my_string string2(" World");

  cout << "Before assignment: " << endl;
  cout << string1 << string2 << endl;
  string2 = string1;
  cout << "After assignment string2 = string1: " << endl;
  cout << string1 << string2 << endl;

  return 0;
}
