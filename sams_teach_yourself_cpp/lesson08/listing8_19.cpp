#include <iostream>
using namespace std;

void get_square(const int & number, int & result)
{
  result = number * number;
}

int main()
{
  cout << "Enter a number you wish to square: ";
  int number = 0;
  cin >> number;

  int square = 0;
  get_square(number, square);
  cout << number << "^2 = "  << square << endl;

  return 0;
}
