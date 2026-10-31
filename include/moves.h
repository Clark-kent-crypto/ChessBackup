#ifndef MOVES_H
#define MOVES_H
#include<stdbool.h>
#include<chess_piece.h>
#include<chess_board.h>
bool pawn_move_check(piece* selected_piece,struct chess_game* game);//should be checking if the pawn move is valid or not 
bool pawn_move_first(piece* selected_piece,struct chess_game* game);//checks if the pawn movement is first
bool bishop_move_check(piece* selected_piece,int inpt_arr[2]);//should be checking if te bishop move is valid or not
bool bishop_move_restriction_check(piece* selected_piece,int x_diff,int y_diff);//checks whether move is restricted by other piece
bool pawn_movement_check(piece* selected_piece,struct chess_game* game,int arr[2]);

#endif