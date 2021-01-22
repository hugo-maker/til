#include <iostream>

class MyClass
{
public:
  MyClass(int no) : mNo(no)
  {
    std::cout << "Constructor (" << mNo << ")" << std::endl;
  }

  // デストラクタ
  ~MyClass()
  {
    std::cout << "Destrucotr (" << mNo << ")" << std::endl;
  }

private:
  int mNo;
};

void f()
{
  MyClass c(999);
}

int main()
{
  MyClass a(1000);

  for (int i = 0; i < 3; ++i)
  {
    MyClass b(i);
  }

  f();
}
