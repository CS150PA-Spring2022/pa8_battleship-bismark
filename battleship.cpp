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
 * @brief Checks if ships are sunk
 *
 * @param board		 	  Holds board for checking
 * @param ship		  	  Defines ship to check for
 */
bool isSunk(char board[][NUM_COLS], char ship){
	int index = 0;
	for (index = 0; index < NUM_SHIPS; index++){
		if (ship == SHIP_SYMBOLS[index]) break;
		else index++;
	}
	int numHits = 0;
	for (int i = 0; i < NUM_COLS; i++){
		for (int j = 0; j < NUM_ROWS; j++){
			if (ship == board[i][j]) numHits++;
		}
	}
	if (numHits == SHIP_SIZES[index]) return true;
	else return false;
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
	do {
		if (firstMove){
			srand(time(NULL));
			// Random move
			thisMove[0] = rand() % NUM_ROWS; // Random row
			thisMove[1] = rand() % NUM_COLS; // Random column
		} else {
			// Begin smart search
			// Check what hits there are on the board, if any.
			if (history[lastMove[0]][lastMove[1]] != 'm'){
				// Check that last move is a hit.
				switch (history[lastMove[0]][lastMove[1]]) {
					case 'C' :     //'C' represents a carrier 5 spaces 
					
					case 'B' :   // B represents a battleship  4 spaces 
					
					case 'R' : //R represents a recon boat 3 space
					
					case 'S' :    // S  represnts a submarine 3 spaces 
					
					case 'D' :    // D represnts a destroyer 2 spaces 
						if (history[lastMove[0] + 1][lastMove[1] + 1] == '-'){
							thisMove[0] = lastMove[0] + 1;
							thisMove[1] = lastMove[1] + 1;
						} else if (1){
						
						}
					default : break;
				}
			}
			// If no hits on unsunk ships, then pick another random.
			// If hit, check type of ship and try one of the spots next to it.
			// If not hit, but not sunk, try other direction.
		}
	} while (/* Check if valid move*/ 1);
	// Output move
}

/**
 * @brief Displays a board to the terminal
 *
 * @param Board which board to display
 **/
void displayboard(char board[][NUM_COLS]){
	cout <<"   ";
	for (int head = 0; head < NUM_COLS; head++)
	{
		cout << head + 1 << " ";
	}
	cout << endl;
	for (int row = 0; row < NUM_ROWS; row++)
	{
		if (row < 9){
		cout <<' '<<row + 1<<" ";
		} else {
			cout <<row + 1<<" ";
		}
		for (int col = 0; col < NUM_COLS; col++)
		{
			cout << board[row][col] << ' ';
		}
	cout << endl;
	}	
}

bool checkYN(char input){
	if (input == 'Y' || input == 'y'){
		return true;
	} else {
		return false;
	}
}
