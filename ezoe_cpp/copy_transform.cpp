// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

auto copy = [] (auto first, auto last, auto result)
{
  for (auto iter = first; iter != last; ++iter, ++result)
  {
    *result = *iter;
  }

  return result;
};

// opは関数。値をコピーする際に関数を適用できる。
auto transform = [] (auto first, auto last, auto result, auto op)
{
  for (auto iter = first; iter != last; ++iter, ++result)
  {
    *result = op(*iter);
  }

  return result;
};

int main()
{
  // copy test
  std::vector<int> source = {1, 2, 3, 4, 5};
  std::vector<int> destination(5);

  auto first = std::begin(source);
  auto last = std::end(source);
  auto result = std::begin(destination);
  auto returned = copy(first, last, result);

  for (std::size_t index = 0, size = destination.size(); index != size; ++index)
  {
    std::cout << destination.at(index) << " "s;
  }
  std::cout << "\n"s;

  std::cout << std::boolalpha;
  bool check_returned = (returned == (result + (last - first)));
  std::cout << "returned == (result + (last - first)): "s << check_returned << "\n"s;

  // transform test
  std::vector<int> a = {1, 2, 3, 4, 5};
  std::vector<int> b(5);

  transform(std::begin(a), std::end(a), std::begin(b), [] (auto x) {return x * x;});

  for (std::size_t index = 0, size = b.size(); index != size; ++index)
  {
    std::cout << b.at(index) << " "s;
  }
  std::cout << "\n"s;
}
