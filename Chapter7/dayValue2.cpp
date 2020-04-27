/*
Author: Jeffrey Russell
Purpose: This program reads pairs of values from the user: a day of the week
         and a value. All the values for one day are collected and printed.
         The number of rejected values are also printed.
*/

#include "../std_lib_facilities.h"

//Structure for a day of the week.
struct weekday{
  string day;
  vector<int> values;
  weekday(string inDay): day(inDay) {};
};

//Create a vector holding each day of the week.
vector<weekday> days = {
  weekday("Sunday"), weekday("Monday"), weekday("Tuesday"), weekday("Wednesday"),
  weekday("Thursday"), weekday("Friday"), weekday("Saturday")
};

//Print out the days vector - each day, its values, and the sum of those values.
void printVector(){
  int sum = 0;
  for(int i = 0; i < days.size(); i++){
    cout << days[i].day << ":\n\t";
    if(days[i].values.size() == 0) cout << "No values entered.\n"; //Specify of no values entered for a day.
    else{
      for(int j = 0; j < days[i].values.size(); j++){
        cout << days[i].values[j] << " ";
        sum += days[i].values[j];
      }
      cout << "\n\tSum is " << sum << ".\n";
    }
    sum = 0;
  }
}

//Try to add a value to a day's values vector. If no correct day is found, return false.
bool incrementDay(string inDay, int value){
  inDay[0] = toupper(inDay[0]);
  for(int i = 0; i < days.size(); i++){
    if(days[i].day.substr(0,inDay.length()) == inDay){ //Check for equality only as far as inDay goes.
      days[i].values.push_back(value);
      return true;
    }
  }
  return false;
}

int main(){
  //Introduce user, intialize variables.
  cout << "Please enter day of the week and int pairs. Enter 'done' for the "
       << "day of the week when finished.\n";
  string day;
  int value;
  int wrong = 0;
  cin >> day;

  //Begin input loop until user enters done.
  while(day != "done"){
    //Read value, return error if not an int.
    cin >> value;
    if(!cin){
      cerr << "Error: Input for value not valid. Exiting...\n";
      return 1;
    }
    //Try to add to the days vector - increment wrong if it fails.
    if(!incrementDay(day, value)) wrong++;
    cin >> day;
  }

  //Print out values in each vector, their sums, and the number of rejected values.
  cout << "The values in each vector along with their sums are\n";
  printVector();
  cout << "The number of rejected values is " << wrong << ".\n";
}
