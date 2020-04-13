/*
Author: Jeffrey Russell
Purpose: This program finds n prime numbers where n is provided by the user.
         The method used is to check if the current number is divisible by any
         previous prime.
*/

#include "../std_lib_facilities.h"

int main(){

  //Initialize prime vector and other variables.
  vector<int> primes;
  int numPrimes = 0;
  bool divisible = false;

  //Obtain the number of primes desired from the user.
  cout << "Please enter the number of primes you wish to generate.";
  int n;
  int i = 2;
  cin >> n;

  //Loop over integers from 2 to 100. If i is not divisible by any previous prime,
  //add it to the vector.
  while(numPrimes < n){
    for(int x : primes){
      if(i % x == 0) divisible = true;
    }
    if(!divisible){
      primes.push_back(i);
      numPrimes++;
    }
    divisible = false;
    i++;
  }

  //Print out the primes found.
  for(int x : primes){
    cout << x << "\n";
  }
}
