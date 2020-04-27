/*
Author: Jeffrey Russell
Purpose: This program prints the first N values of the Fibonacci sequence.
         Additionally, it finds the largest such number which fits in an int.
*/

#include "../std_lib_facilities.h"

constexpr int PRINT_UNTIL_OVERFLOW = 10000000;

int fib(int N){
  int fib1 = 0;
  int fib2 = 1;
  for(int i = 0; i < N; i++){
      fib2 = fib2 + fib1;
      fib1 = fib2 - fib1;
      if(N != PRINT_UNTIL_OVERFLOW) cout << fib1 << "\n";
      if(fib1 > fib2) return fib1;
  }
}

int main(){
  //Request the number of Fibonacci numbers to calculate, print them.
  int N;
  cout << "Please enter the number of Fibonacci numbers you wish to calculate.";
  cin >> N;
  fib(N);

  //Find the largest Fibonacci number which can fit into an int: We know we've
  //reached this when fib2 overflows.
  cout << "------------------------------------------\n";
  cout << "The largest Fibonacci number which can fit into an int is "
       << fib(PRINT_UNTIL_OVERFLOW) << "\n";
}
