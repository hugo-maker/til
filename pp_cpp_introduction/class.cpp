#include <iostream>

class Point
{
public:
  void SetXY(int x, int y);

  int GetX();
  int GetY();

private:
  int x;
  int y;
};

void Point::SetXY(int x, int y)
{
  this->x = x;
  this->y = y;
}

int Point::GetX()
{
  return this->x;
}

int Point::GetY()
{
  return this->y;
}

int main()
{
  Point point;
  point.SetXY(1, 10);

  std::cout << point.GetX() << ", " << point.GetY() << std::endl;
}
