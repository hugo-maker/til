#include <iostream>
using namespace std;

int main()
{
  cout << "This program will help you multiply two numbers" << endl;

  cout << "Enter the first number: ";
  int first_number = 0;
  cin >> first_number;

  cout << "Enter the second number: ";
  int second_number = 0;
  cin >> second_number;

  // Multiply two numbers, store result in a variable
  int multiplicantion_result = first_number * second_number;

  // Display result
  cout << first_number << " x " << second_number;
  cout << " = " << multiplicantion_result << endl;

  return 0;
}
