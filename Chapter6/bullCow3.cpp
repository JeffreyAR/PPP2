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
  string guess;
  int bulls = 0;
  int cows = 0;
  cout << "Welcome! If any of the letters you guess are correct and in the "
       << "correct place, you'll get a 'bull'. If the letters are correct but "
       << "in the wrong place, you'll get a 'cow'.\n";

  while(!done){
     //Generate the "Bulls and Cows" vector.
     vector<int> bullCow(4);
     //I know this is gross, please forgive me
     vector<int> chosen = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
     //Have the user enter a seed to generate a random game. If an invalid input
     //is entered, end with an error.
     cout << "Please enter any integer to produce a game.";
     int seed;
     cin >> seed;
     if(!cin){
       cerr << "Error: Invalid seed.\n";
       return 1;
     }
     randint(25);
     srand(seed);
     for(int i = 0; i < 4; i++){
       //Obtain each number with randint(25)
       bullCow[i] = randint(25);
       while(chosen[bullCow[i]] == 1){
         bullCow[i] += 3;
         bullCow[i] %= 26;
       }
       chosen[bullCow[i]] = 1;
     }

     //Convert bullCow to letters.
     for(int i = 0; i < 4; i++){
       bullCow[i] = (char) (bullCow[i] + 97);
     }

     while(!won){
       cout << "Enter a four letter string.";
       cin >> guess;

       //Calculate and return bulls and cows.
       for(int i = 0; i < 4; i++){
         for(int j = 0; j < 4; j++){
           if(bullCow[j] == guess[i]){
             if(i == j) bulls++;
             else cows++;
           }
         }
       }
       cout << "You got " << bulls << " bulls and " << cows << " cows.\n";

       //Check if user won, reset variables.
       if(bulls == 4) won = true;
       bulls = 0;
       cows = 0;
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
