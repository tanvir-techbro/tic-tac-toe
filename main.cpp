#include <iostream>
#include <ctime>
#include "logic.h"

int main (int argc, char *argv[]) {

  char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char character;
  char player;
  char computer;
  bool charValid = false;
  bool running = true;

  //player character selection.
  while(charValid == false){

    std::cout << "Pick a character (X or O): ";
    std::cin >> character;

    if (character == 'X' || character == 'O') {
      charValid = true;
    }else {
      charValid = false;
      std::cout << "Invalid character, try again." << '\n';
    }

  }

  if (character == 'X'){
    player = 'X';
    computer = 'O';
  }else {
    player = 'O';
    computer = 'X';
  }

  std::cout << '\n';

  //GAME
  draw_board(spaces);

  while(running){
    player_move(spaces, player);
    draw_board(spaces);
    if (check_winner(spaces, player, computer)) {
      running = false;
      break;
    }else if (check_tie(spaces)) {
      running = false;
      break;
    }

    computer_move(spaces, computer);
    draw_board(spaces);
    if (check_winner(spaces, player, computer)) {
      running = false;
      break;
    }else if (check_tie(spaces)) {
      running = false;
      break;
    }
  }

  std::cout << "GAME END." << std::endl;

  return 0;
}
