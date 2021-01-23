#include <iostream>
#include <stack>

int main()
{
  std::stack<int> s;

  for (int i = 0; i < 5; ++i)
  {
    s.push(i);
  }

  const std::stack<int>::size_type size = s.size();

  for (std::stack<int>::size_type i = 0; i < size; ++i)
  {
    std::cout << s.top() << std::endl;
    s.pop();
  }

  if (s.empty())
  {
    std::cout << "empty" << std::endl;
  }
  else
  {
    std::cout << "not empty" << std::endl;
  }
}
