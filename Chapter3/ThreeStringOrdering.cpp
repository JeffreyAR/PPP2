/*
Author: Jeffrey Russell
Purpose: Accepts three strings as input and displays them in alphabetical order.
*/

#include "../std_lib_facilities.h"

int main(){

  //Request and store three strings.
  cout << "Please enter three strings: ";
  string s1,s2,s3,temp;
  cin >> s1 >> s2 >> s3;

  //Swap s1 and s2 if necessary.
  if(s1 > s2){
    temp = s1;
    s1 = s2;
    s2 = temp;
  }

  //Swap s2 and s3 if necessary.
  if(s2 > s3){
    temp = s2;
    s2 = s3;
    s3 = temp;
  }

  //Swap s1 and s2 if necessary.
  if(s1 > s2){
    temp = s1;
    s1 = s2;
    s2 = temp;
  }

  //Print the strings in alphabetical order.
  cout << s1 << ", " << s2 << ", " << s3 << "\n";
}
