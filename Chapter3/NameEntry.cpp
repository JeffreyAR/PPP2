#include "../std_lib_facilities.h"

void first(){
  cout << "Please enter your first name:\n";
  string first_name;
  cin >> first_name;
  cout << "Hello, " << first_name << "!\n";
}

void age(){
  cout << "Please enter your first name and age:\n";
  string first_name;
  double age = -1;
  cin >> first_name >> age;
  cout << "Hello, " << first_name << " (age " << age*12 << " months)!\n";
}

void second(){
  cout << "Please enter your first and second names\n";
  string first;
  string second;
  cin >> first >> second;
  string name = first + ' ' + second;
  cout << "Hello, " << name << '\n';
}

void two(){
  cout << "Please enter two names\n";
  string first;
  string second;
  cin >> first >> second;
  if(first == second) cout << "that's the same name twice\n";
  if(first < second) cout << first << " is alphabetically before " << second << '\n';
  else cout << first << "is alphabetically before " << second << '\n';
}

int main(){
  int mode;
  cout << "Enter a mode:\n"
        << "1. First name only\n"
        << "2. First name and age\n"
        << "3. First name and second name\n"
        << "4. Two names\n";
  cin >> mode;
  if(mode==1) first();
  if(mode==2) age();
  if(mode==3) second();
  if(mode==4) two();
}
