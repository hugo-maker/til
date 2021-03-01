#include <iostream>
#include <string>
using namespace std;

int main()
{
  // Declare a variable to store an integer
  int input_number = 0;

  cout << "Enter an integer: ";

  // Store integer given user input
  cin >> input_number;

  // The same with text i.e. string data
  cout << "Enter your name: ";
  string input_name;
  cin >> input_name;

  cout << input_name << " entered " << input_number << endl;
  return 0;
}

