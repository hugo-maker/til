// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

struct fractional
{
  int num;
  int denom;

  fractional(int num, int denom = 1)
    : num(num), denom(denom)
  {}

  double value()
  {
    return static_cast<double>(num) / static_cast<double>(denom);
  }
};

fractional operator +(fractional &l, fractional &r)
{
  if (l.denom == r.denom)
  {
    return fractional{l.num + r.num, l.denom};
  }
  else
  {
    return fractional{l.num * r.denom + r.num * l.denom, l.denom * r.denom};
  }
}

fractional operator -(fractional &l, fractional &r)
{
  if (l.denom == r.denom)
  {
    return fractional{l.num - r.num, l.denom};
  }
  else
  {
    return fractional{l.num * r.denom - r.num * l.denom, l.denom * r.denom};
  }
}

fractional operator *(fractional &l, fractional &r)
{
  return fractional(l.num * r.num, l.denom * r.denom);
}

fractional operator /(fractional &l, fractional &r)
{
  return fractional(l.num * r.denom, l.denom / r.num);
}

int main()
{
  fractional a(1, 2);
  fractional b(1, 3);

  auto c = a + b;
  std::cout << c.value() << "\n"s;

  c = a - b;
  std::cout << c.value() << "\n"s;

  c = a * b;
  std::cout << c.value() << "\n"s;

  c = a / b;
  std::cout << c.value() << "\n"s;
}
