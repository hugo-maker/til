// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

struct C
{
  int x = 1;
  int y = 2;
  int data{};

  int f(int) 
  {
    return 0;
  }
  int f0()
  {
    return 0;
  }
  int f1(int)
  {
    return 1;
  }
  int f2(int, int)
  {
    return 2;
  }
};

int main()
{
  int C::* x_ptr = &C::x;
  int C::* y_ptr = &C::y;

  C object;

  std::cout << object.*x_ptr;
  std::cout << object.*y_ptr;

  // メンバ関数へのポインタ
  int (C::*ptr)(int) = &C::f;
  // オブジェクトを指定したメンバ関数へのポインタを介した関数呼びだし
  (object.*ptr)(123);

  auto data_ptr = &C::data;
  // どちらも同じ意味
  object.*data_ptr = 123;
  std::invoke(data_ptr, object) = 123;

  C *c_ptr = &object;
  // どちらも同じ意味
  c_ptr->*data_ptr = 123;
  std::invoke(data_ptr, c_ptr) = 123;

  // どちらも同じ意味
  (object.*&C::f0)();
  std::invoke(&C::f0, object);
  // どちらも同じ意味
  (object.*&C::f1)(1);
  std::invoke(&C::f1, object, 1);
  // どちらも同じ意味
  (object.*&C::f2)(1, 2);
  std::invoke(&C::f2, object, 1, 2);
}
