/**
 * @file   computer.cpp
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
void computerMove(char board[][NUM_COLS], int thisMove[],char hitMap[][NUM_COLS]){
	srand(time(NULL));
	do {
		thisMove[0] = rand() % NUM_ROWS; // Random row
		thisMove[1] = rand() % NUM_COLS; // Random column
	} while (!validShot(thisMove[0],thisMove[1],hitMap)); // The validshot function only looks - meaning that ships
	// dont register as valid hits, so I am using hitmap which tracks succusful shots;
	
	cout << thisMove[0] << endl;  
	cout << thisMove[1] << endl;
		
	if(hitDetect(thisMove[0],thisMove[1],board)){
		cout<<"The computer hit\n";
		update(thisMove[0],thisMove[1],board,hitMap);
	} else {
		cout<<"The computer missed\n";
	}
}

