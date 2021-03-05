#include <iostream>
using namespace std;

const double pi = 3.14;

// for sphere
double volume(double radius)
{
  return (4 * pi * radius * radius) / 3;
}

// for cylinder
double volume(double radius, double height)
{
  return pi * radius * radius * height;
}

int main()
{
  cout << "Enter the radius: ";
  double radius = 0;
  cin >> radius;

  cout <<
    "Which do you wish to calculate, a volume of sphere or cylinder(s/c)? "
    << endl;
  char user_selection = 'c';
  cin >> user_selection;

  if (user_selection == 's')
  {
    cout << "Volume of sphere is: " 
      << volume(radius) << endl;
  }
  else
  {
    cout << "Enter the height: ";
    double height = 0;
    cin >> height;
    cout << "Volume of cylinder is: " 
      << volume(radius, height) << endl;
  }

  return 0;
}
