#include <iostream>
using namespace std;

const double pi = 3.14159265;

// Function Declarations (Prototypes)
double area(double radius);
double circumference(double radius);

int main()
{
  cout << "Enter radius: ";
  double radius = 0;
  cin >> radius;

  // Call function "area"
  cout << "Area is: " << area(radius) << endl;

  // Call function "circumference"
  cout << "Circumference is: " << circumference(radius) << endl;

  return 0;
}

// Function definitions (implementations)
double area(double radius)
{
  return pi * radius * radius;
}

double circumference(double radius)
{
  return 2 * pi * radius;
}
