#include <iostream>
using namespace std;

int main()
{
  cout << "Enter the calculate numbers: ";
  int nums_to_calculate = 0;
  cin >> nums_to_calculate;

  cout << "This program will calculate " << nums_to_calculate \
    << " Fibonacci Numbers at a time" << endl;

  int num1 = 0, num2 = 1;
  char want_more = '\0';
  cout << num1 << " " << num2 << " ";

  do
  {
    for (int counter = 0; counter < nums_to_calculate; ++counter)
    {
      cout << num1 + num2 << " ";

      int num2_temp = num2;
      num2 = num1 + num2;
      num1 = num2_temp;
    }

    cout << endl << "Do you want more numbers (y/n)? ";
    cin >> want_more;
  } while (want_more == 'y');

  cout << "Goodbye!" << endl;

  return 0;
}
