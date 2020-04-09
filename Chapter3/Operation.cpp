#include "../std_lib_facilities.h"

int main(){
  cout << "Please enter an operation followed by two doubles ";
  string operation;
  double op1, op2;
  cin >> operation >> op1 >> op2;
  if(operation == "+" || operation == "plus") cout << op1 + op2;
  else if(operation == "-" || operation == "minus") cout << op1 - op2;
  else if(operation == "*" || operation == "mul") cout << op1 * op2;
  else if(operation == "/" || operation == "div") cout << op1 / op2;
  cout << "\n";
}
