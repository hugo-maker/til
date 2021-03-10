#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class my_string
{
private:
  char * buffer;

  // private default constructor
  my_string() {}

public:
  // constructor
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

  // copy constructor
  my_string(const my_string & copy_source)
  {
    buffer = NULL;
    cout << "Copy constructor: copying from my_string" << endl;
    if (copy_source.buffer != NULL)
    {
      // allocate own buffer
      buffer = new char[strlen(copy_source.buffer) + 1];

      // deep copy from the source into local buffer
      strcpy(buffer, copy_source.buffer);

      cout << "buffer points to: " << hex;
      cout << (unsigned int *)buffer << endl;
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

  const char & operator [] (int index) const
  {
    if (index < get_length())
    {
      return buffer[index];
    }
  }

  // destructor
  ~my_string()
  {
    if (buffer != NULL)
    {
      delete[] buffer;
    }
  }

  int get_length() const
  {
    return strlen(buffer);
  }

  operator const char * ()
  {
    return buffer;
  }
};

int main()
{
  cout << "Type a statement: ";
  string str_input;
  getline(cin, str_input);

  my_string you_said(str_input.c_str());

  cout << "Using operator [] for displaying your input: " << endl;
  for (int index = 0; index < you_said.get_length(); ++index)
  {
    cout << you_said[index] << " ";
  }
  cout << endl;

  cout << "Enter index 0 - " << you_said.get_length() - 1 << ": ";
  int index = 0;
  cin >> index;
  cout << "Input character at zero-based position: " << index;
  cout << " is: " << you_said[index] << endl;

  return 0;
}
