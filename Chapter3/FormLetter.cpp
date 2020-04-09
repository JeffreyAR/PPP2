#include "../std_lib_facilities.h"

int main(){
  cout << "Enter the name of the person you want to write to:\n";
  string first_name;
  cin >> first_name;
  cout << "Dear " << first_name << ",\n";
  cout << "\tHow are you? I'm doing pretty well. You're the best.\n";
  cout << "I'm not sure what else to say here. Do you have COVID-19?\n";
  cout << "I hope not. Anyway, that's all for now. Except for the next parts.\n";
  string friend_name;
  cout << "Now enter the name of another friend.\n";
  cin >> friend_name;
  cout << "Have you seen " << friend_name << " lately?\n";
  char friend_sex = 0;
  cout << "Enter 'm' if the second friend is a male, 'f' if a female.\n";
  cin >> friend_sex;
  if(friend_sex == 'm'){
    cout << "If you see " << friend_name << " please ask him to call me.\n";
  }
  if(friend_sex == 'f'){
    cout << "If you see " << friend_name << " please ask her to call me.\n";
  }
  int age;
  cout << "Please enter the age of the recipient.\n";
  cin >> age;
  if(age<0 || age>110) simple_error("you're kidding!");
  cout << "I hear you just had a birthday and you are " << age << " years old.\n";
  if(age<12) cout << "Next year you will be " << age+1 << ".\n";
  if(age==17) cout << "Next year you will be able to vote.\n";
  if(age>70) cout << "I hope you are enjoying retirement.\n";
  cout << "Yours sincerely,\n\nJeffrey Russell\n";
}
