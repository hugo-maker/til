#include <iostream>
using namespace std;

int first_number = 0;
int second_number = 0;
int multiplication_result = first_number * second_number;

void multiplyNumbers()
{
  cout << "Enter the first number: ";
  cin >> first_number;

  cout << "Enter the second number: ";
  cin >> second_number;

  // Multiply two numbers, store result in a variable
  multiplication_result = first_number * second_number;

  // Display result
  cout << "Displaying from multiplyNumbers(): ";
  cout << first_number << " x " << second_number;
  cout << " = " << multiplication_result << endl;
}

int main()
{
  cout << "This program will help you multiply two numbers" << endl;

  // Call the function that does all the work
  multiplyNumbers();

  cout << "Display from main(): ";

  // This line will now compile and work!
  cout << first_number << " x " << second_number;
  cout << " = " << multiplication_result << endl;

  return 0;
}
