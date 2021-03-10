#include <iostream>
using namespace std;

class date
{
  int day, month, year;

public:
  date(int in_month, int in_day, int in_year)
    : month(in_month), day(in_day), year(in_year) {}

  bool operator < (const date & compare_to)
  {
    if (year < compare_to.year)
    {
      return true;
    }
    else if (month < compare_to.month)
    {
      return true;
    }
    else if (day < compare_to.day)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator <= (const date & compare_to)
  {
    if (this->operator == (compare_to))
    {
      return true;
    }
    else
    {
      return this->operator < (compare_to);
    }
  }

  bool operator > (const date & compare_to)
  {
    return !(this->operator <= (compare_to));
  }

  bool operator == (const date & compare_to)
  {
    return ((day == compare_to.day)
        && (month == compare_to.month)
        && (year == compare_to.year));
  }

  bool operator >= (const date & compare_to)
  {
    if (this->operator == (compare_to))
    {
      return true;
    }
    else
    {
      return this->operator > (compare_to);
    }
  }

  void display_date()
  {
    cout << month << " / " << day << " / " << year << endl;
  }
};

int main()
{
  date holiday1(12, 25, 2016);
  date holiday2(12, 31, 2016);

  cout << "holiday 1 is: ";
  holiday1.display_date();
  cout << "holiday 2 is: ";
  holiday2.display_date();

  if (holiday1 < holiday2)
  {
    cout << "operator <: holiday1 happens first" << endl;
  }

  if (holiday2 > holiday1)
  {
    cout << "operator >: holiday2 happends later" << endl;
  }

  if (holiday1 <= holiday2)
  {
    cout << "operator <=: holiday1 happnes on or before holiday2" << endl;
  }

  if (holiday2 >= holiday1)
  {
    cout << "operator >=: holiday2 happens on or after holiday1" << endl;
  }

  return 0;
}
