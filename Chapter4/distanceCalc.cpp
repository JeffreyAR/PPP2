/*
Author: Jeffrey Russell
Purpose: This program takes in a sequence of double values, which are
         interpreted as distances between cities. The total distance, smallest
         distance, largest distance, and average distance are returned.
*/

#include "../std_lib_facilities.h"

int main(){

  //Accept distances as input from user.
  vector<double> distances;
  for(double x = 0; cin >> x;) distances.push_back(x);

  //Find the smallest and largest distances. Calculate the total distance.
  double smallest = distances[0];
  double largest = distances[0];
  double total = 0;
  for(double x : distances){
    if(x < smallest) smallest = x;
    else if(x > largest) largest = x;
    total += x;
  }

  //Display the smallest distance, largest distance, total distance, and
  //average distance to the user.
  cout << "The smallest distance is " << smallest
       << " and the largest distance is " << largest
       << ".\nThe total distance is " << total
       << " and the average distance is " << total/distances.size() << '\n';
}
