/*
Author: Jeffrey Russell
Purpose: This program asks the user to enter their number of pennies, nickels,
         dimes, quarters, and half dollars. The program then tells the user how
         many of each coin they have, calculates the total value of their coins,
         and finally displays it to the user.
*/

#include "../std_lib_facilities.h"

//Accepts as input a string and asks the user how many of that string they have.
void request(string coin){
  cout << "How many " << coin << " do you have?\n";
}

//Accepts as input an integer num and a string coin. Outputs "You have 'num'
//'coin'". Used to tell the user how many of a coin they have.
void output(int num, string coin){
  if(num != 1){
    if(coin == "penny") coin = "pennies";
    else coin += "s";
  }
  cout << "You have " << num << " " << coin << ".\n";
}

int main(){

  //Initialize variables.
  int pennies,nickels,dimes,quarters,half,total;

  //Ask how many of each coin type the user has.
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

  //Calculate the total number of coins.
  total = pennies+5*nickels+10*dimes+25*quarters+50*half;

  //Report to the user how many they have of each coin and the total monetary
  //value of their change.
  output(pennies, "penny");
  output(nickels, "nickel");
  output(dimes, "dime");
  output(quarters, "quarter");
  output(half, "half-dollar");
  cout << "The value of all of your coins is " << total/100 << " dollars and "
        << total%100 << " cents.\n";
}
