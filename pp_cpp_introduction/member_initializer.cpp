#include <iostream>

class Point
{
public:
  Point() : mX(0), mY(0)
  {

  }

  Point(int x, int y) : mX(x), mY(y)
  {

  }

  inline int GetX() const { return mX; }
  inline int GetY() const { return mY; }

private:
  int mX;
  int mY;
};

class Rect
{
public:
  Rect(int left, int top, int right, int bottom) :
    mLT(left, top), mRB(right, bottom)
  {}

  inline const Point *GetLeftTop() const { return &mLT; }
  inline const Point *GetRightBottom() const { return &mRB; }

private:
  Point mLT;
  Point mRB;
};

int main()
{
  const Rect rect(3, 3, 5, 5);
  const Point *const lt = rect.GetLeftTop();
  const Point *const rb = rect.GetRightBottom();
  std::cout << lt->GetX() << ", " << lt->GetY() << std::endl;
  std::cout << rb->GetX() << ", " << rb->GetY() << std::endl;
}
