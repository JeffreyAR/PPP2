/*
Author: Jeffrey Russell
Purpose: This program accepts various strings as input from the user in order
         to write a boilerplate letter to some person specified by the user.
         The letter is the output.
*/

#include "../std_lib_facilities.h"

int main(){

  //Request and store name of recipient.
  cout << "Enter the name of the person you want to write to:\n";
  string first_name;
  cin >> first_name;

  //Begin letter.
  cout << "Dear " << first_name << ",\n";
  cout << "\tHow are you? I'm doing pretty well. You're the best.\n";
  cout << "I'm not sure what else to say here. Do you have COVID-19?\n";
  cout << "I hope not. Anyway, that's all for now. Except for the next parts.\n";

  //Request and store the name of a friend of the user and recipient.
  string friend_name;
  cout << "Now enter the name of another friend.\n";
  cin >> friend_name;
  cout << "Have you seen " << friend_name << " lately?\n";

  //Request and store sex of the previously input friend.
  char friend_sex = 0;
  cout << "Enter 'm' if the second friend is a male, 'f' if a female.\n";
  cin >> friend_sex;

  //Write next line depending on the gender of the previously input friend.
  if(friend_sex == 'm'){
    cout << "If you see " << friend_name << " please ask him to call me.\n";
  }
  if(friend_sex == 'f'){
    cout << "If you see " << friend_name << " please ask her to call me.\n";
  }

  //Request and store the age of the recipient.
  int age;
  cout << "Please enter the age of the recipient.\n";
  cin >> age;

  //Give an error if the age given is either below 0 or very large.
  //Otherwise, continue letter and possibly add a line based on their age.
  if(age<0 || age>110) simple_error("you're kidding!");
  cout << "I hear you just had a birthday and you are " << age << " years old.\n";
  if(age<12) cout << "Next year you will be " << age+1 << ".\n";
  if(age==17) cout << "Next year you will be able to vote.\n";
  if(age>70) cout << "I hope you are enjoying retirement.\n";
  cout << "Yours sincerely,\n\nJeffrey Russell\n";
}
