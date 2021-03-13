#include <iostream>
#include <deque>
#include <string>

int main()
{
  using namespace std;

  deque<string> strings{"Hello"s, "Containers are cool!"s, "C++ is evolving!"s};

  for (auto element = strings.cbegin();
      element != strings.cend();
      ++element)
  {
    cout << *element << " ";
  }

  cout << endl;
}
