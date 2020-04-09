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
  double total = 0;
  int count = 0;
  const int METERS_TO_CENTIMETERS = 100;
  const double INCHES_TO_CENTIMETERS = 2.54;
  const double FEET_TO_CENTIMETERS = 12 * INCHES_TO_CENTIMETERS;

  //Accept a double from the user. Continue running while the user supplies
  //doubles.
  while(cin >> d1 >> unit){

    //Convert input to centimeters if necessary. Give error if unit is invalid.
    if(unit == "m") d1 *= METERS_TO_CENTIMETERS;
    else if(unit == "in") d1 *= INCHES_TO_CENTIMETERS;
    else if(unit == "ft") d1 *= FEET_TO_CENTIMETERS;
    else if(unit != "cm"){
      cout << "Error: Invalid unit. Valid units are cm, m, in, and ft.\n";
      unit = "error";
    }

    //Print out the double and unit input from the user. Update the smallest and
    //largest values if necessary while notifying the user of this change.
    //Skips if there was a unit error.
    if(unit != "error"){
      d1 /= METERS_TO_CENTIMETERS;
      cout << d1 << " m" << "\n";
      total += d1;
      count++;
    }
    if(small > large && unit != "error"){
      small = d1;
      large = d1;
      cout << "This is the smallest so far.\n" << "This is the largest so far.\n";
    }
    else if(d1 < small && unit != "error"){
      small = d1;
      cout << "This is the smallest so far.\n";
    }
    else if(d1 > large && unit != "error"){
      large = d1;
      cout << "This is the largest so far.\n";
    }
  }
  cout << "The smallest value entered is " << small << " m.\n"
       << "The largest value entered is " << large << " m.\n"
       << "The number of values entered is " << count << " .\n"
       << "The sum of the values entered is " << total << " m.\n";
}
