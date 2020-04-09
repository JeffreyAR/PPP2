/*
Author: Jeffrey Russell
*/

#include "../std_lib_facilities.h"

int main(){
  //Accept two ints from the user. Continue running while the user supplies
  //integers.
  int i1,i2;
  while(cin >> i1 >> i2){
    if(i1 == i2) cout << "The values are equal.\n";
    else cout << "The smaller value is " << (i1 < i2 ? i1 : i2)
         << " and the larger value is " << (i1 > i2 ? i1 : i2) << ".\n";
  }
}
