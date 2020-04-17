/*
As this code was largely provided by the text, I do not claim to be the author.
Purpose: This program originally had multiple errors, but attempts to convert
         temperatures from Celsius to Kelvin.
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

double ctok(double c)
{
  //Check that function input is valid.
  if(c < -273.15){
    throw Bad_celsius{};
  }

  //Calculate and return temperature in Kelvin.
  double k = c + 273.15;
  return k;
}

int main()
{
  //Request temperature in Celsius from user.
  double c = 0;
  cin >> c;


  //Calculate temperature in Kelvin. Catch exceptions given by bad input to
  //ctok.
  try{
    double k = ctok(c);
    cout << k << "\n";
  }
  catch(Bad_celsius){
    cerr << "Error: Celsius temperature provided to conversion function is less"
         << " than absolute zero.\n";
    return 1;
  }
}
