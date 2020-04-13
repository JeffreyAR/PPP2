/*
Author: Jeffrey Russell
Purpose: Calculates the mean and median of some temperatures which are
         specified by the user.
*/

#include "../std_lib_facilities.h"

int main(){

  //Populate vector with doubles given by user.
  vector<double> temps;
  for(double temp; cin>>temp;) temps.push_back(temp);

  //Compute and return the mean temperature.
  double sum = 0;
  int size = temps.size();
  for(int x: temps) sum += x;
  cout << "Average temperature: " << sum/size << '\n';

  //Compute and return the median temperature.
  sort(temps);
  cout << "Median temperature: "
       << (temps.size()%2==0 ? ((temps[size/2]+temps[size/2-1])/2):temps[size/2])
       << '\n';
}
