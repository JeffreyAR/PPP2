/*
Author: Jeffrey Russell
*/

#include "../std_lib_facilities.h"

int main(){

  //Initialize variables and conversion constants.
  double d1;
  string unit;
  double small = 1;
  double large = 0;
  const double METERS_TO_CENTIMETERS = 100;
  const double INCHES_TO_CENTIMETERS = 2.54;
  const double FEET_TO_CENTIMETERS = 12 * INCHES_TO_CENTIMETERS;

  //Accept a double from the user. Continue running while the user supplies
  //doubles.
  while(cin >> d1 >> unit){

    //Convert input to centimeters if necessary.
    if(unit == "m") d1 *= METERS_TO_CENTIMETERS;
    else if(unit == "in") d1 *= INCHES_TO_CENTIMETERS;
    else if(unit == "ft") d1 *= FEET_TO_CENTIMETERS;

    //Print out the double and unit input from the user. Update the smallest and
    //largest values if necessary while notifying the user of this change.
    cout << d1 << " cm" << "\n";
    if(small > large){
      small = d1;
      large = d1;
      cout << "This is the smallest so far.\n" << "This is the largest so far.\n";
    }
    else if(d1 < small){
      small = d1;
      cout << "This is the smallest so far.\n";
    }
    else if(d1 > large){
      large = d1;
      cout << "This is the largest so far.\n";
    }
  }
}
