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
    return (item_to_compare.name == this->name);
  }

  // used to sort
  bool operator < (const contact_item & item_to_compare) const
  {
    return (this->name < item_to_compare.name);
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

  cout << "Enter a name you wish to delete: ";
  string input_name;
  getline(cin, input_name);

  auto contact_found = set_contacts.find(contact_item(input_name, ""));
  if (contact_found != set_contacts.end())
  {
    set_contacts.erase(contact_found);
    cout << "Display contents after erasing " << input_name << endl;
    display_contents(set_contacts);
  }
  else
  {
    cout << "Contact not found" << endl;
  }

  return 0;
}
