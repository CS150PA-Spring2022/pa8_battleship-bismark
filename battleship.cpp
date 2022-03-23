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
void computerMove(int thisMove[], int lastMove[], char history[][NUM_COLS], bool liveShips[]){ // NOTE: THIS FUNCTION IS IN ROUGH STAGES. PARAMETERS ARE NOT FIXED!
	bool firstMove = true;
	for (int i = 0; i < NUM_COLS; i++){
		for (int j = 0; j < NUM_ROWS; j++){
			if (history[i][j] != '-') firstMove = false;
		}
	}
	do {
		if (firstMove){
			srand(time(NULL));
			// Random move
			thisMove[0] = rand() % NUM_ROWS; // Random row
			thisMove[1] = rand() % NUM_COLS; // Random column
		} else {
			// Begin smart search
			if (history[lastMove[0]][lastMove[1]] != 'm'){ // Check that last move is a hit.
				char lastResult = history[lastMove[0]][lastMove[1]];
				if (lastResult == 'C'){
					if (liveShips[0]){ // Check if it is still up.
						if (history[lastMove[0] - 1][lastMove[1]] == 'C'){ // Check if it is in previous row.
							for (int i = 2; i < SHIP_SIZES[0]; i++){
								if (history[lastMove[0] - i][lastMove[1]] == '-'){
									thisMove[0] = lastMove[0] - i;
									thisMove[1] = lastMove[1];
								}
							}
						} else if (history[lastMove[0] + 1][lastMove[1]] == 'C'){ // Check if it is in the next row.
							for (int i = 2; i < SHIP_SIZES[0]; i++){
								if (history[lastMove[0] + i][lastMove[1]] == '-'){
									thisMove[0] = lastMove[0] + i;
									thisMove[1] = lastMove[1];
								}
							}
						}
					}
				} else if (lastResult == 'B'){
					if (liveShips[1]){
					
					}
				} else if (lastResult == 'R'){
					if (liveShips[2]){
					
					}
				} else if (lastResult == 'S'){
					if (liveShips[3]){
					
					}
				} else if (lastResult == 'D'){
					if (liveShips[4]){
					
					}
				}
			}
			// If no hits on unsunk ships, then pick another random.
			// If not hit, but not sunk, try other direction.
		}
	} while (/* Check if valid move*/ 1);
	// Output move
}
