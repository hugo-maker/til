#include <iostream>
using namespace std;

int main()
{
  int three_rows_three_columns[3][3] = \
  {{-501, 205, 2016}, {989, 101, 206}, {303, 456, 596}};

  cout << "Row 0: " << three_rows_three_columns[0][0] << " " \
                    << three_rows_three_columns[0][1] << " " \
                    << three_rows_three_columns[0][2] << endl;

  cout << "Row 1: " << three_rows_three_columns[1][0] << " " \
                    << three_rows_three_columns[1][1] << " " \
                    << three_rows_three_columns[1][2] << endl;

  cout << "Row 2: " << three_rows_three_columns[2][0] << " " \
                    << three_rows_three_columns[2][1] << " " \
                    << three_rows_three_columns[2][2] << endl;

  return 0;
}
