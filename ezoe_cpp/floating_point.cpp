// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h floating_point.cpp -o floating_point
int main()
{
  double a = std::numeric_limits<double>::infinity();
  double b = -std::numeric_limits<double>::infinity();
  double NaN = std::numeric_limits<double>::quiet_NaN();

  std::cout << a << "\n"s << b << "\n"s << NaN << "\n"s;

  bool c = NaN == 0.0;
  bool d = NaN != NaN;
  bool e = NaN < 0.0;
  bool f = NaN == NaN;

  std::cout << c << "\n"s << d << "\n"s << e << "\n"s << f << "\n"s;

  std::cout
    << "float: "s << std::numeric_limits<float>::digits10 << "\n"s
    << "double: "s << std::numeric_limits<double>::digits10 << "\n"s
    << "long double: "s << std::numeric_limits<long double>::digits10 << "\n"s;

  std::cout
    << "float: "s << std::numeric_limits<float>::max_digits10 << "\n"s
    << "double: "s << std::numeric_limits<double>::max_digits10 << "\n"s
    << "long double: "s << std::numeric_limits<long double>::max_digits10 << "\n"s;

  std::cout
    << "float: "s << std::numeric_limits<float>::epsilon << "\n"s
    << "double: "s << std::numeric_limits<double>::epsilon << "\n"s
    << "long double: "s << std::numeric_limits<long double>::epsilon << "\n"s;
}
