// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

auto replace = [] (auto first, auto last, auto old_value, auto new_value)
{
  for (auto iter = first; iter != last; ++iter)
  {
    if (*iter == old_value)
    {
      *iter = new_value;
    }
  }
};

auto fill = [] (auto first, auto last, auto value)
{
  for (auto iter = first; iter != last; ++iter)
  {
    *iter = value;
  }
};

auto fill_n = [] (auto first, auto n, auto value)
{
  for (auto i = 0; i != n; ++i, ++first)
  {
    *first = value;
  }
};

auto generate = [] (auto first, auto last, auto gen)
{
  for (auto iter = first; iter != last; ++iter)
  {
    *iter = gen();
  }
};

auto generate_n = [] (auto first, auto n, auto gen)
{
  for (auto i = 0; i != n; ++i, ++first)
  {
    *first = gen();
  }
};

int main()
{
  // replace test
  std::vector<int> a = {1, 3, 2, 3, 2, 3, 4, 2, 3, 4};
  replace(std::begin(a), std::end(a), 2, 1);

  for (size_t i = 0, size = a.size(); i != size; ++i)
  {
    std::cout << a.at(i) << " "s;
  }
  std::cout << "\n"s;

  // fill and fill_n test
  std::vector<int> b(5);
  fill(std::begin(b), std::end(b), 9);
  for (size_t i = 0, size = b.size(); i != size; ++i)
  {
    std::cout << b.at(i) << " "s;
  }
  std::cout << "\n"s;

  fill_n(std::begin(b), 3, 1);
  for (size_t i = 0, size = b.size(); i != size; ++i)
  {
    std::cout << b.at(i) << " "s;
  }
  std::cout << "\n"s;

  // gen and gen_n test
  std::vector<int> v = {1, 2, 3, 4, 5};
  auto gen_one = [] () {return 1;};
  auto gen_two = [] () {return 2;};

  generate(std::begin(v), std::end(v), gen_one);
  for (size_t i = 0, size = v.size(); i != size; ++i)
  {
    std::cout << v.at(i) << " "s;
  }
  std::cout << "\n"s;

  generate_n(std::begin(v), 4, gen_two);
  for (size_t i = 0, size = v.size(); i != size; ++i)
  {
    std::cout << v.at(i) << " "s;
  }
  std::cout << "\n"s;
}
