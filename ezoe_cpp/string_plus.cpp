// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h string_plus.cpp -o string_plus
std::string plus(std::string s1, std::string s2)
{
  return s1 + s2;
}

int main()
{
  auto x = plus("hello", "world");
  std::cout << x << std::endl;
}
