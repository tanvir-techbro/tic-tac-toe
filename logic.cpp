#include <iostream>
#include <ctime>
#include <cmath>
#include "logic.h"

//draw board after every move.
void draw_board(char *spaces){

  std::cout << '\n';

  std::cout << "     |     |     " << '\n';
  std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "   " << '\n';
  std::cout << "_____|_____|_____" << '\n';

  std::cout << "     |     |     " << '\n';
  std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "   " << '\n';
  std::cout << "_____|_____|_____" << '\n';

  std::cout << "     |     |     " << '\n';
  std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "   " << '\n';
  std::cout << "     |     |     " << '\n';

  std::cout << '\n';

}

//let the player make move.
void player_move(char *spaces, char player){

  int number;
  do {

    std::cout << "Enter a number to make a move(1-9): ";
    std::cin >> number;
    number--;

    if (spaces[number] == ' ') {
      spaces[number] = player;
      break;
    }

  } while(number >= 0 || number <= 8);

}

//let the ai make move. Randomised.
void computer_move(char *spaces, char computer){

  int number;
  //random number generation for the move.
  srand(time(NULL));

  while(true){
    number = rand() % 9;
    if (spaces[number] == ' ') {
      spaces[number] = computer;
      break;
    }
  }

}

//check winner after every move.
bool check_winner(char *spaces, char player, char computer){

  if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
    spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "You lose.\n";
  }
  else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
    spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "You lose.\n";
  }
  else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
    spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "You lose.\n";
  }
  else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
    spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "You lose.\n";
  }
  else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
    spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "You lose.\n";
  }
  else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
    spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "You lose.\n";
  }
  else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
    spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "You lose.\n";
  }
  else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
    spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "You lose.\n";
  }
  else{
    return false; //if none of the cases above are true.
  }

  return true; //if any of the cases above is true.
}

//check tie after every move.
bool check_tie(char *spaces){

  for(int i = 0; i < 9; i++){
    if (spaces[i] == ' ') {
      return false;
    } 
  }
  std::cout << "It's a tie...\n";
  return true;

}
