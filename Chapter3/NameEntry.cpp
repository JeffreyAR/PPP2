/*
Author: Jeffrey Russell
Purpose: This program was modified in the text several times. The purpose in
         most cases is to take the users first name and possible some other
         information as input and output a greeting. The exception is a version
         which takes in two names and outputs their order.
*/

#include "../std_lib_facilities.h"

//Outputs a greeting based on the first name of the user.
void first(){

  //Request and store the first name of the user.
  cout << "Please enter your first name:\n";
  string first_name;
  cin >> first_name;

  //Output a greeting.
  cout << "Hello, " << first_name << "!\n";
}

//Outputs a greeting based on the first name and age of the user.
void age(){

  //Request and store the first name and age of the user.
  cout << "Please enter your first name and age:\n";
  string first_name;
  double age = -1;
  cin >> first_name >> age;

  //Output a greeting.
  cout << "Hello, " << first_name << " (age " << age*12 << " months)!\n";
}

//Outputs a greeting based on the first and last name of the user.
void second(){

  //Request and store the first and last name of the user.
  cout << "Please enter your first and second names\n";
  string first;
  string second;
  cin >> first >> second;

  //Concatenate the first and last name, output a greeting.
  string name = first + ' ' + second;
  cout << "Hello, " << name << '\n';
}

//Takes in two names and outputs their order alphabetically.
void two(){

  //Request and store two names.
  cout << "Please enter two names\n";
  string first;
  string second;
  cin >> first >> second;

  //Output the order of the two names, or state that they are the same.
  if(first == second) cout << "that's the same name twice\n";
  if(first < second) cout << first << " is alphabetically before " << second << '\n';
  else cout << first << "is alphabetically before " << second << '\n';
}

int main(){

  //Ask the user which version of the program they which to run.
  int mode;
  cout << "Enter a mode:\n"
        << "1. First name only\n"
        << "2. First name and age\n"
        << "3. First name and second name\n"
        << "4. Two names\n";
  cin >> mode;

  //Run the corresponding version of the program.
  switch(mode){
    case 1:
      first();
      break;
    case 2:
      age();
      break;
    case 3:
      second();
      break;
    case 4:
      two();
      break;
    default:
      cout << "Error: Requested mode does not exist.\n";
      break;
  }
}
