#include "../std_lib_facilities.h"

int main(){
  cout << "Please enter three integers: ";
  int i1,i2,i3;
  cin >> i1 >> i2 >> i3;
  if(i1 > i2){
    i1 = i1 + i2;
    i2 = i1 - i2;
    i1 = i1 - i2;
  }
  if(i2 > i3){
    i2 = i2 + i3;
    i3 = i2 - i3;
    i2 = i2 - i3;
  }
  if(i1 > i2){
    i1 = i1 + i2;
    i2 = i1 - i2;
    i1 = i1 - i2;
  }
  cout << i1 << ", " << i2 << ", " << i3 << "\n";
}
