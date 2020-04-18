/*
Author: Jeffrey Russell
Purpose: This program originally had multiple errors. It now can convert from
         Celsius to Kelvin or vice versa. Errors are thrown for temperatures
         below absolute zero.
Corrected errors:
         -k in ctok changed from int to double to prevent loss of information
         -return int corrected to return k in ctok
         -semicolon added to return statement in ctok
         -cin >> d corrected to cin >> c in main
         -ctok("c") corrected to ctok(c) in main
         -Cout corrected to cout in main
         -Corrected new line in final print statement in main from character
          literal to string literal
*/

#include "../std_lib_facilities.h"

class Bad_celsius{};
class Bad_kelvin{};

double ctok(double c)
{
  //Check that the temperature is above absolute zero.
  if(c < -273.15) throw Bad_celsius{};

  //Calculate and return temperature in Kelvin.
  double k = c + 273.15;
  return k;
}

double ktoc(double k){
  //Check that the temperature is above absolute zero.
  if(k < 0) throw Bad_kelvin{};

  //Calculate and return temperature in Celsius.
  double c = k - 273.15;
  return c;
}

int main()
{
  //Request mode from user followed by appropriate temperature to convert.
  int mode;
  cout << "Please enter one for celsius to kelvin or two for kelvin to celsius.\n";
  cin >> mode;
  if(mode != 1 && mode != 2){
    cerr << "Error: Invalid mode.\n";
    return 1;
  }
  cout << "Please enter the temperature you wish to convert.";
  double convert = 0;
  cin >> convert;


  //Calculate temperature according to the mode input previously.
  double finalTemp;
  if(mode == 1){
    try{
      finalTemp = ctok(convert);
    }
    catch(Bad_celsius){
      cerr << "Error: Celsius temperature provided to conversion function is less"
           << " than absolute zero.\n";
      return 1;
    }
  }
  else{
    try{
      finalTemp = ktoc(convert);
    }
    catch(Bad_kelvin){
      cerr << "Error: Celsius temperature provided to conversion function is less"
           << " than absolute zero.\n";
      return 1;
    }
  }
  cout << finalTemp << "\n";
}
