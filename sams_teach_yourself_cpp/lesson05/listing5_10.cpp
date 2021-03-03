#include <iostream>
using namespace std;

int main()
{
  cout << "Use sizeof to determine memory used by arrays" << endl;
  int my_numbers[100] = {0};

  cout << "Bytes used by an int: " << sizeof(int) << endl;
  cout << "Bytes used by my_numbers: " << sizeof(my_numbers) << endl;
  cout << "Bytes used by an element: " << sizeof(my_numbers[0]) << endl;

  return 0;
}
