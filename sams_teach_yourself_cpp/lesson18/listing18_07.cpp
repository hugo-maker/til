#include <list>
#include <string>
#include <iostream>
using namespace std;

template <typename t>
void display_as_contents(const t & container)
{
  for (auto element = container.cbegin();
      element != container.cend();
      ++element)
  {
    cout << *element << endl;
  }
  cout << endl;
}


struct contact_item
{
  string name;
  string phone;
  string display_as;

  contact_item(const string & con_name, const string & con_num)
  {
    name = con_name;
    phone = con_num;
    display_as = (name + ": " + phone);
  }

  // used by list::remove() given contact list item
  bool operator == (const contact_item & item_to_compare) const
  {
    return (item_to_compare.name == this->name);
  }

  // used by list::sort() without parameters
  bool operator < (const contact_item & item_to_compare) const
  {
    return (this->name < item_to_compare.name);
  }

  // used in display_as_contents via cout
  operator const char * () const
  {
    return display_as.c_str();
  }
};

bool sort_onphone_number(const contact_item & item1, const contact_item & item2)
{
  return (item1.phone < item2.phone);
}

int main()
{
  list<contact_item> contacts;
  contacts.push_back(contact_item("Jack Welsch", "+1 7889879879"));
  contacts.push_back(contact_item("Bill Gates", "+1 97789787998"));
  contacts.push_back(contact_item("Angi Merkel", "+49 234565466"));
  contacts.push_back(contact_item("Vlad Putin", "+7 66454564797"));
  contacts.push_back(contact_item("Ben Afflec", "+1 745641314"));
  contacts.push_back(contact_item("Dan Craig", "+44 123456789"));

  cout << "List in initial order: " << endl;
  display_as_contents(contacts);

  contacts.sort();
  cout << "Sorting in alphabetical order via operator <:" << endl;
  display_as_contents(contacts);

  contacts.sort(sort_onphone_number);
  cout << "Sorting in order of phone numbers via predicate:" << endl;
  display_as_contents(contacts);

  cout << "Erasing Putin from the list: " << endl;
  contacts.remove(contact_item("Vlad Putin", ""));
  display_as_contents(contacts);

  return 0;
}
