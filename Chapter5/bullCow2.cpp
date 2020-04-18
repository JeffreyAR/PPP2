/*
Author: Jeffrey Russell
Purpose: This program is an implementation of the "Bulls and Cows" game. It
         runs until the user guesses the number correctly and wishes to stop
         playing.
*/

#include "../std_lib_facilities.h"

int main(){

  //Introduce and play the game.
  bool won = false;
  bool done = false;
  char choice;
  int guess;
  int curGuess;
  int bulls = 0;
  int cows = 0;
  cout << "Welcome! If any of the digits you guess are correct and in the "
       << "correct place, you'll get a 'bull'. If the digits are correct but "
       << "in the wrong place, you'll get a 'cow'.\n";

  while(!done){
     //Generate the "Bulls and Cows" vector.
     vector<int> bullCow(4);
     //I know this is gross, please forgive me
     vector<int> chosen = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
     //Have the user enter a seed to generate a random game. If an invalid input
     //is entered, end with an error.
     cout << "Please enter any integer to produce a game.";
     int seed;
     cin >> seed;
     if(!cin){
       cerr << "Error: Invalid seed.\n";
       return 1;
     }
     srand(seed);
     for(int i = 0; i < 4; i++){
       //Obtain each number with randint(10)
       bullCow[i] = randint(10);
       while(chosen[bullCow[i]] == 1){
         bullCow[i] += 3;
         bullCow[i] %= 10;
       }
       chosen[bullCow[i]] = 1;
     }
     while(!won){
       cout << "Enter a four digit number.";
       cin >> guess;

       //Check that guess is valid, otherwise continue.
       if(!cin){
         cerr << "Error: Not a four digit number.\n";
         return 1;
       }
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

     //Congratulate the user and see if they want to play again.
     //Give errors for invalid input.
     cout << "Oh, you won! Great job! Would you like to play again? Enter 'y'"
          << " for yes, 'n' for no.\n";
     cin >> choice;
     if(!cin){
       cerr << "Error: reading of user's choice failed. Exiting...\n";
       return 1;
     }
     switch(choice){
       case 'y':
          done = false;
          won = false;
          break;
       case 'n':
          done = true;
          break;
       default:
          cerr << "Error: Choice not recognized. Exiting...\n";
          return 1;
     }
  }

  cout << "Thanks for playing!\n";
}
