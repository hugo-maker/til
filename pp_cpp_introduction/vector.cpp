#include <iostream>
#include <vector>

void print_vector(const std::vector<int> *vec)
{
  const std::vector<int>::size_type size = vec->size();
  for (std::vector<int>::size_type i = 0; i < size; ++i)
  {
    std::cout << (*vec)[i] << std::endl;
  }
}

int main()
{
  std::vector<int> v1; // サイズ0、容量 0
  std::vector<int> v2(5); // サイズ 5、容量 5(以上)
  std::vector<int> v3 = {0, 10, 20, 30}; // サイズ 4、容量 4(以上)

  print_vector(&v1);
  print_vector(&v2);
  print_vector(&v3);

  std::cout << "v1: " << "size = " << v1.size() << ", capacity = " << v1.capacity() << std::endl;
  std::cout << "v2: " << "size = " << v2.size() << ", capacity = " << v2.capacity() << std::endl;
  std::cout << "v3: " << "size = " << v3.size() << ", capacity = " << v3.capacity() << std::endl;

  for (int i = 0; i < 5; ++i)
  {
    v1.push_back(i); // 末尾に追加。必要に応じて容量拡張
  }
  print_vector(&v1);
  std::cout << "v1: " << "size = " << v1.size() << ", capacity = " << v1.capacity() << std::endl;

  // sizeメンバ関数でサイズを取得
  const std::vector<int>::size_type size = v2.size();
  for (std::vector<int>::size_type i = 0; i < size; ++i)
  {
    v2[i] = 10;
  }
  print_vector(&v2);
  std::cout << "v2: " << "size = " << v2.size() << ", capacity = " << v2.capacity() << std::endl;

  if (v1.empty())
  {
    std::cout << "empty" << std::endl;
  }
  else
  {
    std::cout << "not empty" << std::endl;
  }
}
