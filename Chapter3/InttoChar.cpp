/*
Author: Jeffrey Russell
Purpose: While the user provides input, this program will convert a given
         double to a char, then back to an integer, and output each of the
         input, both integers, and the char.
*/

#include "../std_lib_facilities.h"

int main(){

  //While there is input, store as a double.
  double d = 0;
  while(cin >> d){

    //Convert the double to an integer, then a char, then an integer again.
    int i = d;
    char c = i;
    int i2 = c;

    //Output stored variables.
    cout << "d==" << d
          << "i==" << i
          << "i2==" << i2
          << " char(" << c << ")\n";
  }
}
