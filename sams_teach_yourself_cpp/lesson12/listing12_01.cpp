#include <iostream>
using namespace std;

class date
{
private:
  int day, month, year;

public:
  date(int in_month, int in_day, int in_year)
    : month(in_month), day(in_day), year(in_year) {}

  date & operator ++ () // prefix increment
  {
    ++day;
    return *this;
  }

  date & operator -- () // prefix decrement
  {
    --day;
    return *this;
  }

  date operator ++ (int) // postfix increment
  {
    date copy(month, day, year);
    ++day;
    return copy; // copy of instance before increment returned
  }

  date operator -- (int) // postfix decrement
  {
    date copy(month, day, year);
    --day;
    return copy; // copy of instance before decrement returned
  }

  void display_date()
  {
    cout << month << " / " << day << " / " << year << endl;
  }
};

int main()
{
  date holiday (12, 25, 2016);

  cout << "The date object is initialized to: ";
  holiday.display_date();

  ++holiday;
  cout << "Date after prefix-increment is: ";
  holiday.display_date();

  --holiday;
  cout << "Date after prefix-decrement is: ";
  holiday.display_date();

  holiday++;
  cout << "Date after postfix-increment is: ";
  holiday.display_date();

  holiday--;
  cout << "Date after postfix-decrement is: ";
  holiday.display_date();

  return 0;
}
