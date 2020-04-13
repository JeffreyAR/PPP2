/*
Author: Jeffrey Russell
Purpose: This program calculates the mode of a set of positive integers input by
         the user.
*/

#include "../std_lib_facilities.h"

int main(){

  //Request input from the user.
  cout << "Please enter any number of positive integers followed by the '|' symbol.";

  //Initialize vector holding user input.
  int next;
  vector<int> userInput;
  while(cin >> next) userInput.push_back(next);

  //Sort the user inputs, iterate through, and fine the integers which appear
  //most. It will be easier if the integers are consecutive.
  sort(userInput);
  int most = 0;
  vector<int> mode;
  int current = userInput[0];
  int repeated = 0;
  for(int i = 0; i < userInput.size(); i++){

    //If either we are on a new integer or are at the end of the list,
    //see if the current integer is a mode. If so, replace the old vector if
    //this is a new max. Otherwise, push onto the mode vector.
    if(userInput[i] != current || i == userInput.size() - 1){
      if(i == userInput.size() - 1) repeated++;
      if(repeated > most){
        mode.clear();
        mode.push_back(current);
        most = repeated;
      }
      else if(repeated == most){
        mode.push_back(current);
      }
      current = userInput[i];
      repeated = 0;
    }
    repeated++;
  }

  //Output either an error if no data was input, the unique mode if only one mode
  //exists, or every mode otherwise. Note if every element is a mode.
  if(userInput.size() == 0) cout << "I don't have anything to work with here.\n";
  else if(mode.size() == 1){
    cout << "The mode of this data is " << mode[0] << " which appears "
         << most << " times.\n";
  }
  else if(mode.size() * most != userInput.size()){
    cout << "There are multiple modes. The modes are:\n";
    for(int x : mode) cout << x << "\n";
    cout << "These each appear " << most << " times.\n";
  }
  else if(mode.size() * most == userInput.size()){
    cout << "Wow, every element of this data is a mode. Not a very interesting dataset."
         << " Each element appears " << most << " times.\n";
  }
}
