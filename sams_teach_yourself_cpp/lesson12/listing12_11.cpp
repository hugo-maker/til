#include <iostream>
#include <string.h>
using namespace std;

class my_string
{
private:
  char * buffer;

  my_string() : buffer(NULL) // private default constructor
  {
    cout << "Default constructor called" << endl;
  }

public:
  my_string(const char * initial_input) // constructor
  {
    cout << "Constructor called for: " << initial_input << endl;
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

  my_string(my_string && move_src) // move constructor
  {
    cout << "Move constructor moves: " << move_src.buffer << endl;
    if (move_src.buffer != NULL)
    {
      buffer = move_src.buffer; // take ownership i.e. 'move'
      move_src.buffer = NULL; // free move source
    }
  }

  my_string & operator = (my_string && move_src) // move assignment op.
  {
    cout << "Move assignment op. moves: " << move_src.buffer << endl;
    if ((move_src.buffer != NULL) && (this != &move_src))
    {
      delete[] buffer; // release own buffer

      buffer = move_src.buffer; // take ownership i.e. 'move'
      move_src.buffer = NULL; // free move source
    }

    return *this;
  }

  my_string(const my_string & copy_src) // copy constructor
  {
    cout << "Copy constructor copies: " << copy_src.buffer << endl;
    if (copy_src.buffer != NULL)
    {
      buffer = new char[strlen(copy_src.buffer) + 1];
      strcpy(buffer, copy_src.buffer);
    }
    else
    {
      buffer = NULL;
    }
  }

  my_string & operator = (const my_string & copy_src) // copy assignment op.
  {
    cout << "Copy assignment op. copies: " << copy_src.buffer << endl;
    if ((this != &copy_src) && (copy_src.buffer != NULL))
    {
      if (buffer != NULL)
      {
        delete[] buffer;
      }
      buffer = new char[strlen(copy_src.buffer) + 1];
      strcpy(buffer, copy_src.buffer);
    }

    return *this;
  }

  ~my_string() // destructor
  {
    if (buffer != NULL)
    {
      delete[] buffer;
    }
  }

  int get_length()
  {
    return strlen(buffer);
  }

  operator const char * ()
  {
    return buffer;
  }

  my_string operator + (const my_string & add_this)
  {
    cout << "operator + called: " << endl;
    my_string new_str;

    if (add_this.buffer != NULL)
    {
      new_str.buffer = new char[get_length() + strlen(add_this.buffer) + 1];
      strcpy(new_str.buffer, buffer);
      strcat(new_str.buffer, add_this.buffer);
    }

    return new_str;
  }
};

int main()
{
  my_string hello("Hello ");
  my_string world("World");
  my_string cpp(" of C++");

  my_string say_hello_again("overwrite this");
  say_hello_again = hello + world + cpp;

  return 0;
}
