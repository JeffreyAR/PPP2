/*
Author: Jeffrey Russell
Purpose: This program is an implementation of the "Bulls and Cows" game. It
         runs until the user guesses the number correctly.
*/

#include "../std_lib_facilities.h"

int main(){

  //Have the user enter a seed to generate a random game. If an invalid input
  //is entered, end with an error.
  cout << "Please enter an integer at least 4 digits to generate a game.\n";
  int seed;
  cin >> seed;
  if(seed / 1000 == 0){
    cerr << "Error: The seed entered is less than 4 digits.\n";
    return 1;
  }

  //Generate the "Bulls and Cows" vector.
  constexpr int RANDOM_GENERATION_NUMBER = 52;
  seed *= 52;
  if(seed < 0) seed *= -1;
  vector<int> bullCow(4);
  //I know this is gross, please forgive me
  vector<int> chosen = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for(int i = 0; i < 4; i++){
    //To get a number, mod seed by 10 and use the remainder. If taken, add three
    //until you reach an unused number. Divide by 10 at the end for a new number.
    bullCow[i] = seed % 10;
    cout << bullCow[i] << "\n";
    while(chosen[bullCow[i]] == 1){
      bullCow[i] += 3;
      bullCow[i] %= 10;
    }
    chosen[bullCow[i]] = 1;
    seed /= 10;
  }

  //Introduce and play the game.
  bool won = false;
  int guess;
  int curGuess;
  int bulls = 0;
  int cows = 0;
  cout << "Welcome! If any of the digits you guess are correct and in the "
       << "correct place, you'll get a 'bull'. If the digits are correct but "
       << "in the wrong place, you'll get a 'cow'.";
  while(!won){
    cout << "Enter a four digit number.";
    cin >> guess;

    //Check that guess is valid, otherwise continue.
    if(!cin) cout << "That's not a four digit number!\n";
    else{
      //Calculate and return bulls and cows.
      curGuess = guess;
      for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
          if(bullCow[j] == curGuess % 10){
            if(i == j) bulls++;
            else cows++;
          }
        }
        curGuess /= 10;
      }
      cout << "You got " << bulls << " bulls and " << cows << " cows.\n";

      //Check if user won, reset variables.
      if(bulls == 4) won = true;
      bulls = 0;
      cows = 0;
      curGuess = 0;
    }
  }

  cout << "Oh, you won! Great job!\n";
}
