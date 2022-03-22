/**
 * @file   battleship.cpp
 * @author Kellen West
 * @brief  
 * @date   03-21-2022
 * 
 */

#include "battleship.h"

/**
 * @brief Displays welcome
 */
void welcomeScreen(){
	cout << "***** Welcome to Battleship! *****\n\n";
	cout << "Rules of the Game:\n";
	cout << "1. This is a two player game.\n";
	cout << "2. You are Player 1 and the computer is Player 2.\n";
	cout << "3. RULES\n"; // Needs completion
	
	cout << "Hit enter to start the game!\n";
}


/**
 * @brief Handles computer player moves
 *
 * @param thisMove		  Holds the current move by the computer
 * @param lastMove		  Stores the last move to allow for smarter play
 * @param history		  Stores the move statistics of the computer for smarter play
 */
void computerMove(int thisMove[], int lastMove[], char history[][NUM_COLS]){ // NOTE: THIS FUNCTION IS IN ROUGH STAGES. PARAMETERS ARE NOT FIXED!
	bool firstMove = true;
	for (int i = 0; i < NUM_COLS; i++){
		for (int j = 0; j < NUM_ROWS; j++){
			if (history[i][j] != '-') firstMove = false;
		}
	}
	do{
		if (firstMove){
			srand(time(NULL));
			// Random move
			thisMove[0] = rand() % NUM_ROWS; // Random row
			thisMove[1] = rand() % NUM_COLS; // Random column
		} else {
			// Begin smart search
			// Check what hits there are on the board, if any.
			// If no hits on unsunk ships, then pick another random.
			// If hit, check type of ship and try one of the spots next to it.
			// If not hit, but not sunk, try other direction.
		}
	} while (/* Check if valid move*/);
	// Output move
}
