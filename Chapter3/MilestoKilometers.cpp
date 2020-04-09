#include "../std_lib_facilities.h"

int main(){
  double miles = -1;
  const double KILOMETERS_PER_MILE = 1.609;
  cout << "Please enter the number of miles:\n";
  cin >> miles;
  cout << "This is equal to " << miles*KILOMETERS_PER_MILE << " kilometers.\n";
}
