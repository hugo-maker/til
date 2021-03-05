#include <iostream>
using namespace std;

const double pi = 3.14;

void area(double radius, double & area_fetched)
{
  area_fetched = pi * radius * radius;
}

void circumference(double radius, double & circumference_fetched)
{
  circumference_fetched = pi * 2 * radius;
}

int main()
{
  cout << "Enter the radius: ";
  double radius = 0;
  cin >> radius;

  double area_fetched = 0;
  double circumference_fetched = 0;

  area(radius, area_fetched);
  circumference(radius, circumference_fetched);

  cout << "Arae is: " << area_fetched << endl;
  cout << "Circumference is: " << circumference_fetched << endl;

  return 0;
}
