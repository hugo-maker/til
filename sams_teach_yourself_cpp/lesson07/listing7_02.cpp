#include <iostream>
using namespace std;

const double pi = 3.14159265;

// Declaration contains two parameters
double surface_area(double radius, double height);

int main()
{
  cout << "Enter the radius of the cylinder: ";
  double radius = 0;
  cin >> radius;
  cout << "Enter the height of the cylinder: ";
  double height = 0;
  cin >> height;

  cout << "Surface area: " << surface_area(radius, height) << endl;

  return 0;
}

double surface_area(double radius, double height)
{
  double area = 2 * pi * radius * radius + 2 * pi * radius * height;
  return area;
}
