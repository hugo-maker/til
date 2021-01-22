#include <iostream>

class Point
{
public:
  void SetXY(int x, int y);

  int GetX();
  int GetY();

private:
  int m_x;
  int m_y;
};

void Point::SetXY(int x, int y)
{
  m_x = x;
  m_y = y;
}

int Point::GetX()
{
  return m_x;
}

int Point::GetY()
{
  return m_y;
}

int main()
{
  Point point;
  point.SetXY(1, 10);

  std::cout << point.GetX() << ", " << point.GetY() << std::endl;
}
