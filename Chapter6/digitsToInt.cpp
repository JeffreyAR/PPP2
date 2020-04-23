/*
Author: Jeffrey Russell
Purpose: This program takes in a number with up to four digits and outputs
         each digit as an integer. For example, the input 123 would generate
         the output "1 hundred and 2 tens and 3 ones.""
*/

#include "../std_lib_facilities.h"

int main(){
  //Obtain input from the user, define constants.
  constexpr int MAX_SIZE_INPUT = 10000;
  int digits;
  int tempDigits;
  cout << "Please enter an integer which is at most four digits.\n";
  cin >> digits;
  tempDigits = digits;

  //Handle invalid input, either if it could not be read or if it has more than
  //four digits.
  if(!cin){
    cerr << "Error: Input is not an integer. Exiting...\n";
    return 1;
  }
  else if(digits / MAX_SIZE_INPUT >= 1){
    cerr << "Error: Input has too many digits. Exiting...\n";
    return 1;
  }

  //If the user entered zero, just give a hard coded message.
  if(digits == 0){
    cout << "0 is 0, nothing else to it.\n";
    return 0;
  }

  //Create vector to hold digits, extract digits from input and push onto vector.
  vector<int> intDigit;
  while(tempDigits > 0){
    intDigit.push_back(tempDigits % 10);
    tempDigits /= 10;
  }

  //Create the message to be output then print.
  vector<string> postfixes = {"one", "ten", "hundred", "thousand"};
  string result = ".\n";
  for(int i = 0; i < intDigit.size(); i++){
    if(i != 0) result = " and " + result; //Add and after the first one
    if(intDigit[i] != 1) result = "s" + result; //Make it plural if needed
    result = to_string(intDigit[i]) + " " + to_string(postfixes[i]) + result; //Add number and type of i
  }
  result = to_string(digits) + " is " + result;
  cout << result;
}
