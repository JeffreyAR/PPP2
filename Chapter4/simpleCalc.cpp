/*
Author: Jeffrey Russell
Purpose: This program is a simple calculator. It can add, multiply, subtract, or
         divide two input values from the user.
*/

#include "../std_lib_facilities.h"

int main(){
  //Greet the user and prompt them for and operation and two operands.
  cout << "Hello! Welcome to simpleCalc!\n";
  double op1;
  double op2;
  char operation;
  cout << "Please input an equation of the form a + b, a - b, a * b, or a / b. "
       << "Note that the spaces are required.";
  cin >> op1 >> operation >> op2;

  //Depending on the operation, return the result on the given oeprands.
  //If we don't recognize the operation, alert the user.
  switch(operation){
    case '+':
      cout << "The sum of " << op1 << " and " << op2 << " is " << op1 + op2
           << ".\n";
      break;
    case '-':
      cout << "The difference between " << op1 << " and " << op2 << " is "
           << op1 - op2 << ".\n";
      break;
    case '*':
      cout << "The product of " << op1 << " and " << op2 << " is "
           << op1 * op2 << ".\n";
      break;
    case '/':
      cout << "The ratio between " << op1 << " and " << op2 << " is "
           << op1 / op2 << ".\n";
      break;
    default:
      cout << "Oops - I don't recognize that operation. Please try again.\n";
      break;
  }
  cout << "Thank you for using simpleCalc!\n";
}
