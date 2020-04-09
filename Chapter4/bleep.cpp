/*
Author: Jeffrey Russell
Purpose: This program accepts as input a string and 'bleeps' some previously
         chosen words. This 'bleeped' string is printed as output.
*/

#include "../std_lib_facilities.h"

int main(){

  //Define vector containing words that should be bleeped
  vector<string> bleep = {"the", "hello", "hippo", "c++"};

  //For each word the user enters, bleep it if necessary and print it.
  for(string temp; cin>>temp; cout << "\n"){
    for(string x : bleep){

      //If temp equals x, replace temp with BLEEP
      if(temp == x){
        temp = "BLEEP";
      }
    }
    //Print temp.
    cout << temp << " ";
  }
}
