/*
Author: Jeffrey Russell
Purpose: This program prints the first N values of the Fibonacci sequence.
         Additionally, it finds the largest such number which fits in an int.
*/

#include "../std_lib_facilities.h"

int main(){
  //Request the number of Fibonacci numbers to calculate.
  int N;
  cout << "Please enter the number of Fibonacci numbers you wish to calculate.";
  cin >> N;

  //Calculate the numbers.
  int fib1 = 0;
  int fib2 = 1;
  for(int i = 0; i < N; i++){
    fib2 = fib2 + fib1;
    fib1 = fib2 - fib1;
    cout << fib1 << "\n";
  }

  //Find the largest Fibonacci number which can fit into an int: We know we've
  //reached this when fib2 overflows.
  cout << "------------------------------------------\n";
  fib1 = 0;
  fib2 = 1;
  while(fib1 <= fib2){
    fib2 = fib2 + fib1;
    fib1 = fib2 - fib1;
  }
  cout << "The largest Fibonacci number which can fit into an int is "
       << fib1 << "\n";
}
