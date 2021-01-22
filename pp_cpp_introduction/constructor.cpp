#include <iostream>

class Point
{
public:
  // デフォルトコンストラクタ: 実引数の指定なしで呼び出せるコンストラクタ
  Point()
  {
    m_x = 0;
    m_y = 0;
  }
  // コンストラクタ
  Point (int x, int y)
  {
    m_x = x;
    m_y = y;
  }

  inline int GetX() const { return m_x; }
  inline int GetY() const { return m_y; }

private:
  int m_x;
  int m_y;
};

int main()
{
  // デフォルトコンストラクタが呼ばれる
  Point point1;
  // コンストラクタが呼ばれる
  Point point2(1, 10);
  std::cout << point1.GetX() << ", " << point1.GetY() << std::endl;
  std::cout << point2.GetX() << ", " << point2.GetY() << std::endl;
}
