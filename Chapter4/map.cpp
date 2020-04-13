/*
Author: Jeffrey Russell
Purpose: This program implements a map using two vectors. After initialization,
         requests names from the user to print the corresponding score. Following
         this, the user may search for scores as well. Names with said score
         will be printed.
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

  //Inform the user that they can retrieve any scores they like by inputting
  //the name of the person corresponding to the score they wish to retrieve.
  //Initialize variables for user input and error handling.
  cout << "Now, if you'd like to retrieve any scores, please enter the "
       << "corresponding name. Enter NoName to terminate.\n";
  string request;
  bool found = false;
  cin >> request;

  //While the user wants to search, try to match the entered name. If found,
  //return the corresponding score. Otherwise, return an error.
  while(request != "NoName"){
    for(int i = 0; i < names.size(); i++){
      if(names[i] == request){
        cout << scores[i] << "\n";
        found = true;
      }
    }
    if(!found) cout << "Error: name not found.\n";
    found = false;
    cin >> request;
  }

  //Now allow the user to search for scores and print all corresponding names.
  cout << "Now you may enter scores to search for names which match that score."
       << " Enter '|' when finished.\n";

  while(cin >> score){
    for(int i = 0; i < scores.size(); i++){
      if(scores[i] == score){
        cout << names[i] << "\n";
        found = true;
      }
    }
    if(found == false) cout << "Error: score not found\n";
    found = false;
  }

}
