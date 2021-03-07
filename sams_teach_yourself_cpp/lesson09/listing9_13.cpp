#include <iostream>
#include <string.h>
using namespace std;
class my_string
{
private:
  char * buffer;

public:
  my_string(const char * init_string)
  {
    buffer = NULL;
    if (init_string != NULL)
    {
      buffer = new char[strlen(init_string) + 1];
      strcpy(buffer, init_string);
    }
  }

  my_string(const my_string & copy_source)
  {
    buffer = NULL;
    if (copy_source.buffer != NULL)
    {
      buffer = new char[strlen(copy_source.buffer) + 1];
      strcpy(buffer, copy_source.buffer);
    }
  }

  ~my_string()
  {
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

class human
{
private:
  int age;
  bool gender;
  my_string name;

public:
  human(const my_string & input_name, int input_age, bool gender)
    : name(input_name), age(input_age), gender(gender) {}

  int get_age()
  {
    return age;
  }
};

int main()
{
  my_string mans_name("Adam");
  my_string womans_name("Eve");

  cout << "sizeof(my_string) = " << sizeof(my_string) << endl;
  cout << "sizeof(mans_name) = " << sizeof(mans_name) << endl;
  cout << "sizeof(womans_name) = " << sizeof(womans_name) << endl;

  human first_man(mans_name, 25, true);
  human first_woman(womans_name, 18, false);

  cout << "sizeof(human) = " << sizeof(human) << endl;
  cout << "sizeof(first_man) = " << sizeof(first_man) << endl;
  cout << "sizeof(first_woman) = " << sizeof(first_woman) << endl;

  return 0;
}
