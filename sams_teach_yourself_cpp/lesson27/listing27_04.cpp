#include <iostream>
using namespace std;

int main()
{
  cout << "Enter an integer: ";
  int input_num = 0;
  cin >> input_num;

  cout << "Enter the value of pi: ";
  double pi = 0.0;
  cin >> pi;

  cout << "Enter three characters separated by space: " << endl;
  char char1 = '\0';
  char char2 = '\0';
  char char3 = '\0';
  cin >> char1 >> char2 >> char3;

  cout << "The record variable values are: " << endl;
  cout << "input_num: " << input_num << endl;
  cout << "pi: " << pi << endl;
  cout << "The three characters: " << char1 << char2 << char3 << endl;

  return 0;
}
