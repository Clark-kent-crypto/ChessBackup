#include<stdio.h>
#include<moves.h>
#include<stdlib.h>
#include<chess_board.h>
#include<rand_macros.h>
#include<mod.h>
bool pawn_move_check(piece* selected_piece,struct chess_game* game){
    piece* temp=selected_piece;
    if(temp->color==BLACK){
        if(chess_board[++(temp->current_position[Y])][temp->current_position[X]]!='*'){
             printf("PAWN MOVEMENT RESTRICTED!!\n");
        return false;

    }
    // if(pawn_move_first(selected_piece,game)){

    // }
    
    }
    if(temp->color==WHITE){
        if(chess_board[--(temp->current_position[Y])][temp->current_position[X]]!='*'){
            printf("PAWN MOVEMENT RESTRICTED!!\n");
        return false;

    }
    }
    
    return true;

}
bool pawn_move_first(piece* selected_piece,struct chess_game* game){
    if(game->turn_tracker<=2){
        return true;
    }
    return false;
    

}
bool bishop_move_check(piece* selected_piece,int inpt_arr[2]){
    piece* temp=selected_piece;
    int x_diff=temp->current_position[X]-inpt_arr[X];
    int y_diff=temp->current_position[Y]-inpt_arr[Y];
   if(x_diff*x_diff!=y_diff*y_diff){
       printf("BISHOP MOVEMENT ERROR !!\n");
    return false;
   }
   if(!bishop_move_restriction_check(selected_piece,x_diff,y_diff)){
    return false;
   }
   return true;

}
bool bishop_move_restriction_check(piece* selected_piece,int x_diff,int y_diff){
    piece* temp=selected_piece;
    int x_movement=mod(x_diff);
    int y_movement=mod(y_diff);
    int tracker=x_movement-1;
    int x_step=temp->current_position[X];
    int y_step=temp->current_position[Y];
    int i=direction(x_diff);
    int j=direction(y_diff);
    while(tracker!=0){
         x_step+=i;
         y_step+=j;
        //  printf("%d",x_step);
         if(chess_board[y_step][x_step]!='*'){
            printf("BISHOP IS UNABLE TO MOVE\n");
            return false;
         }
         tracker--;
        


    }
    return true;


}
bool pawn_movement_check(piece* selected_piece,struct chess_game* game,int arr[2]){
    int y_diff=arr[Y]- selected_piece->current_position[Y];
    int abs_yDiff=y_diff*y_diff;
    if(abs_yDiff>=1){
        if(pawn_move_first(selected_piece,game) && abs_yDiff==1){
            // printf("HEllo\n");//just to debug
            return true;
        }
        // printf("hello\n");
        printf("PAWN CAN NOT MOVE THIS MUCH !!\n");
        return false;
    }
    return true;
}
