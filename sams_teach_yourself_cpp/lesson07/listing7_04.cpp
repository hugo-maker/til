#include <iostream>
using namespace std;

// Function Declarations (Prototypes)

double area(double radius, double pi = 3.14);

int main()
{
  cout << "Enter radius: ";
  double radius = 0;
  cin >> radius;

  cout << "pi is 3.14, do you wish to change this (y / n)? ";
  char change_pi = 'n';
  cin >> change_pi;

  double circle_area = 0;
  if (change_pi == 'y')
  {
    cout << "Enter new pi: ";
    double new_pi = 3.14;
    cin >> new_pi;
    circle_area = area(radius, new_pi);
  }
  else
  {
    circle_area = area(radius); // Ignore 2nd param, use default value
  }
  // Call function "area"
  cout << "Area is: " << circle_area << endl;

  return 0;
}

// Function definitions (implementations)
double area(double radius, double pi)
{
  return pi * radius * radius;
}
