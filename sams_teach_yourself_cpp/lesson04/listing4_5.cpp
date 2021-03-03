#include <iostream>
using namespace std;

int main()
{
  char say_hello[] = {'H', 'e', 'l', 'l', 'o', ' ',
  'W', 'o', 'r', 'l', 'd', '\0'};
  cout << say_hello << endl;
  cout << "Size of array: " << sizeof(say_hello) << endl;

  cout << "Replacing space with null" << endl;
  say_hello[5] = '\0';
  cout << say_hello << endl;
  cout << "Size of array: " << sizeof(say_hello) << endl;

  return 0;
}
