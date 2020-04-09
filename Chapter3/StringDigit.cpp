/*
Author: Jeffrey Russell
Purpose: Take as input from the user a spelled out version of a number.
         Output the numeric version if it is from one to ten, complain
         otherwise.
*/

#include "../std_lib_facilities.h"

int main(){

  //Request and store a spelled-out number.
  cout << "Please enter the spelled-out version of a one digit number: ";
  string digit;
  cin >> digit;

  //Output the correct number if it is single digit, complain otherwise.
  if(digit == "zero" || digit == "Zero") cout << 0;
  else if(digit == "one" || digit == "One") cout << 1;
  else if(digit == "two" || digit == "Two") cout << 2;
  else if(digit == "three" || digit == "Three") cout << 3;
  else if(digit == "four" || digit == "Four") cout << 4;
  else if(digit == "five" || digit == "Five") cout << 5;
  else if(digit == "six" || digit == "Six") cout << 6;
  else if(digit == "seven" || digit == "Seven") cout << 7;
  else if(digit == "eight" || digit == "Eight") cout << 8;
  else if(digit == "nine" || digit == "Nine") cout << 9;
  else cout << "I don't understand!";
  cout << "\n";
}
