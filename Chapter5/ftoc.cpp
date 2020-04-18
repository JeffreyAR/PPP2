/*
Author: Jeffrey Russell
Purpose: This program converts from Celsius to Fahrenheit and vice versa.
         Temperatures below absolute zero give an exception.
*/

#include "../std_lib_facilities.h"

//Exceptions
class badFahrenheit{};
class badCelsius{};

//Converts fahrenheit to celsius.
double ftoc(double f){
  //Give an exception if f is below absolute zero.
  if(f < (9.0/5)*-273.15 + 32) throw badFahrenheit{};
  return (f - 32)*(5.0/9);
}

//Converts celsius to fahrenheit.
double ctof(double c){
  //Give an exception if c is below absolute zero.
  if(c < -273.15) throw badCelsius{};
  return (9.0/5)*c + 32;
}

int main(){
  //Request a mode from the user, then obtain the temperature they wish to convert.
  int mode;
  cout << "Please enter one to convert from fahrenheit to celsius or two to "
       << "convert from celsius to fahrenheit.";
  cin >> mode;
  if(mode != 1 && mode != 2){
    cerr << "Error: Invalid mode.\n";
    return 1;
  }
  double initialTemp;
  double finalTemp;
  cout << "Please enter the temperature you wish to convert.";
  cin >> initialTemp;
  //Handle bad input
  if(!cin){
    cout << "Error: Something besides a double was entered.\n";
    return 1;
  }

  //From Fahrenheit to Celsius
  if(mode == 1){
    try{
      finalTemp = ftoc(initialTemp);
    }
    catch(badFahrenheit){
      cerr << "Error: Temperature entered was below absolute zero.\n";
      return 1;
    }
  }
  //From Celsius to Fahrenheit
  else{
    try{
      finalTemp = ctof(initialTemp);
    }
    catch(badCelsius){
      cerr << "Error: Temperature entered was below absolute zero.\n";
      return 1;
    }
  }
  cout << finalTemp << "\n";
}
