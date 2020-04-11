/*
Author: Jeffrey Russell
Purpose: This program converts spelled versions of single digit integers to
         an integer or converts single digit integers to a spelled out version.
*/

#include "../std_lib_facilities.h"

//Forward declarations.
void word(vector<string> dict);
void singleDigit(vector<string> dict);

int main(){
  //Initialize vector. Request for user to pick a mode.
  vector<string> dict = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  int mode;
  cout << "Would you like to:\n"
       << "\t1. Convert a word to a single digit integer, or\n"
       << "\t2. Convert a single digit integer to a word?\n";
  cin >> mode;

  //Switch to appropriate mode.
  switch(mode){
    case 1:
      word(dict);
      break;
    case 2:
      singleDigit(dict);
      break;
  }
}

void word(vector<string> dict){
  //Request and store the word to convert.
  string intWord;
  int answer = -1;
  cout << "Please enter the word you would like to convert.";
  cin >> intWord;

  //Search for the word, record index of occurence.
  for(int i = 0; i < dict.size(); i++){
    if(dict[i] == intWord) answer = i;
  }

  //If answer is unchanged, return an error. Otherwise, return the answer.
  if(answer == -1) cout << "Error: the word entered was not a single digit number.\n";
  else cout << answer << "\n";
  return;
}

void singleDigit(vector<string> dict){
  //Request and store the integer to convert.
  int chosen;
  cout << "Please enter a single digit integer to convert.";
  cin >> chosen;

  //If chosen is not single digit, return an error. Otherwise, return the word.
  if(chosen < 0 || chosen > 9) cout << "Error: this is not a single digit number.\n";
  else cout << dict[chosen] << "\n";
  return;
}
