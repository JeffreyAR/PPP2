/*
Author: Jeffrey Russell
Purpose: The user specifies some number of integers N followed by a sequences
         of integers. The sum of the first N integers in the sequence is returned.
         An error is thrown if N is greater than the number of integers entered.
*/

#include "../std_lib_facilities.h"

int main(){
  //Request number of integers to sum and sequence of integers.
  int N;
  vector<int> sequence;
  int next;
  cout << "Please enter the number of integers you wish to sum.";
  cin >> N;
  //Handle invalid input
  if(!cin){
    cerr << "Error: invalid input for N.\n";
    return 1;
  }
  cout << "Please enter a sequence of integers, terminated by '|'.";
  while(cin >> next) sequence.push_back(next);

  //Throw an error if the sequence of integers has size less than N.
  if(sequence.size() < N){
    cerr << "Error: The size of the integer sequence is smaller than the "
         << "number of integers to be summed.\n";
    return 1;
  }

  //Sum the first N integers in the sequence and print it.
  int sum = 0;
  for(int i = 0; i < N; i++) sum += sequence[i];
  cout << "The sum of the first " << N << " integers is " << sum << ".\n";
}
