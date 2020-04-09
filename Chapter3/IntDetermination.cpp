/*
Author: Jeffrey Russell
Purpose: This program takes in two integers from the user. The smaller and
         larger of the two, their sum, difference, product, and ratio are
         output to the user.
*/

#include "../std_lib_facilities.h"

int main(){

  //Request and store two integer values.
  cout << "Please enter two integers for comparison: ";
  int val1,val2;
  cin >> val1 >> val2;

  //Output the smaller value followed by the larger value.
  cout << "The smaller of the two is " << (val1<val2 ? val1 : val2)
        << " and the larger is " << (val1>val2 ? val1 : val2) << ".\n";

  //Output the sum, difference, product, and ratio of the integers.
  cout << "Their sum is " << (val1 + val2) << "\ntheir difference is "
        << val1 - val2 << "\ntheir product is " << val1 * val2
        << "\ntheir ratio is " << ((double) val1) / ((double) val2) << "\n";
}
