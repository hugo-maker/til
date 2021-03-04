#include <iostream>
#include <string>
using namespace std;

int main()
{
  int some_nums[] = {1, 101, -1, 40, 2040};

  for (const int & a_num : some_nums)
  {
    cout << a_num << ' ';
  }
  cout << endl;

  for (auto an_element : {5, 222, 110, -45, 2017})
  {
    cout << an_element << ' ';
  }
  cout << endl;

  char char_array[] = {'h', 'e', 'l', 'l', 'o'};
  for (auto a_char : char_array)
  {
    cout << a_char << ' ';
  }
  cout << endl;

  double more_nums[] = {3.14, -1,3, 22, 10101};
  for (auto an_element : more_nums)
  {
    cout << an_element << ' ';
  }
  cout << endl;

  string say_hello{"Hello, World!"};
  for (auto an_element : say_hello)
  {
    cout << an_element << ' ';
  }
  cout << endl;

  return 0;
}
