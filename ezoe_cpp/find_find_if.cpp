// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h find_find_if.cpp -o find_find_if
auto find = [] (auto first, auto last, auto const &value) 
{
  for (auto iter = first; iter != last; ++iter)
  {
    if (*iter == value)
    {
      return iter;
    }
  }
  return last;
};

auto find_if = [] (auto first, auto last, auto pred)
{
  for (auto iter = first; iter != last; ++iter)
  {
    if (pred(*iter))
    {
      return iter;
    }
  }

  return last;
};

auto find_with_find_if = [] (auto first, auto last, auto value)
{
  return std::find_if(first, last, 
      [&] (auto elem) {return value == elem;});
};

int main()
{
  std::vector<int> v = {1, 2, 3, 4, 5};

  std::cout << *(find(std::begin(v), std::end(v), 3)) << "\n"s;

  auto is_4 = [] (auto x) {return x == 4;};

  auto i = find_if(std::begin(v), std::end(v), is_4);

  auto j = find(std::begin(v), std::end(v), 4);

  std::cout << std::boolalpha;
  bool b = (i == j);
  std::cout << b << "\n"s;

  std::cout << 
    *(find_with_find_if(std::begin(v), std::end(v), 2)) << "\n"s;
}
