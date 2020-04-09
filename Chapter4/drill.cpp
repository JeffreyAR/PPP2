/*
Author: Jeffrey Russell
*/

#include "../std_lib_facilities.h"

int main(){
  //Accept two ints from the user. Continue running while the user supplies
  //integers.
  double d1,d2;
  while(cin >> d1 >> d2){
    if(d1 == d2) cout << "The values are equal.\n";
    else cout << "The smaller value is " << (d1 < d2 ? d1 : d2)
         << " and the larger value is " << (d1 > d2 ? d1 : d2) << ".\n";
  }
}
