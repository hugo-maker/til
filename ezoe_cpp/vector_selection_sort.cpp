// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h vector_selection_sort.cpp -o vector_selection_sort
int input()
{
  int x{};
  std::cin >> x;
  return x;
}

int main()
{
  std::vector<int> v;
  int x{};

  while ((x = input()) != 0)
  {
    v.push_back(x);
  }

  std::size_t size = v.size();
  for (std::size_t head = 0; head != size; ++head)
  {
    std::size_t min = head;
    for (std::size_t index = head + 1; index != size; ++index)
    {
      if (v.at(index) < v.at(min))
      {
        min = index;
      }
    }
    std::cout << v.at(min) << " "s;

    auto temp = v.at(head);
    v.at(head) = v.at(min);
    v.at(min) = temp;
  }


  std::cout << "\n"s;
  for (std::size_t index = 0, size = v.size(); index != size; ++index)
  {
    std::cout << v.at(index) << " "s;
  }
  std::cout << "\n"s;
}
