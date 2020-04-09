/*
Author: Jeffrey Russell
*/

#include "../std_lib_facilities.h"

int main(){
  //Accept two ints from the user. Continue running while the user supplies
  //integers.
  int i1,i2;
  while(cin >> i1 >> i2){
    cout << i1 << " " << i2 << "\n";
  }
}
