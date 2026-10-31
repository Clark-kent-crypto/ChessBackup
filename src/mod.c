#include<stdio.h>
#include<mod.h>
int mod(int inpt){
    if(inpt<0){
        return -(inpt);
    }
    else{
        return inpt;
    }
}
int direction(int inpt){
    if(inpt<0){
        return 1;
    }
    else{
        return -1;
    }
}