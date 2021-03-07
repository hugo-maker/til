#include <iostream>
#include <string.h>
using namespace std;
class my_string
{
private:
  char * buffer;
  
public:
  my_string(const char * init_string) // constructor
  {
    if (init_string != NULL)
    {
      buffer = new char[strlen(init_string) + 1];
      strcpy(buffer, init_string);
    }
    else
    {
      buffer = NULL;
    }
  }

  ~my_string()
  {
    cout << "Invoking destructor, clearing up" << endl;
    if (buffer != NULL)
    {
      delete[] buffer;
    }
  }

  int get_length()
  {
    return strlen(buffer);
  }

  const char * get_string()
  {
    return buffer;
  }
};

int main()
{
  my_string say_hello("Hello from string class");
  cout << "String buffer in say_hello is " << say_hello.get_length();
  cout << " characters long" << endl;

  cout << "Buffer contains: " << say_hello.get_string() << endl;

  return 0;
}
