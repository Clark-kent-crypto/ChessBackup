#ifndef INIT_FUNCTIONS
#define INIT_FUNCTIONS
#include<chess_piece.h>
#include<rand_macros.h>
piece* piece_init(char color,int x_position,char type);//used to initialize a piece object
struct chess_game* game_init();// used to initialize chess_game object
void board_setter(struct chess_game* game);//initializes and sets up the board 
void game_destroy(struct chess_game* game);//destroys the game object



#endif