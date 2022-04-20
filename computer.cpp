/**
 * @file   battleship.cpp
 * @author Kellen West
 * @brief  
 * @date   04-07-2022
 * 
 */

#include "battleship.h"

/**
 * @brief Handles computer player moves
 *
 * @param thisMove		  Holds the current move by the computer
 * @param lastMove		  Stores the last move to allow for smarter play
 * @param history		  Stores the move statistics of the computer for smarter play
 */
 
// NOTE: THIS CODE IS NOT FINAL. IT IS A PLACEHOLDER THAT MAKES RANDOM MOVES.
void computerMove(char board[][NUM_COLS],char hitMap2[][NUM_COLS]){
		srand(time(NULL));
		int row = rand() % NUM_ROWS; // Random row
		int col = rand() % NUM_COLS;

   if (validShot(row,col,hitMap2))
   {
     if(hitDetect(row,col,board)==1)
     {
         cout<<"Take that ye scallywag";
         update(row,col,board,hitMap2);

     }
     else
     {
		 cout<<"The scurvy dog missed";
     }
   }
		 // Random column
	} 

    