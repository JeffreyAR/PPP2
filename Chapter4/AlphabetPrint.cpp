#include "../std_lib_facilities.h"

int main(){
  /*char iterate = 'a';
  cout << iterate << "\t" << int(iterate) << "\n";
  while(iterate != 'z'){
    iterate = char(iterate + 1);
    cout << iterate << "\t" << int(iterate) << "\n";
  }*/
  for(int i = 48; i <= 122; i++){
    if(isalnum(char(i))) cout << char(i) << " " << i << "\n";
  }
}
