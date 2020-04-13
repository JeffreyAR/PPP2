/*
Author: Jeffrey Russell
Purpose: This program finds all prime numbers from 1 to 100. The method used is
         to keep a vector of all previous primes found and check divisibility.
*/

#include "../std_lib_facilities.h"

int main(){

  //Initialize prime vector and other variables.
  vector<int> primes;
  bool divisible = false;

  //Loop over integers from 2 to 100. If i is not divisible by any previous prime,
  //add it to the vector.
  for(int i = 2; i <= 100; i++){
    for(int x : primes){
      if(i % x == 0) divisible = true;
    }
    if(!divisible) primes.push_back(i);
    divisible = false;
  }

  //Print out the primes found.
  for(int x : primes){
    cout << x << "\n";
  }
}
