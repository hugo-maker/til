#include <iostream>
using namespace std;

int main()
{
  // uninitialized pointer
  bool * is_sunny;

  cout << "Is it sunny (y/n)? ";
  char user_input = 'y';
  cin >> user_input;

  if (user_input == 'y')
  {
    is_sunny = new bool;
    *is_sunny = true;
  }

  // is_sunny contains invalid value if user entered 'n'
  cout << "Booolean flag sunny says: " << *is_sunny << endl;

  // delete being invoked also when new wans't
  delete is_sunny;

  return 0;
}
