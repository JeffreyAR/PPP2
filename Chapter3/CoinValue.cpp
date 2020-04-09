#include "../std_lib_facilities.h"

void request(string coin){
  cout << "How many " << coin << " do you have?\n";
}

void output(int num, string coin){
  if(num != 1){
    if(coin == "penny") coin = "pennies";
    else coin += "s";
  }
  cout << "You have " << num << " " << coin << ".\n";
}

int main(){
  int pennies,nickels,dimes,quarters,half,total;
  request("pennies");
  cin >> pennies;
  request("nickels");
  cin >> nickels;
  request("dimes");
  cin >> dimes;
  request("quarters");
  cin >> quarters;
  request("half-dollars");
  cin >> half;
  total = pennies+5*nickels+10*dimes+25*quarters+50*half;
  output(pennies, "penny");
  output(nickels, "nickel");
  output(dimes, "dime");
  output(quarters, "quarter");
  output(half, "half-dollar");
  cout << "The value of all of your coins is " << total/100 << " dollars and "
        << total%100 << " cents.\n";
}
