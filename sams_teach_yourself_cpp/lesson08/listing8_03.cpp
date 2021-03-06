#include <iostream>
using namespace std;

int main()
{
  int age = 30;

  int * points_to_int = &age;
  cout << "points_to_int points to age now" << endl;

  // Display the value of pointer
  cout << "points_to_int = " << hex << points_to_int << endl;

  int dogs_age = 9;
  points_to_int = &dogs_age;
  cout << "points_to_int points to dogs_age now" << endl;

  cout << "points_to_int = " << hex << points_to_int << endl;

  return 0;
}
