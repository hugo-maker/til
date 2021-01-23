#include <iostream>

template <typename T>
class Point
{
public:
  Point(T x, T y) : mX(x), mY(y)
  {}

  inline T GetX() const { return mX; }
  inline T GetY() const { return mY; }

private:
  T mX;
  T mY;
};

int main()
{
  const Point<int> p1(3, 5);
  const Point<double> p2(4.6, 2.3);

  std::cout << p1.GetX() << ", " << p1.GetY() << std::endl;
  std::cout << p2.GetX() << ", " << p2.GetY() << std::endl;
}
