#include <iostream>
using namespace std;

const double pi = 3.14159265;

double area(double radius);
double area(double radius, double height);

int main()
{
  cout << "Enter z for Cylinder, c for Circle: ";
  char user_selection = 'z';
  cin >> user_selection;

  cout << "Enter radius: ";
  double radius = 0;
  cin >> radius;

  if (user_selection == 'z')
  {
    cout << "Enter height: ";
    double height = 0;
    cin >> height;

    // Invoke overloaded variant of area for Cylinder
    cout << "Area of cylinder is: " << area(radius, height) << endl;
  }
  else
  {
    cout << "Area of circle is: " << area(radius) << endl;
  }

  return 0;
}

double area(double radius)
{
  return pi * radius * radius;
}

double area(double radius, double height)
{
  return 2 * area(radius) + 2 * pi * radius * height;
}
