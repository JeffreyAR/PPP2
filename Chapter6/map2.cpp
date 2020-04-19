/*
Author: Jeffrey Russell
Purpose: This program implements a map using two vectors. After initialization,
         requests names from the user to print the corresponding score. Following
         this, the user may search for scores as well. Names with said score
         will be printed.
*/

#include "../std_lib_facilities.h"

class Name_value{
public:
  string name;
  int value;
};

int main(){

  //Instruct the user to enter name and value pairs, initialize vectors.
  cout << "Please enter any number of name and value pairs, where the names"
       << " are strings and the values are ints. Please enter 'NoName 0' when"
       << " you are finished.\n";
  vector<Name_value> nvMap;

  //Initialize temp name and temp score for user input. Handle invalid input.
  Name_value nvTemp;
  bool repeat = false;
  cin >> nvTemp.name >> nvTemp.value;
  if(!cin){
    cerr << "Error: Invalid value entered.\n";
    return 1;
  }

  while(nvTemp.name != "NoName" || nvTemp.value != 0){
    for(Name_value x : nvMap){
      if(x.name == nvTemp.name){
        cout << "Error: duplicate name entered. Please try again.\n";
        repeat = true;
      }
    }
    if(!repeat){
      nvMap.push_back(nvTemp);
    }
    cin >> nvTemp.name >> nvTemp.value;
    if(!cin){
      cerr << "Error: Invalid value entered.\n";
      return 1;
    }
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
    for(int i = 0; i < nvMap.size(); i++){
      if(nvMap[i].name == request){
        cout << nvMap[i].value << "\n";
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
  int score;

  while(cin >> score){
    for(int i = 0; i < nvMap.size(); i++){
      if(nvMap[i].value == score){
        cout << nvMap[i].name << "\n";
        found = true;
      }
    }
    if(found == false) cout << "Error: score not found\n";
    found = false;
  }

}
