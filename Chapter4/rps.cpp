/*
Author: Jeffrey Russell
Purpose: This program plays Rock, Paper, Scissors with the user. A seed is
         provided by the user.
*/

#include "../std_lib_facilities.h"

int main(){

  //Obtain seed from user, define variables.
  cout << "Please enter a seed so we can play! Give a random integer.";
  int seed;
  int cur;
  cin >> seed;
  vector<string> move;

  //Use seed to fill move vector. Take the remainder of the seed mod 3, push
  //some move onto the vector, and divide the seed by 10 until it is 0.
  while(seed > 0){
    cur = seed % 3;
    switch(cur){
      case 0:
        move.push_back("scissors");
        break;
      case 1:
        move.push_back("paper");
        break;
      case 2:
        move.push_back("rock");
        break;
    }
    cout << cur << "\n";
    seed /= 10;
  }

  //Begin playing.
  cout << "Okay, I'm ready to play. Enter '|' when you're ready to stop.\n";
  cout << "Additionally, only use lowercase letters please.\n";
  string userMove = "";
  int i = 0;
  while(userMove != "|"){

    //Obtain user's move.
    cout << "Rock, paper, scissors, shoot!";
    cin >> userMove;

    //Use the user's move and the computer's move to determine the outcome.
    //Stop playing if | is input, return an error otherwise.
    if(userMove == "rock"){
      cout << "I pick " << move[i] << ".\n";
      if(move[i] == "paper") cout << "I win!\n";
      else if(move[i] == "rock") cout << "It's a tie.\n";
      else if(move[i] == "scissors") cout << "You win!\n";
    }
    else if(userMove == "paper"){
      cout << "I pick " << move[i] << ".\n";
      if(move[i] == "scissors") cout << "I win!\n";
      else if(move[i] == "paper") cout << "It's a tie.\n";
      else if(move[i] == "rock") cout << "You win!\n";
    }
    else if(userMove == "scissors"){
      cout << "I pick " << move[i] << ".\n";
      if(move[i] == "rock") cout << "I win!\n";
      else if(move[i] == "scissors") cout << "It's a tie.\n";
      else if(move[i] == "paper") cout << "You win!\n";
    }
    else if(userMove == "|") cout << "Okay, thanks for playing!\n";
    else cout << "Sorry, I don't recognize that move.\n";

    //Increment i for the next choice, if i is out of the vector's index,
    //start over.
    ++i;
    if(i >= move.size()) i = 0;
  }
}
