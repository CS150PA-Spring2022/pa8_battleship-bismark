#include "battleship.h"
bool validShot(int row,int col,char board[][NUM_COLS]){
    if (board[row][col]=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
bool hitDetect(int row,int col,char board[][NUM_COLS]){
     if (board[row][col]=='d'||board[row][col]=='c'||board[row][col]=='r'
       ||board[row][col]=='b'||board[row][col]=='s'){
           return 1;
     }
     else{
         return 0;
     }
}

void update(int row, int col, char board[][NUM_COLS],char hitMap[][NUM_COLS]){
    if (board[row][col]!='-'){
        hitMap[row][col] = 'X';
    }
    else{
        hitMap[row][col]=board[row][col];
    }
}