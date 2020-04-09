/*
Author: Jeffrey Russell
Purpose: Accepts three integers from the user. Outputs them from smallest to
         largest.
*/

#include "../std_lib_facilities.h"

int main(){

  //Request and store three integers.
  cout << "Please enter three integers: ";
  int i1,i2,i3;
  cin >> i1 >> i2 >> i3;

  //Swap i1 and i2 if needed.
  if(i1 > i2){
    i1 = i1 + i2;
    i2 = i1 - i2;
    i1 = i1 - i2;
  }

  //Swap i2 and i3 if needed.
  if(i2 > i3){
    i2 = i2 + i3;
    i3 = i2 - i3;
    i2 = i2 - i3;
  }

  //Swap i1 and i2 if needed.
  if(i1 > i2){
    i1 = i1 + i2;
    i2 = i1 - i2;
    i1 = i1 - i2;
  }

  //Output the integers in ascending order.
  cout << i1 << ", " << i2 << ", " << i3 << "\n";
}
