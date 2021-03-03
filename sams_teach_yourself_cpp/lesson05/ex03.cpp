#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a boolean value true(1) or false(0): ";
  bool value1 = false;
  cin >> value1;

  cout << "Enter a boolean value true(1) or false(0): ";
  bool value2 = false;
  cin >> value2;

  cout << "Result of bitwise operators on these operands: " << endl;
  cout << "Bitwise AND: " << (value1 & value2) << endl;
  cout << "Bitwise OR: " << (value1 | value2) << endl;
  cout << "Bitwise XOR: " << (value1 ^ value2) << endl;

  return 0;
}
