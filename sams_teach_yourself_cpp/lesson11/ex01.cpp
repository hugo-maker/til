#include <iostream>
using namespace std;

class shapes
{
public:
  shapes()
  {
    cout << "Constructed shapes" << endl;
  }

  virtual ~shapes()
  {
    cout << "Destructed shapes" << endl;
  }

  virtual double area() = 0;
  virtual void print() = 0;
};

class circle final : public shapes
{
private:
  double pi;
  double radius;
public:
  circle(double input_radius, double input_pi = 3.1416)
    : pi(input_pi), radius(input_radius)
  {
    cout << "Constructed circle" << endl;
  }

  ~circle() 
  {
    cout << "Destructed circle" << endl;
  }

  double area()
  {
    return pi * radius * radius;
  }

  void print()
  {
    cout << "Here is circle: its area is " << area() << endl;
  }
};

class triangle final : public shapes
{
private:
  double base;
  double height;

public:
  triangle(double input_base, double input_height)
    : base(input_base), height(input_height) 
  {
    cout << "Constructed triangle" << endl;
  }

  ~triangle()
  {
    cout << "Destructed triangle" << endl;
  }

  double area()
  {
    return base * height / 2;
  }

  void print()
  {
    cout << "Here is triangle: its area is " << area() << endl;
  }
};

int main()
{
  cout << "Enter the radius: ";
  double radius = 0;
  cin >> radius;

  circle my_circle(radius);
  my_circle.print();

  cout << "Enter the base and height: ";
  double base = 0, height = 0;;
  cin >> base;
  cin >> height;

  triangle my_triangle(base, height);
  my_triangle.print();

  return 0;
}
