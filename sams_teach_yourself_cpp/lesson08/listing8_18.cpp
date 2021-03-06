#include <iostream>
using namespace std;

void get_square(int & number)
{
  number *= number;
}

int main()
{
  cout << "Enter a number you wish to square: ";
  int number = 0;
  cin >> number;

  get_square(number);
  cout << "Square is: " << number << endl;

  return 0;
}
