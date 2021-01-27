// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h all_any_none_of.cpp -o all_any_none_of
auto all_of = [] (auto first, auto last, auto pred)
{
  for (auto iter = first; iter != last; ++iter)
  {
    if (pred(*iter) == false)
    {
      return false;
    }
  }
  return true;
};

auto any_of = [] (auto first, auto last, auto pred)
{
  for (auto iter = first; iter != last; ++iter)
  {
    if (pred(*iter))
    {
      return true;
    }
  }
  return false;
};

auto none_of = [] (auto first, auto last, auto pred)
{
  for (auto iter = first; iter != last; ++iter)
  {
    if (pred(*iter))
    {
      return false;
    }
  }
  return true;
};

int main()
{
  std::vector<int> v = {2, 44, 98, 16, 100, 0};
  std::cout << std::boolalpha;

  auto is_odd = [] (auto value) {return value % 2 == 0;};
  std::cout << 
    all_of(std::begin(v), std::end(v), is_odd) << "\n"s;
  
  auto is_le_100 = [] (auto value) {return value <= 100;};
  std::cout << 
    all_of(std::begin(v), std::end(v), is_le_100) << "\n"s;

  auto has_3 = [] (auto value) {return value == 3;};
  std::cout << 
    all_of(std::begin(v), std::end(v), has_3) << "\n"s;

  auto not_has_100 = [] (auto value) {return value != 100;};
  std::cout <<
    all_of(std::begin(v), std::end(v), not_has_100) << "\n"s;
}
