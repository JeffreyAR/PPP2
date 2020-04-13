#include "../std_lib_facilities.h"

int main(){

  //Request input from the user.
  cout << "Please enter any number of strings followed by the '|' symbol.";

  //Initialize vector holding user input.
  string next;
  vector<string> userInput;
  while(cin >> next && next != "|") userInput.push_back(next);

  //Sort the user inputs, iterate through, and fine the integers which appear
  //most. It will be easier if the integers are consecutive.
  sort(userInput);
  int most = 0;
  vector<string> mode;
  string current = userInput[0];
  int repeated = 0;
  for(int i = 0; i < userInput.size(); i++){

    //If either we are on a new integer or are at the end of the list,
    //see if the current integer is a mode. If so, replace the old vector if
    //this is a new max. Otherwise, push onto the mode vector.
    if(userInput[i] != current){
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

  //We don't check if the last element of the vector is a mode in the loop, so
  //do it now.
  if(repeated > most){
    mode.clear();
    mode.push_back(current);
    most = repeated;
  }
  else if(repeated == most){
    mode.push_back(current);
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
    for(string x : mode) cout << x << "\n";
    cout << "These each appear " << most << " times.\n";
  }
  else if(mode.size() * most == userInput.size()){
    cout << "Wow, every element of this data is a mode. Not a very interesting dataset."
         << " Each element appears " << most << " times.\n";
  }

  //Output the min and max as well.
  cout << "Additionally, the minimum string input is '" << userInput[0]
       << "' and the maximum string input is '" << userInput[userInput.size()-1]
       << "'.\n";
}
