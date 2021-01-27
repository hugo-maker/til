// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h count_count_if.cpp -o count_count_if

auto count = [] (auto first, auto last, auto value)
{
  auto counter = 0u;
  for (auto i = first; i != last; ++i)
  {
    if (*i == value)
    {
      ++counter;
    }
  }
  return counter;
};

auto count_if = [] (auto first, auto last, auto pred)
{
  auto counter = 0u;
  for (auto i = first; i != last; ++i)
  {
    if (pred(*i) != false)
    {
      ++counter;
    }
  }
  return counter;
};

int main()
{
  std::vector<int> v = {1, 2, 1, 1, 1, 3, 3};

  std::cout << count(std::begin(v), std::end(v), 1);
  std::cout << count(std::begin(v), std::end(v), 2);
  std::cout << count(std::begin(v), std::end(v), 3);

  std::cout << count_if(std::begin(v), std::end(v),
      [] (auto x) {return x % 2 == 1;});

  std::cout << count_if(std::begin(v), std::end(v),
      [] (auto x) {return x % 2 == 0;});
    
  std::cout << count_if(std::begin(v), std::end(v),
      [] (auto x) {return x >= 2;});
}
