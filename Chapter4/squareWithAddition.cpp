/*
Author: Jeffrey Russell
Purpose: This program calculates the square of all integers from 0 to 99 using
         repeated addition and prints the results.
*/

#include "../std_lib_facilities.h"

//Accepts an integer x as input, calculates its square using repeated addition,
//and returns the result.
int square(int x){
  int result = 0;

  //Add x to result x times.
  for(int i = 0; i < x; i++){
    result += x;
  }
  return result;
}

int main(){

  //Prints every integer from 0 to 99 along with its square.
  for(int i = 0; i < 100; i++){
    cout << i << '\t' << square(i) << '\n';
  }
}
