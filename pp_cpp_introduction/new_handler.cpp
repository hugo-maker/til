#include <climits>
#include <cstdlib>
#include <iostream>
#include <new>

// 動的確保に失敗する巨大な型
struct BigData
{
  char c[INT_MAX];
};

// 独自のnewハンドラ
void my_new_handler()
{
  std::cerr << "memory allocate error" << std::endl;

  std::abort();
}

int main()
{
  std::set_new_handler(my_new_handler);

  BigData *data = new BigData();
  delete data;
}
