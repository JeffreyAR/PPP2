#include "../std_lib_facilities.h"

//Problem 5 asks for a modification of this program; I am choosing not
//to do this as I understand what the difference is between int computation
//and double computation.
int main(){
  cout << "Please enter two integers for comparison: ";
  int val1,val2;
  cin >> val1 >> val2;
  cout << "The smaller of the two is " << (val1<val2 ? val1 : val2)
        << " and the larger is " << (val1>val2 ? val1 : val2) << ".\n";
  cout << "Their sum is " << (val1 + val2) << "\ntheir difference is "
        << val1 - val2 << "\ntheir product is " << val1 * val2
        << "\ntheir ratio is " << ((double) val1) / ((double) val2) << "\n";
}
