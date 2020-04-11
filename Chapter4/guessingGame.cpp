/*
Author: Jeffrey Russell
Purpose: This program attempts to guess a number that the user is thinking of
         from 1 to 100. It succeeds in at most 7 questions.
*/

#include "../std_lib_facilities.h"

int main(){

  //Initialize variables.
  int smallest = 1;
  int largest = 100;
  int count = 0;
  int average = (smallest + largest) / 2;;
  char answer;
  bool guessed = false;

  //Begin questions.
  //cout << "Please pick a number from 1 to 100." << '\n';
  while(!guessed){
    count++;
    if(largest == smallest + 1){
      guessed = true;
      cout << "Is your number " << smallest << "?";
      cin >> answer;
      switch(answer){
        case 'n':
          smallest = largest;
          break;
        default:
          break;
          }
        }
    else{
      cout << "Is your number less than or equal to " << average
           << "? Enter y for yes, n for no.";
           cin >> answer;
           switch(answer){
             case 'y':
              largest = average;
              break;
             case 'n':
              smallest = average + 1;
              break;
           }
       average = (smallest + largest) / 2;
       if(largest == smallest) guessed = true;
    }
  }
  cout << "I know! Your number is " << smallest << "!\n";
  return count;
}
