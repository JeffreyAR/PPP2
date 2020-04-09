#include "../std_lib_facilities.h"

int main(){
  cout << "Please enter whether you would like to convert "
        << " yen (y), euros (e), pounds (p), yuan (u), or kroner (k) to dollars: ";
  char mode;
  cin >> mode;

  cout << "Please enter the amount of currency you are converting: ";
  double amount;
  cin >> amount;

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
    return 0;
  }
  plural = (total != 1 ? "dollars" : "dollar");
  cout << amount << " " << currency << " is equal to " << total << " "
        << plural << ".\n";
}
