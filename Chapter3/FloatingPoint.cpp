/*
Author: Jeffrey Russell
Purpose: Accepts as input an integer n and performs various operations on it.
         These operations and their results are output to the user.
*/

#include "../std_lib_facilities.h"

int main(){

  //Request an integer and store it.
  cout << "Please enter an integer value: ";
  int n;
  cin >> n;

  //Perform various operations to the given integer, output to the user.
  cout << "n == " << n
        << "\nn+1 == " << n+1
        << "\nthree times n == " << 3*n
        << "\ntwice n == " << n+n
        << "\nn squared == " << n*n
        << "\nhalf of n == " << n/2
        << "\nsquare root of n == " << sqrt((double) n)
        << '\n';
}
