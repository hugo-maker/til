#include <iostream>
using namespace std;

int main()
{
  // Static array of 5 integers
  int my_numbers[5];

  // array assigned to pointet to int
  int * point_to_nums = my_numbers;

  // Display address contained in pointer
  cout << "point_to_nums = " << hex << point_to_nums << endl;

  // Address of first element of array
  cout << "&my_numbers[0] = " << hex << &my_numbers[0] << endl;

  return 0;
}
