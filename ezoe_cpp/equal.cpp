// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>
auto equal = [] (auto first1, auto last1, auto first2, auto last2)
{
  auto size1 = std::distance(first1, last1);
  auto size2 = std::distance(first2, last2);

  if (size1 != size2)
  {
    return false;
  }

  for (auto i = first1, j = first2; i != last1; ++i, ++j)
  {
    if (*i != *j)
    {
      return false;
    }
  }

  return true;
};

auto equal_pred = [] (auto first1, auto last1, auto first2, auto last2, auto pred)
{
  auto size1 = std::distance(first1, last1);
  auto size2 = std::distance(first2, last2);

  if (size1 != size2)
  {
    return false;
  }

  for (auto i = first1, j = first2; i != last1; ++i, ++j)
  {
    if (!pred(*i, *j))
    {
      return false;
    }
  }

  return true;
};

int main()
{
  std::vector<int> a = {1, 2, 3, 4, 5};
  std::vector<int> b = {1, 2, 3, 4, 5};
  std::vector<int> c = {1, 2, 3, 4, 5, 6};

  std::cout << std::boolalpha;

  bool ab = equal(std::begin(a), std::end(a), std::begin(b), std::end(b));
  std::cout << ab << "\n"s;

  bool ac = equal(std::begin(a), std::end(a), std::begin(c), std::end(c));
  std::cout << ac << "\n"s;

  std::vector<double> v = {1.3, 2.2, 3.0, 4.9, 5.7};
  std::vector<double> w = {1.9, 2.0, 3.7, 4.1, 5.1};

  auto cmp = [] (auto x, auto y)
  {
    return std::floor(x) == std::floor(y);
  };

  bool vw = equal_pred(std::begin(v), std::end(v), std::begin(w), std::end(w), cmp);
  std::cout << vw << "\n"s;
}
