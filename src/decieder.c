#include<stdio.h>
#include<chess_piece.h>
#include<rand_macros.h>
#include"decieder.h"
char name_decieder(char type,char color){
    char b_name[6]={'p','b','n','r','k','q'};//name designated for black pieces
    char w_name[6]={'P','B','N','R','K','Q'};//name designated for white pieces
    char types[6]={PAWN,BISHOP,KNIGHT,ROOK,KING,QUEEN};//it stores the all the macros for the pieces in one array 
    char return_value;
    int size=6;
    for(int i=0;i<size;i++){
        if(type==types[i]){
            if(color==BLACK){
                return_value=b_name[i];
                break;
                
            }
            return_value=type;
            break;
        }
    }
    return return_value;
}
int position_decieder(char type,char color){//its a function to deciede which piece gets which position it is right now being only worked at the initializeer
    int position;
    char Color;
    if(type==PAWN){
        if(color==BLACK){
            position=1;
        }
        else{
            position=6;
        }
    }else{
        if(color==BLACK){
            position=0;
        }
        else{
            position=7;
        }
        
    }
    return position;
}