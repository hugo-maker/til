#include <iostream>
#include <string>

int main()
{
  std::string s1;
  std::string s2("def");

  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;

  s1 = "ghi";
  std::cout << s1 << std::endl;

  s1 = s2;
  std::cout << s1 << std::endl;

  if (s1 == s2)
  {
    std::cout << "equal" << std::endl;
  }
  else
  {
    std::cout << "not equal" << std::endl;
  }

  std::string::size_type len = s1.length();
  std::cout << len << std::endl;

  if (s1.empty())
  {
    std::cout << "empty" << std::endl;
  }
  else
  {
    std::cout << "not empty" << std::endl;
  }

  s1 += s2;
  std::cout << s1 << std::endl;

  char c = s1[1];
  s1[1] = 'Y';
  std::cout << s1 << std::endl;

  const char *s = s1.c_str();
  std::cout << s << std::endl;
}
