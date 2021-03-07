#include <iostream>
using namespace std;

union simple_union
{
  int num;
  char alphabet;
};

struct complex_type
{
  enum datatype
  {
    Int,
    Char,
  } type;

  union value
  {
    int num;
    char alphabet;

    value() {}
    ~value() {}
  } value;
};

void display_complex_type(const complex_type & obj)
{
  switch (obj.type)
  {
    case complex_type::Int:
    {
      cout << "Union contains number: " << obj.value.num << endl;
      break;
    }
    case complex_type::Char:
    {
      cout << "Union contains character: " << obj.value.alphabet << endl;
      break;
    }
  }
}

int main()
{
  simple_union u1, u2;
  u1.num = 2100;
  u2.alphabet = 'C';
  cout << "sizeof(u1) containing integer: " << sizeof(u1) << endl;
  cout << "sizeof(u2) containing character: " << sizeof(u2) << endl;

  complex_type my_data1, my_data2;
  my_data1.type = complex_type::Int;
  my_data1.value.num = 2017;

  my_data2.type = complex_type::Char;
  my_data2.value.alphabet = 'X';

  display_complex_type(my_data1);
  display_complex_type(my_data2);

  return 0;
}
