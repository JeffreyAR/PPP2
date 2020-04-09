/*
Author: Jeffrey Russell
*/

#include "../std_lib_facilities.h"

int main(){
  //Accept a double from the user. Continue running while the user supplies
  //doubles.
  double d1;
  double small = 1;
  double large = 0;
  while(cin >> d1){

    //Print out the double input from the user. Update the smallest and largest
    //values if necessary while notifying the user of this change.
    cout << d1 << "\n";
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
