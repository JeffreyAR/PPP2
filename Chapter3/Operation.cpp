/*
Author: Jeffrey Russell
Purpose: Accept as input an operation and two doubles. Preform the given
         operation on the provided doubles and output the result.
*/

#include "../std_lib_facilities.h"

int main(){

  //Request and store an operation and two doubles as operands.
  cout << "Please enter an operation followed by two doubles: ";
  string operation;
  double op1, op2;
  cin >> operation >> op1 >> op2;

  //Preform the given operation on the two operands, output the result.
  if(operation == "+" || operation == "plus") cout << op1 + op2;
  else if(operation == "-" || operation == "minus") cout << op1 - op2;
  else if(operation == "*" || operation == "mul") cout << op1 * op2;
  else if(operation == "/" || operation == "div") cout << op1 / op2;
  cout << "\n";
}
