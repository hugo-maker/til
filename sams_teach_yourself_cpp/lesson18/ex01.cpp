#include <list>
#include <iostream>
using namespace std;

template <typename t>
void display_contents(const t & container)
{
  for (auto element = container.cbegin();
      element != container.cend();
      ++element)
  {
    cout << *element << ' ';
  }
  cout << endl;
}

int main()
{
  std::list<double> num_list;

  char user_select = '\0';
  do
  {
    cout << "Enter a number: ";
    auto input = 0;
    cin >> input;
    num_list.push_front(input);

    cout << "Would you like to insert number again(y/n)? " << endl;
    cout << "> ";
    cin >> user_select;
  } while (user_select != 'n');

  cout << "Here is your list: ";
  display_contents(num_list);

  return 0;
}
