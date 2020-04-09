/*
Author: Jeffrey Russell
Purpose: Accepts a currency selected by the user and an amount of said currency
         from the user. The program converts this to dollars and outputs the
         result.
*/

#include "../std_lib_facilities.h"

int main(){
  //Request and store the currency to convert from the user.
  cout << "Please enter whether you would like to convert "
        << " yen (y), euros (e), pounds (p), yuan (u), or kroner (k) to dollars: ";
  char mode;
  cin >> mode;

  //Request and store the amount to convert from the user.
  cout << "Please enter the amount of currency you are converting: ";
  double amount;
  cin >> amount;

  //Calculate the dollar amount based upon the selected currency. Call the user
  //silly if they try to convert dollars to dollars. Quit if an unexpected
  //character is entered.
  double total;
  string currency;
  string plural;
  switch(mode){
  case 'y':
    total = .0092 * amount;
    currency = "yen";
    break;
  case 'e':
    total = 1.08 * amount;
    currency = (amount != 1 ? "euros" : "euro");
    break;
  case 'p':
    total = 1.22 * amount;
    currency = (amount != 1 ? "pounds" : "pound");
    break;
  case 'u':
    total = .14 * amount;
    currency = "yuan";
    break;
  case 'k':
    total = .095 * amount;
    currency = "kroner";
    break;
  case 'd':
    cout << "Yes, you're very silly.\n";
    return 0;
  default:
    cout << "I don't seem to recognize " << mode << ".\n";
    return -1;
  }

  //Tell the user how much their currency is worth in dollars.
  plural = (total != 1 ? "dollars" : "dollar");
  cout << amount << " " << currency << " is equal to " << total << " "
        << plural << ".\n";
}
