/*
Author: Jeffrey Russell
Purpose: This program is a mnodification of simpleCalc. It accepts either single
         digit numbers as operands or spelled out versions of single digit
         numbers, which are converted to numbers using the algorithm from
         spelledIntConvert.
*/

#include "../std_lib_facilities.h"

//Forward declaration.
double convert(string x);

int main(){
  //Greet the user and prompt them for and operation and two operands.
  cout << "Hello! Welcome to simpleCalc!\n";
  string op1;
  string op2;
  double db1;
  double db2;
  char operation;
  cout << "Please input an equation of the form a + b, a - b, a * b, or a / b. "
       << "Note that the spaces are required. Additionally, a and b must be "
       << "either single digit numbers or their spelled out versions.";
  cin >> op1 >> operation >> op2;

  //Convert op1 and op2 to doubles using convert function.
  db1 = convert(op1);
  db2 = convert(op2);

  //Depending on the operation, return the result on the given oeprands.
  //If we don't recognize the operation, alert the user.
  switch(operation){
    case '+':
      cout << "The sum of " << db1 << " and " << db2 << " is " << db1 + db2
           << ".\n";
      break;
    case '-':
      cout << "The difference between " << db1 << " and " << db2 << " is "
           << db1 - db2 << ".\n";
      break;
    case '*':
      cout << "The product of " << db1 << " and " << db2 << " is "
           << db1 * db2 << ".\n";
      break;
    case '/':
      cout << "The ratio between " << db1 << " and " << db2 << " is "
           << db1 / db2 << ".\n";
      break;
    default:
      cout << "Oops - I don't recognize that operation. Please try again.\n";
      break;
  }
  cout << "Thank you for using simpleCalc!\n";
}

double convert(string x){
  if(x.length() == 1){
    for(int i = 0; i < 10; i++){
      if(to_string(i) == x) return i;
    }
  }
  else{
    vector<string> dict = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    double answer = -1;
    for(int i = 0; i < dict.size(); i++){
      if(dict[i] == x) answer = i;
    }
    return answer;
  }
}
