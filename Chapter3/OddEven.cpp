/*
Author: Jeffrey Russell
Purpose: Accept as input an integer. Output whether that integer is even or odd.
*/

#include "../std_lib_facilities.h"

int main(){

  //Request and store an integer.
  cout << "Please input an integer: ";
  int i;
  cin >> i;

  //Output whether the integer is even or odd.
  cout << i << " is an ";
  if(i % 2 == 0) cout << "even";
  else cout << "odd";
  cout << " number.\n";
}
