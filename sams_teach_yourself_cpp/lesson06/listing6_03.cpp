#include <iostream>
using namespace std;

int main()
{
  cout << "Enter two numbers: " << endl;
  float num1 = 0, num2 = 0;
  cin >> num1;
  cin >> num2;

  cout << "Enter 'd' to divide, anything else to multiply: ";
  char user_selection = '\0';
  cin >> user_selection;

  if (user_selection == 'd')
  {
    cout << "You wish to divide!" << endl;
    if (num2 != 0)
    {
      cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    }
    else
    {
      cout << "Divesion by zero is not allowed" << endl;
    }
  }
  else
  {
    cout << "You wish to multiply!" << endl;
    cout << num1 << " x " << num2 << " = " << num1 * num2 << endl;
  }

  return 0;
}
