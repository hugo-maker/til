#include <iostream>
using namespace std;

int main()
{
  int age = 30;
  int dogs_age = 9;

  cout << "Integer age = " << age << endl;
  cout << "Integer dogs_age = " << dogs_age << endl;

  int * points_to_int = &age;
  cout << "points_to_int points to age" << endl;

  // Displaying the value of pointer
  cout << "points_to_int = " << hex << points_to_int << endl;

  // Displaying the value at the pointed location
  cout << "points_to_int = " << dec << *points_to_int << endl;

  points_to_int = &dogs_age;
  cout << "points_to_int points to dogs_age now" << endl;

  cout << "points_to_int = " << hex << points_to_int << endl;
  cout << "points_to_int = " << dec << *points_to_int << endl;

  return 0;
}
