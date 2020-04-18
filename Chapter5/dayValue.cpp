/*
Author: Jeffrey Russell
Purpose: This program reads pairs of values from the user: a day of the week
         and a value. All the values for one day are collected and printed.
         The number of rejected values are also printed.
*/

#include "../std_lib_facilities.h"

void printVector(vector<int> vect){
  int sum = 0;
  for(int i = 0; i < vect.size(); i++){
    cout << vect[i] << " ";
    sum += vect[i];
  }
  cout << "\nSum is " << sum << ".\n";
}

int main(){
  //Introduce user, intialize variables.
  cout << "Please enter day of the week and int pairs. Enter 'done' for the "
       << "day of the week when finished.\n";
  vector<int> sunday;
  vector<int> monday;
  vector<int> tuesday;
  vector<int> wednesday;
  vector<int> thursday;
  vector<int> friday;
  vector<int> saturday;
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
    //Add to appropriate vector, increment counter if not correct.
    if(day == "Sunday" || day == "sunday" || day == "Sun" || day == "sun"){
      sunday.push_back(value);
    }
    else if(day == "Monday" || day == "monday" || day == "Mon" || day == "mon"){
      monday.push_back(value);
    }
    else if(day == "Tuesday" || day == "tuesday" || day == "Tues" || day == "tues"){
      tuesday.push_back(value);
    }
    else if(day == "Wednesday" || day == "wednesday" || day == "Wed" || day == "wed"){
      wednesday.push_back(value);
    }
    else if(day == "Thursday" || day == "thursday" || day == "Thurs" || day == "thurs"){
      thursday.push_back(value);
    }
    else if(day == "Friday" || day == "friday" || day == "Fri" || day == "fri"){
      friday.push_back(value);
    }
    else if(day == "Saturday" || day == "saturday" || day == "Sat" || day == "sat"){
      saturday.push_back(value);
    }
    else wrong++;
    cin >> day;
  }

  //Print out values in each vector, their sums, and the number of rejected
  //values.
  cout << "The values in each vector along with their sums are\nSunday: ";
  printVector(sunday);
  cout << "Monday: ";
  printVector(monday);
  cout << "Tuesday: ";
  printVector(tuesday);
  cout << "Wednesday: ";
  printVector(wednesday);
  cout << "Thursday: ";
  printVector(thursday);
  cout << "Friday: ";
  printVector(friday);
  cout << "Saturday: ";
  printVector(saturday);
  cout << "The number of rejected values is " << wrong << ".\n";
}
