#include<stdio.h>
#include<stdlib.h>
#include"chess_board.h"
#include"chess_piece.h"
#include"stack_For_chess.h"
#include"stack_initialiezer.h"
#include"input_function.h"
#include"node_declaration.h"
#define X 0//To better understand when i am assigning in X position of the array 
#define Y 1// .......................................... Y postion of the array 

#define STOP 0
#define RUN 1

// Its all the macro needed for X positioning 
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
//misclenious macro s like color,movement etc...

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define ALL 'A'
#define WIDTH 8
#define LENGTH 8
// chess_board=((*chess_board)[8])malloc(8*sizeof(char));
char (*chess_board)[8]=NULL;
piece** chess_piece_arr=NULL;//array that is being taken from input_function.h 

stack* new_stack=NULL;//stack to use 




// struct chess_game{
//     piece* b_pawn1;
//     piece* b_pawn2;
//     piece* b_pawn3;
//     piece* b_pawn4;
//     piece* b_pawn5;
//     piece* b_pawn6;
//     piece* b_pawn7;
//     piece* b_pawn8;
//     piece* b_knight_L;
//     piece* b_kngiht_R;
//     piece* b_bishop_L;
//     piece* b_bishop_R;
//     piece* b_rook_R;
//     piece* b_rook_L;
//     piece* b_king;
//     piece* b_queen;


//     piece* w_pawn1;
//     piece* w_pawn2;
//     piece* w_pawn3;
//     piece* w_pawn4;
//     piece* w_pawn5;
//     piece* w_pawn6;
//     piece* w_pawn7;
//     piece* w_pawn8;
//     piece* w_knight_L;
//     piece* w_kngiht_R;
//     piece* w_bishop_L;
//     piece* w_bishop_R;
//     piece* w_rook_R;
//     piece* w_rook_L;
//     piece* w_king;
//     piece* w_queen;


    

      

//     int turn_tracker;
//     int run_state;
//     // char (*board_state)[8];

// };
//  pawn* pawn_init(char color,int x_position){
//     if(color!='b' && color!='w'){
//         printf("You can not define that as color");
//         return NULL;
//     }
//     pawn* new=(pawn*)malloc(sizeof(pawn));
//     if(new==NULL){
//         printf("Memory allocation failed !!");
//         return NULL;
//     }
//     new->color=color;
//     if(color=='w'){
//         new->current_position[1]=7;
//     }
//     if(color=='b'){
//         new->current_position[1]=2;
//     }
//     new->current_position[0]=x_position;
//     new->moving_direction=FORWARD;
//     new->moving_distance=1;
//     new->piece_name='P';
//     return new;
    

    
// }
void remove_piece(piece* given_piece);
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

// king* king_init(char color){
//     if(color!='b' && color!='w'){
//         return NULL;
//     }
//     king* new_king=(king*)malloc(sizeof(king));
//     new_king->color=color;
//     new_king->current_position[0]=5;
//     new_king->moving_direction=ALL;
//     if(color==BLACK){
//     new_king->current_position[1]=0;
//     }else{
//         new_king->current_position[0]=7;
//     }
//     return new_king;
// }
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
piece* select_piece(struct chess_game* game){
    piece* selectedPiece=chess_piece_arr[(game->move_position_y*MAX_POSITIONS)+game->move_position_x];
    chess_board[game->move_position_y][game->move_position_x]='*';
    return selectedPiece;

    

}
void piece_move(piece* given_piece,struct chess_game* game){
    piece* given=given_piece;//idk why i did taht its just part of debugging you can say 
    char temp_c=chess_board[game->next_move_y][game->next_move_x];
    piece* temp=chess_piece_arr[(game->next_move_y*MAX_POSITIONS)+game->next_move_x];
    
    if((temp!=NULL && temp->color!=given_piece->color) || temp==NULL){
    chess_board[game->next_move_y][game->next_move_x]=given_piece->piece_name;
    }else{
        printf("Wrong move\n");
        chess_board[game->move_position_y][game->move_position_x]=given_piece->piece_name;
        return;
    }//game's breaking herer fix it asap!!!

    
    // chess_board[game->move_position_y][game->move_position_x]=temp_c;
    
    chess_piece_arr[(game->next_move_y*MAX_POSITIONS)+game->next_move_x]=given_piece;
    chess_piece_arr[(game->move_position_y*MAX_POSITIONS)+game->move_position_x]=NULL;
    // printf("%p\n",given);
    // printf("%p\n",given->own);
    if(temp!=NULL){
        printf("%c",temp->piece_name);
    remove_piece(temp); //This line does causes seg fault fix it asap remve piece function is broken ... its now fixed 
    }
   
    // chess_piece_arr[(game->move_position_y*MAX_POSITIONS)+game->move_position_x]=temp;
    change_turn(game);

    

}
void game_board(struct chess_game* game){
    
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||1\n",A8,B8,C8,D8,E8,F8,G8,H8);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||2\n",A7,B7,C7,D7,E7,F7,G7,H7);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||3\n",A6,B6,C6,D6,E6,F6,G6,H6);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||4\n",A5,B5,C5,D5,E5,F5,G5,H5);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||5\n",A4,B4,C4,D4,E4,F4,G4,H4);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||6\n",A3,B3,C3,D3,E3,F3,G3,H3);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||7\n",A2,B2,C2,D2,E2,F2,G2,H2);
    printf("=========================================\n");
    printf("|| %c || %c || %c || %c || %c || %c || %c || %c ||8\n",A1,B1,C1,D1,E1,F1,G1,H1);
    printf("=========================================\n");
    printf("   A    B    C    D    E    F    G    H\n");
}
void game_state_control(struct chess_game* game){
            while(1){
            if(scanf(" %d",&game->choice)==1){
                if(game->choice==0 || game->choice==1){
                break;
                }

        }
            while(1){

                if(getchar()=='\n'){
                    break;
                }

    }

        }

}
void gameLoop(struct chess_game* game){
    piece* selected_piece;
    // int choice;
    while(game->run_state){
        printf("0.For EXIT\n");
        printf("1.For Continue\n");
        game_state_control(game);

        if(game->choice==0){
            game->run_state=STOP;
            break;
        }

        do{
        parser_for_chess(game);
         selected_piece=select_piece(game);
        }while(!move_checker(selected_piece,game));

        while(!move_input(game));
        piece_move(selected_piece,game);


        game_board(game);
        
        
        
        
    }

}
void remove_piece(piece* given_piece){
    printf("1\n");
    piece* temp=given_piece;
    printf("%p",temp);
    struct node* ptr=temp->own;
    printf("%p",ptr->data);
    if(ptr->prev==NULL){
        ptr->next->prev=NULL;
        
        free(ptr);
        free(temp);
        // given_piece=NULL;
        return;
    }
    if(ptr->next==NULL){
        ptr->prev->next=NULL;
        free(ptr);
        free(temp);
        // given_piece=NULL;
        return;
    }
    struct node* previous_node=ptr->prev;
    previous_node->next=ptr->next;
    ptr->next->prev=previous_node;
    free(ptr);
    free(temp);
    // given_piece=NULL;
    
}
int main(){
    new_stack=stack_init(32);
    chess_piece_arr=piece_arr_setter();
    struct chess_game* game=game_init();
    game_board(game);
    gameLoop(game);
    game_destroy(game);
    free(chess_piece_arr);
    stack_destroy(new_stack);

    return 0;
}
