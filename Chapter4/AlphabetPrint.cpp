/*
Author: Jeffrey Russell
Purpose: This program checks if an integer corresponds to an alphanumeric
         character. If so, it prints the character and the integer. All
         alphanumeric characters are printed.
*/

#include "../std_lib_facilities.h"

int main(){

  //Loop through the integers which contain alphanumeric characters. If the
  //integer corresponds to an alphanumeric character, print both. 
  for(int i = 48; i <= 122; i++){
    if(isalnum(char(i))) cout << char(i) << " " << i << "\n";
  }
}
