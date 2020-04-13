/*
Author: Jeffrey Russell
Purpose: This program implements a map using two vectors.
*/

#include "../std_lib_facilities.h"

int main(){

  //Instruct the user to enter name and value pairs, initialize vectors.
  cout << "Please enter any number of name and value pairs, where the names"
       << " are strings and the values are ints. Please enter 'NoName 0' when"
       << " you are finished.\n";
  vector<string> names;
  vector<int> scores;

  //Initialize temp name and temp score for user input.
  string name;
  int score;
  bool repeat = false;
  cin >> name >> score;

  while(name != "NoName" || score != 0){
    for(string x : names){
      if(x == name){
        cout << "Error: duplicate name entered. Please try again.\n";
        repeat = true;
      }
    }
    if(!repeat){
      names.push_back(name);
      scores.push_back(score);
    }
    cin >> name >> score;
    repeat = false;
  }

  for(int i = 0; i < names.size(); i++){
    cout << names[i] << ": " << scores[i] << "\n";
  }
}
