/*
  Author: Jeffrey Russell
  Purpose: This program accepts two integers from the user and calculates either
           their permutation or combination.
*/

#include "../std_lib_facilities.h"

class fact_overflow_error{};

//Calculate factorial of a.
int factorial(int a){
  //Check pre-condition: a is nonnegative.
  if(a < 0){
    cerr << "Error: factorial recieved negative input.\n";
    return 1;
  }

  //Iterate to compute result.
  int result = 1;
  for(int i = 1; i <= a; i++){
    if(result * i < result) throw fact_overflow_error{};
    result *= i;
  }
  return result;
}

//Calculate the number of permutations of a objects in b slots.
int permutation(int a, int b){
  int result;
  try{ result = factorial(a) / factorial(a-b); }
  catch(fact_overflow_error){ throw fact_overflow_error{}; }
  return result;
}

//Calculate the number of combinations of a objects in b slots.
int combination(int a, int b){
  int perm = permutation(a,b);
  int result;
  try{ result = perm / factorial(b); }
  catch(fact_overflow_error){ throw fact_overflow_error{}; }
  return result;
}

int main(){
  //Get various input from the user.
  string mode;
  cout << "Please enter whether you wish to calculate a permutation or combination.\n"
       << "Enter p for permutation and c for combination.";
  cin >> mode;

  //Handle input errors for mode.
  if(mode != "c" && mode != "p"){
    cerr << "Error: Invalid mode.\n";
    return 1;
  }

  int b,a;
  cout << "Please enter the integers you wish to use.";
  cin >> a >> b;

  //Handle input errors for a and b.
  if(!cin){
    cerr << "Error: Reading of two integers unsuccessful.\n";
    return 1;
  }
  else if(a < b){
    cerr << "Error: Number of objects less than number of positions.\n";
    return 1;
  }
  else if(b < 1){
    cerr << "Error: Nonpositive integers entered.\n";
    return 1;
  }

  //Calculate and print result.
  int result;
  if(mode == "c"){
     try{
       result = combination(a,b);
     }
     catch(fact_overflow_error){
       cerr << "Error: Factorial overflowed.\n";
       return 1;
     }
  }
  else{
    try{
      result = permutation(a,b);
    }
    catch(fact_overflow_error){
      cerr << "Error: Factorial overflowed.\n";
      return 1;
    }
  }
  cout << to_string(result) << "\n";
}
