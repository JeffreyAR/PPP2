/*
Author: Jeffrey Russell
Purpose: This program calculates how many squares are needed to reach certain
         amounts of rice if square 1 contains 1 piece of rice and each square
         doubles the amount from the previous square.
*/

#include "../std_lib_facilities.h"

int main(){

  //Declare variables - grainsSquare tracks the number of grains of rice on the
  //current square, grainsTotal the total number of grains.
  int grainsSquare = 1;
  int grainsTotal = 1;
  int i;

  //Run until we reach 1000000000 grains of rice.
  for(i = 1; grainsTotal < 1000000000; i++){
    grainsSquare *= 2;

    //If the total number before this loop is below a certain amount and
    //the total after is more than that amount, this is the least number of
    //square required to reach that amount. Print it.
    if(grainsTotal < 1000 && grainsTotal + grainsSquare >= 1000)
      cout << i + 1 << " squares are needed to have 1000 grains of rice.\n";
    if(grainsTotal <1000000 && grainsTotal + grainsSquare >= 1000000)
      cout << i + 1 << " squares are needed to have 1000000 grains of rice.\n";
    grainsTotal += grainsSquare;
  }

  //Print out the final number of squares.
  cout << i + 1 << " squares are needed to have 1000000000 grains of rice.\n";
}
