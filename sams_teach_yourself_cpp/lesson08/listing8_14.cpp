#include <iostream>
using namespace std;

int main()
{
  cout << "Is it sunny (y/n)? ";
  char user_input = 'y';
  cin >> user_input;

  // declare pointer and initialize
  bool * const is_sunny = new bool;
  *is_sunny = true;

  if (user_input == 'n')
  {
    *is_sunny = false;
  }

  // is_sunny contains invalid value if user entered 'n'
  cout << "Booolean flag sunny says: " << *is_sunny << endl;

  // release valid memory
  delete is_sunny;

  return 0;
}
