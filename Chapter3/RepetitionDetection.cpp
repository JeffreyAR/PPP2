#include "../std_lib_facilities.h"

void exact(){
  string previous = " ";
  string current;
  while(cin >> current){
    if(previous == current) cout << "repeated word: " << current << '\n';
  previous = current;
  }
}

void related(){
  int number_of_words = 0;
  string previous = " ";
  string current;
  while(cin >> current){
    ++number_of_words;
    if(previous == current){
      cout << "word number " << number_of_words << " repeated: " << current << '\n';
    }
    previous = current;
  }
}

int  main(){
  int mode;
  cout << "Which mode?\n1. Exact\n2. Related\n";
  cin >> mode;
  if(mode == 1) exact();
  if(mode == 2) related();
}
