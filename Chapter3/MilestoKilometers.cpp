/*
Author: Jeffrey Russell
Purpose: Accept as input from the user some number of miles. Convert this to
         kilometers and output this to the user.
*/

#include "../std_lib_facilities.h"

int main(){

  //Request and store some number of miles; define the conversion as a
  //constant. Initialize miles as -1 for error handling.
  double miles = -1;
  const double KILOMETERS_PER_MILE = 1.609;
  cout << "Please enter the number of miles:\n";
  cin >> miles;

  //Output the equivalent number of kilmeters.
  cout << "This is equal to " << miles*KILOMETERS_PER_MILE << " kilometers.\n";
}
