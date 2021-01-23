#include <iostream>
#include <list>

void print_list(const std::list<int> *lst)
{
  const std::list<int>::const_iterator itEnd = lst->end();
  for (std::list<int>::const_iterator it = lst->begin(); it != itEnd; ++it)
  {
    std::cout << *it << std::endl;
  }
}

int main()
{
  std::list<int> lst1;
  std::list<int> lst2(5);
  std::list<int> lst3 = {0, 10, 20, 30};

  print_list(&lst1);
  print_list(&lst2);
  print_list(&lst3);

  // begin, endでイテレータを取得。イテレータはポインタのように操作可能。
  const std::list<int>::iterator itEnd = lst2.end();
  for (std::list<int>::iterator it = lst2.begin(); it != itEnd; ++it)
  {
    *it = 10;
  }
  print_list(&lst2);

  lst2.push_back(0);
  lst2.push_front(9);
  print_list(&lst2);

  std::cout << "-----" << std::endl;

  lst2.pop_back(); // 末尾の要素を取り除く
  lst2.pop_front(); // 先頭の要素を取り除く
  print_list(&lst2);

  std::cout << "-----" << std::endl;
  std::cout << "size = " << lst2.size() << std::endl;
  lst2.clear(); // 全ての要素を取り除く
  std::cout << "size = " << lst2.size() << std::endl;

  if (lst2.empty())
  {
    std::cout << "empty" << std::endl;
  }
  else
  {
    std::cout << "not empty" << std::endl;
  }
}
