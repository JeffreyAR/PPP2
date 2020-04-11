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
  int average = (smallest + largest) / 2;;
  char answer;
  bool guessed = false;

  //Begin questions.
  cout << "Please pick a number from 1 to 100." << '\n';
  while(!guessed){

    //If there are only two possible numbers left, we may as well just ask
    //if one of them is right. If not, the other is the answer.
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

    //Otherwise, try to narrow the range of possible answers by dividing the
    //size of the range in half.
    else{
      cout << "Is your number less than or equal to " << average
           << "? Enter y for yes, n for no.";
           cin >> answer;

           //If yes, we have a new upper bound. If no, a new lower bound.
           switch(answer){
             case 'y':
              largest = average;
              break;
             case 'n':
              smallest = average + 1;
              break;
           }

       //Redefine average. If the upper and lower bounds are the same, then we
       //have the correct answer.
       average = (smallest + largest) / 2;
       if(largest == smallest) guessed = true;
    }
  }

  //Output the user's number.
  cout << "I know! Your number is " << smallest << "!\n";
  return count;
}
