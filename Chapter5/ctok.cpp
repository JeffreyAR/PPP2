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

double ctok(double c)
{
  double k = c + 273.15;
  return k;
}

int main()
{
  //Request temperature in Celsius from user.
  double c = 0;
  cin >> c;

  //Check that user input is valid.
  if(c < -273.15){
    cerr << "Error: provided temperature less than absolute 0.\n";
    return 1;
  }

  //Calculate temperature in Kelvin.
  double k = ctok(c);
  cout << k << "\n";
}
