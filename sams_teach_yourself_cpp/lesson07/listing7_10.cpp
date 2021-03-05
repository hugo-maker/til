#include <iostream>
using namespace std;

// define an inline function that doubles
inline long double_num(int input_num)
{
  return input_num * 2;
}

int main()
{
  cout << "Enter an integer: ";
  int input_num = 0;
  cin >> input_num;

  // call inline function
  cout << "Double is: " << double_num(input_num) << endl;

  return 0;
}
