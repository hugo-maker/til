#include <iostream>
using namespace std;

int main()
{
  int age = 30;
  int * points_to_int = &age;

  // Display the value of pointer
  cout << "Integer age is at: 0x" << hex << points_to_int << endl;

  return 0;
}
