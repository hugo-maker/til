#include <iostream>
using namespace std;

int main()
{
  int dogs_age = 30;
  cout << "Initialized dogs_age = " << dogs_age << endl;

  int * points_to_an_age = &dogs_age;
  cout << "points_to_an_age points to dogs_age" << endl;

  cout << "Enter an age for your dog: ";

  // store input at the memory pointed to by points_to_an_age
  cin >> *points_to_an_age;

  // Displaying the address where age is stored
  cout << "Input stored at " << hex << points_to_an_age << endl;
  cout << "Integer dogs_age = " << dec << dogs_age << endl;

  return 0;
}
