/*
Author: Jeffrey Russell
Purpose: The user specifies some number of doubles N followed by a sequences
         of doubles. The sum of the first N doubles in the sequence is returned.
         An error is thrown if N is greater than the number of doubles entered
         or if the sum of the doubles is not an integer. Additionally, a vector
         of size N-1 contains the difference between adjacent members of the
         sequence and is printed.
*/

#include "../std_lib_facilities.h"

int main(){
  //Request number of integers to sum and sequence of integers.
  int N;
  vector<double> sequence;
  double next;
  cout << "Please enter the number of doubles you wish to sum.";
  cin >> N;
  //Handle invalid input
  if(!cin){
    cerr << "Error: invalid input for N.\n";
    return 1;
  }
  cout << "Please enter a sequence of doubles, terminated by '|'.";
  while(cin >> next) sequence.push_back(next);

  //Throw an error if the sequence of integers has size less than N.
  if(sequence.size() < N){
    cerr << "Error: The size of the double sequence is smaller than the "
         << "number of doubles to be summed.\n";
    return 1;
  }

  //Sum the first N integers in the sequence and print it. Additionally, create
  //the difference vector and print it.
  double sum = 0;
  vector<double> difference;
  for(int i = 0; i < N; i++){
    sum += sequence[i];
    if(i > 0) difference.push_back(sequence[i] - sequence[i - 1]);
  }
  int testSum = sum;
  if(sum != testSum){
    cerr << "Error: sum is not an integer.\n";
    return 1;
  }
  cout << "The sum of the first " << N << " doubles is " << sum << ".\n";
  cout << "The differences between the first N adjacent doubles are:\n";
  for(int i = 0; i < difference.size(); i++) cout << difference[i] << "\n";
}
