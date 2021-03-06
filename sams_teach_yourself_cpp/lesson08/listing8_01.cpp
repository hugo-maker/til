#include <iostream>
using namespace std;

int main()
{
  int age = 30;
  const double pi = 3.1416;

  // Use & to find the address in memory
  cout << "Integer age is located at: 0x" << &age << endl;
  cout << "Double pi is located at: 0x" << &pi << endl;

  return 0;
}
