/*
Author: Jeffrey Russell
Purpose: This program finds all prime numbers from 1 to max, where max is
         provided by the user. The algorithm used is the Sieve of Eratosthenes.
*/

#include "../std_lib_facilities.h"

int main(){

  //Ask the user to input max.
  cout << "Please enter the max value you wish to search through.";
  int max;
  cin >> max;

  //Initialize prime vector and other variables.
  int cur = 1;
  bool primes[max] = {0};

  //Loop through all numbers from 2 to 100. If the current value of i has not
  //had any divisors, mark every multiple of i as having a divisor.
  for(int i = 2; i < max; i++){
    if(primes[i] == false){
      cur = i;
      for(int j = 2; cur*j < max; j++){
        primes[cur*j] = true;
      }
    }
  }

  //Print out every number which never had a divisor.
  for(int i = 2; i < max; i ++){
    if(primes[i] == false) cout << i << "\n";
  }
}
