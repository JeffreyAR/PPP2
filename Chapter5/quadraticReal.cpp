/*
Author: Jeffrey Russell
Purpose: This program returns the solutions to an arbitrary quadratic equation
         if they are real, and gives an error otherwise.
*/

#include "../std_lib_facilities.h"

int main(){

  //Obtain the coefficients from the user.
  cout << "Please enter the coefficients a, b, and c of your quadratic equation.";
  int a,b,c;
  cin >> a >> b >> c;

  //Calculate the determinant to see if the solutions are real. If so,
  //calculate them. Otherwise, give an error.
  double det = b*b - 4*a*c;
  int x1, x2;
  if(det >= 0){
    x1 = (-b + sqrt(det))/(2*a);
    x2 = (-b - sqrt(det))/(2*a);
    cout << "The solutions are " << x1 << " and " << x2 << ".\n";
  }
  else{
    cerr << "Error: This equation has no real roots."
  }
}
