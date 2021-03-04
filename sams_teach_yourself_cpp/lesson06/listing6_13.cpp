#include <iostream>
using namespace std;

int main()
{
  for (;;)
  {
    cout << "Enter two integers: " << endl;
    int num1 = 0, num2 = 0;
    cin >> num1;
    cin >> num2;

    cout << "Do you wish to correct the numbers? (y/n): ";
    char change_numbers = '\0';
    cin >> change_numbers;

    if (change_numbers == 'y')
    {
      continue; // restart the loop!
    }

    cout << num1 << " x " << num2 << " = " << num1 * num2 << endl;
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;

    cout << "Press x to exit or any other key to recalculate" << endl;

    char user_selection = '\0';
    cin >> user_selection;

    if (user_selection == 'x')
    {
      break; // exit the infinite loop
    }
  }

  cout << "Goodbye!" << endl;

  return 0;
}
