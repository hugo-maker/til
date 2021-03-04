#include <iostream>
using namespace std;

int main()
{
  cout << "Enter two integers: ";
  int num1 = 0, num2 = 0;
  cin >> num1;
  cin >> num2;

  cout << "Enter \'m\' to multiply, or anything else to adds: ";
  char user_selection = '\0';
  cin >> user_selection;

  int result = 0;
  if (user_selection == 'm')
  {
    result = num1 * num2;
  }
  else
  {
    result = num1 + num2;
  }

  cout << "result is: " << result << endl;

  return 0;
}
