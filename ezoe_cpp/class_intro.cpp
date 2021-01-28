// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

struct fractional
{
  int num;
  int denom;

  void set(int num, int denom)
  {
    fractional::num = num;
    fractional::denom = denom;
  }

  double value()
  {
    return static_cast<double>(num) / static_cast<double>(denom);
  }
};

struct S
{
  int x;
  void f(int x)
  {
    x = x;
  }
};

int main()
{
  fractional x;
  x.set(2, 3);
  std::cout << x.value() << "\n"s;

  S s{0};
  s.f(1);
  // xの値は0
  std::cout << s.x << "\n"s;
}
