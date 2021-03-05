#include <iostream>
using namespace std;

const double pi = 3.14159265;

auto area(double radius)
{
  return pi * radius * radius;
}

int main()
{
  cout << "Enter radius: ";
  double radius = 0;
  cin >> radius;

  // Call function "area"
  cout << "Area is: " << area(radius) << endl;

  return 0;
}
