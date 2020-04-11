/*
Author: Jeffrey Russell
Purpose: This program is a modification of the rice program to see how large a
         number ints and doubles fit.
*/

#include "../std_lib_facilities.h"

int main(){

  //Declare variables - grainsSquare tracks the number of grains of rice on the
  //current square, grainsTotal the total number of grains. doub variables do
  //the same, but are doubles and not ints.
  int grainsSquare = 1;
  int grainsTotal = 1;
  double doubSquare = 1;
  double doubTotal = 1;
  int i;

  //Run until all 64 square are filled.
  for(i = 1; i < 64; i++){
    grainsSquare *= 2;

    //If the variable overflows next step, print it out and the square we're on.
    if(grainsTotal + grainsSquare < grainsTotal){
      cout << grainsTotal << " is the most we can represent with an int.\n";
      cout << i << " is the number of squares we could do.\n";
    }
    grainsTotal += grainsSquare;
    doubSquare *= 2;

    //If the variable overflows next step, print it out and the square we're on.
    if(doubTotal + doubSquare < doubTotal){
      cout << doubTotal << " is the most we can represent with an int.\n";
      cout << i << " is the number of squares we could do.\n";
    }
    doubTotal += doubSquare;
  }
  //The double is supposed to run out of space by the end of this, but it
  //doesn't seem to. I'm not sure why.
}
