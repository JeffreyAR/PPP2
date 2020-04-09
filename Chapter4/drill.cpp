/*
Author: Jeffrey Russell
*/

#include "../std_lib_facilities.h"

int main(){
  //Accept two doubles from the user. Continue running while the user supplies
  //doubles.
  double d1,d2;
  while(cin >> d1 >> d2){

    //Output comparison. Note if the absolute value of the difference if the
    //doubles is less than 1/100.
    if(d1 == d2) cout << "The values are equal.\n";
    else{
      cout << "The smaller value is " << (d1 < d2 ? d1 : d2)
           << " and the larger value is " << (d1 > d2 ? d1 : d2) << ".\n";
      if(d1 - d2 < 1.0/100 && d1 - d2 > -1.0/100) cout << "The numbers are almost equal.\n";
    }
  }
}
