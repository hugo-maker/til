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
    buffer = NULL;
    if (init_string != NULL)
    {
      buffer = new char[strlen(init_string) + 1];
      strcpy(buffer, init_string);
    }
  }

  ~my_string() // destructor
  {
    cout << "Invoking destructor, clearing up" << endl;
    delete[] buffer;
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

void use_my_string(my_string str)
{
  cout << "String buffer in my_string is " << str.get_length();
  cout << " characters long" << endl;

  cout << "buffer contains: " << str.get_string() << endl;
  return;
}

int main()
{
  my_string say_hello("Hello from string class");
  use_my_string(say_hello);

  return 0;
}
