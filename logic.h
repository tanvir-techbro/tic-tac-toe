#ifndef LOGIC_H
#define LOGIC_H

#include <ctime>
#include <cmath>

void draw_board(char *spaces);
void player_move(char *spaces, char player);
void computer_move(char *spaces, char computer);
//result checking.
bool check_winner(char *spaces, char player, char computer);
bool check_tie(char *spaces);

#endif // !LOGIC_H
