#include <iostream>
using namespace std;

int main()
{
  // without loop expression (third expression missing)
  for (char user_selection = 'm'; (user_selection != 'x');)
  {
    cout << "Enter the two integers: " << endl;
    int num1 = 0, num2 = 0;
    cin >> num1;
    cin >> num2;

    cout << num1 << " x " << num2 << " = " << num1 * num2 << endl;
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;

    cout << "Pres x to exit or any other key to recalculate" << endl;
    cin >> user_selection;
  }

  cout << "Goodbye!" << endl;

  return 0;
}
