#include <set>
#include <iostream>
#include <string>
using namespace std;

template <typename t>
void display_contents(const t & container)
{
  for (auto i_element = container.cbegin();
      i_element != container.cend();
      ++i_element)
  {
    cout << *i_element << endl;
  }
  cout << endl;
}

struct contact_item
{
  string name;
  string phone_num;
  string display_as;

  contact_item(const string & name_init, const string & phone)
  {
    name = name_init;
    phone_num = phone;
    display_as = (name + ": " + phone_num);
  }

  // used by set::find() given contact list item
  bool operator == (const contact_item & item_to_compare) const
  {
    return (item_to_compare.phone_num == this->phone_num);
  }

  // used to sort
  bool operator < (const contact_item & item_to_compare) const
  {
    return (this->phone_num < item_to_compare.phone_num);
  }

  // used in display_contents via cout
  operator const char * () const
  {
    return display_as.c_str();
  }
};

int main()
{
  set<contact_item> set_contacts;
  set_contacts.insert(contact_item("Jack Welsch", "+1 7889 879 879"));
  set_contacts.insert(contact_item("Bill Gates", "+1 97 7897 8799 8"));
  set_contacts.insert(contact_item("Angi Merkel", "+49 23456 5466"));
  set_contacts.insert(contact_item("Vlad Putin", "+7 6645 4564 797"));
  set_contacts.insert(contact_item("Ben Afflec", "+1 745 6413 14"));
  set_contacts.insert(contact_item("Dan Craig", "+44 123 456 789"));
  display_contents(set_contacts);

  cout << "Enter a phone number you wish to search: ";
  string input_phone_num;
  getline(cin, input_phone_num);

  auto contact_found = set_contacts.find(contact_item("", input_phone_num));
  if (contact_found != set_contacts.end())
  {
    cout << "Contact found!" << endl;
    cout << (*contact_found).phone_num  << ": " << (*contact_found).name << endl;
    display_contents(set_contacts);
  }
  else
  {
    cout << "Contact not found" << endl;
  }

  return 0;
}
