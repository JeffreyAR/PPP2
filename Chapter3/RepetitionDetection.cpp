/*
Author: Jeffrey Russell
Purpose: Runs one of two modes. Either detects whether a string is repeated
         and outputs repreated words, or output if a string is repeated and
         where this repetition occurs. In either case, the string is accepted
         as input from the user.
*/

#include "../std_lib_facilities.h"

//While there is input, scan it and check to see if any words are repreated
//consecutively. If so, output the repeated word.
void exact(){

  //Take a string as input from the user.
  string previous = " ";
  string current;
  while(cin >> current){

    //If the current word is the same as the previous, print it.
    if(previous == current) cout << "repeated word: " << current << '\n';
    previous = current;
  }
}

//While there is input, scan it and check to see if any words are repreated
//consecutively. If so, output the repeated word and where it occurs.
void related(){

  //Take a string as input from the user.
  int number_of_words = 0;
  string previous = " ";
  string current;
  while(cin >> current){

    //Increment the current number of words.
    ++number_of_words;

    //If the current word is the same as the previous, print it with its
    //position.
    if(previous == current){
      cout << "word number " << number_of_words << " repeated: " << current << '\n';
    }
    previous = current;
  }
}

int  main(){
  //Ask the user which mode to run.
  int mode;
  cout << "Which mode?\n1. Exact\n2. Related\n";
  cin >> mode;

  //Run the corresponding mode.
  switch(mode){
    case 1:
      exact();
      break;
    case 2:
      related();
      break;
    default:
      cout << "Error: Requested mode does not exist.\n";
      break;
  }
}
