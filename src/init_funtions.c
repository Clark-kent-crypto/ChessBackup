#include<stdio.h>
#include<stdlib.h>
#include<chess_piece.h>
#include<rand_macros.h>
#include<stack_For_chess.h>
#include<decieder.h>
#include<stack_initialiezer.h>
#include<init_functions.h>
#include<chess_board.h>
piece* piece_init(char color,int x_position,char type){//it initianlizes each and every pieces 
    if(color!=WHITE && color!=BLACK){
        printf("Invalid Color Choice !!");
        return NULL;
    }
    piece* new_piece=(piece*)malloc(sizeof(piece));
    if(new_piece==NULL){
        printf("Memory Allocation failed!!");
        return NULL;
    }
    push(new_stack,new_piece);
    new_piece->moving_direction=FORWARD;
    
    new_piece->color=color;
    new_piece->current_position[Y]=position_decieder(type,color);
    new_piece->current_position[X]=x_position;
    new_piece->piece_type=type;
    new_piece->piece_name=name_decieder(type,color);
    // i had new_piece->own=NULL after allocating them with different memory so it was fucking up 
    return new_piece;
    

}
void board_setter(struct chess_game* game){// its supposed to set up the board 
    for(int i=0;i<LENGTH;i++){
        for(int j=0;j<WIDTH;j++){
            chess_board[i][j]='*';
        }
    }
    struct node* temp=new_stack->top;
    while(temp!=NULL){
        piece* temp_piece=temp->data;
        chess_piece_arr[(temp_piece->current_position[Y]*MAX_POSITIONS)+temp_piece->current_position[X]]=temp_piece;

        chess_board[temp_piece->current_position[Y]][temp_piece->current_position[X]]=temp_piece->piece_name;
        temp=temp->next;
    }


}
struct chess_game* game_init(){
    struct chess_game* newGame=(struct chess_game*)malloc(sizeof(struct chess_game));
    newGame->b_pawn1=piece_init(BLACK,A,PAWN);
    newGame->b_pawn2=piece_init(BLACK,B,PAWN);
    newGame->b_pawn3=piece_init(BLACK,C,PAWN);
    newGame->b_pawn4=piece_init(BLACK,D,PAWN);
    newGame->b_pawn5=piece_init(BLACK,E,PAWN);
    newGame->b_pawn6=piece_init(BLACK,F,PAWN);
    newGame->b_pawn7=piece_init(BLACK,G,PAWN);
    newGame->b_pawn8=piece_init(BLACK,H,PAWN);

    newGame->b_rook_L=piece_init(BLACK,A,ROOK);
    newGame->b_rook_R=piece_init(BLACK,H,ROOK);
    newGame->b_bishop_L=piece_init(BLACK,C,BISHOP);
    newGame->b_bishop_R=piece_init(BLACK,F,BISHOP);
    newGame->b_knight_L=piece_init(BLACK,B,KNIGHT);
    newGame->b_kngiht_R=piece_init(BLACK,G,KNIGHT);
    newGame->b_king=piece_init(BLACK,E,KING);
    newGame->b_queen=piece_init(BLACK,D,QUEEN);

    newGame->w_pawn1=piece_init(WHITE,A,PAWN);
    newGame->w_pawn2=piece_init(WHITE,B,PAWN);
    newGame->w_pawn3=piece_init(WHITE,C,PAWN);
    newGame->w_pawn4=piece_init(WHITE,D,PAWN);
    newGame->w_pawn5=piece_init(WHITE,E,PAWN);
    newGame->w_pawn6=piece_init(WHITE,F,PAWN);
    newGame->w_pawn7=piece_init(WHITE,G,PAWN);
    newGame->w_pawn8=piece_init(WHITE,H,PAWN);

    newGame->w_rook_L=piece_init(WHITE,A,ROOK);
    newGame->w_rook_R=piece_init(WHITE,H,ROOK);
    newGame->w_bishop_L=piece_init(WHITE,C,BISHOP);
    newGame->w_bishop_R=piece_init(WHITE,F,BISHOP);
    newGame->w_knight_L=piece_init(WHITE,B,KNIGHT);
    newGame->w_kngiht_R=piece_init(WHITE,G,KNIGHT);
    newGame->w_king=piece_init(WHITE,E,KING);
    newGame->w_queen=piece_init(WHITE,D,QUEEN);

   

    // newGame->board_state=(char(*)[8])malloc(8*sizeof(char));
    chess_board=malloc(8*sizeof(char[8]));
    newGame->run_state=RUN;
    board_setter(newGame);
    newGame->choice=0;
    newGame->turn_tracker=white;
   return newGame;
     

}
void game_destroy(struct chess_game* game){
    stack* new=new_stack;
    struct node* ptr=new->top;
    while(ptr!=NULL){
        piece* temp_piece=ptr->data;
        ptr=ptr->next;
        free(temp_piece);
    }
    free(game);
}