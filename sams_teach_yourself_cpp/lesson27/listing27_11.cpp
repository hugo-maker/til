#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
  cout << "Enter an integer: ";
  int input = 0;
  cin >> input;

  stringstream converter_stream;
  converter_stream << input;
  string input_as_str;
  converter_stream >> input_as_str;

  cout << "Integer Input = " << input << endl;
  cout << "String gained from integer = " << input_as_str << endl;

  stringstream another_stream;
  another_stream << input_as_str;
  int copy = 0;
  another_stream >> copy;

  cout << "Integer gained from string, Copy = " << copy << endl;

  return 0;
}
