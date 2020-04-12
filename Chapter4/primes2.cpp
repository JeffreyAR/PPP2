/*
Author: Jeffrey Russell
Purpose: This program is a modification of primes.cpp which finds all prime
         numbers from 1 to max, where max is input by the user.
*/

#include "../std_lib_facilities.h"

int main(){

  //Initialize prime vector and other variables.
  vector<int> primes;
  bool divisible = false;

  //Obtain max from the user.
  cout << "Please enter the upper bound on the primes we search for.";
  int max;
  cin >> max;

  //Loop over integers from 2 to 100. If i is not divisible by any previous prime,
  //add it to the vector.
  for(int i = 2; i <= max; i++){
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
