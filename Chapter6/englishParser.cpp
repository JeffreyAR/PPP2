/*
Author: Jeffrey Russell
Purpose: This program parses a very small subset of the English language.

It occurs to me only after writing and testing the program that the question
did not ask for the English grammar including the article from the previous
exercise. However, it seems silly to remove functionality, so I'm going to leave
it as is since it correctly handles anything without articles anyway.
*/

#include "../std_lib_facilities.h"

//Define a string_stream class to help parse sentences.
class string_stream{
public:
  string get();
  void putback(string read);
  void clear();
private:
  bool full = false;
  string hold;
};

//If a string is being held, return it. Otherwise, return the next string from cin.
string string_stream::get(){
  if(full == true){
    full = false;
    return hold;
  }
  string next;
  cin >> next;
  return next;
}

//Hold the string 'read'. If a string is already being held, give an error as well.
void string_stream::putback(string read){
  if(full == true){
    cerr << "Error: hold already full.\n";
  }
  full = true;
  hold = read;
}

//Clear the string being held by the string_stream.
void string_stream::clear(){
  hold = "";
  full = false;
}

//Initialize the string_stream, forward declaration of sentence.
string_stream ss;
bool sentence(string word);

//Check if the vector valid holds the string word. Return true if so, false otherwise.
bool contains(vector<string> valid, string word){
  for(int i = 0; i < valid.size(); i++){
    if(valid[i] == word) return true;
  }
  return false;
}

//Check to see if word is a verb. We only call this after a noun and thus read
//a character ahead, so if this isn't a verb, put it back. This mainly
//makes sure periods will be read. Return true if a verb, false otherwise.
bool verb(string word){
  vector<string> valid = {"rules", "fly", "swim"};
  bool result = contains(valid, word);
  if(!result) ss.putback(word);
  return contains(valid, word);
}

//Check to see if word is a noun. If so, check if the next word is a verb.
//Return true if both of the previous hold, false otherwise.
bool noun(string word){
  vector<string> valid = {"birds", "fish", "C++"};
  string next;
  if(contains(valid, word)){
    next = ss.get();
    return verb(next);
  }
  return false;
}

//Check if the word is a conjunction. If so, see if the rest of the input forms
//a sentence. If so, return true. Otherwise, false.
bool conjunction(string word){
  vector<string> valid = {"and", "or", "but"};
  string next;
  if(contains(valid, word)){
    next = ss.get();
    return sentence(next);
  }
  return false;
}

//Check to see if word is an article. If so, check to see if the rest of the
//input forms a sentence. If so, return true. Otherwise, false.
bool article(string word){
  vector<string> valid = {"the"};
  string next;
  if(contains(valid, word)){
    next = ss.get();
    return sentence(next);
  }
  return false;
}

//Check to see if the input forms a sentence. If so, return true. Otherwise, false.
bool sentence(string word){
  bool first = true;
  while(true){

    //Find out what part of speech the current word is. A sentence can't start
    //with a preposition, so don't check that until we've had a sentence of some
    //kind come first.
    if(article(word)) first = false;
    else if(noun(word)) first = false;
    else if(!first && conjunction(word)){}

    //If the current word doesn't match any recognized part of speech or
    //it does but does not form a sentence, then the input isn't a sentence.
    //Return false.
    else{
      while(word != ".") word = ss.get();
      ss.putback(word);
      return false;
    }
    word = ss.get();

    //If we have finished parsing the input and the next string is a period,
    //then the whole input is a sentence. Return true.
    if(word == "."){
      ss.putback(word);
      return true;
    }
  }
}

int main(){

  //Begin program, initialize variables.
  cout << "Please enter a sentence to be parsed.\n";
  string word;
  bool valid;
  string okay = "OK";
  while(true){

    //Until the user enters a 'q', scan user input to see if a sentence has been
    //entered. If so, print OK. Otherwise, print not OK. Clear string_stream
    //after each parse.
    word = ss.get();
    if(word == "q") break;
    valid = sentence(word);
    if(!valid) okay = "not OK";
    cout << okay << "\n";
    okay = "OK";
    ss.clear();
  }
}
