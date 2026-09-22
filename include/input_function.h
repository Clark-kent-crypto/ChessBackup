#ifndef INPUT_H
#define INPUT_H
#include"chess_piece.h"
#include<stdbool.h>
#define INPUT_SIZE 3
#define MAX_POSITIONS 8
#define X 0
#define Y 1
#define BLACK 'b'
#define WHITE 'w'
piece** piece_arr_setter();//piece array  initialiezer
void parser_for_chess(struct chess_game* game);//parses the user input
void translate_position(char arr[2],int *pReturnArr);//translates the user given input
extern piece** chess_piece_arr;//array containing piece* as a data
bool move_input(struct chess_game* game);//takes the user input that is responsible for moving the selceted piece
bool move_checker(piece* selected_piece,struct chess_game* game);//it should be ckecking if current move is possible in terms of the player turn
void change_turn(struct chess_game* game);//responsible to change the turn for the game 
#endif