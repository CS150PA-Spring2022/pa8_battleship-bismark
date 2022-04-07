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

// Kellen
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

// Carson?
/**
 * @brief Displays a board to the terminal
 *
 * @param board 		  which board to display
 **/
void displayboard(char board[][NUM_COLS]){
	cout << "   ";
	for (int head = 0; head < NUM_COLS; head++){
		cout << head + 1 << " ";
	}
	cout << endl;
	for (int row = 0; row < NUM_ROWS; row++){
		if (row < 9){
		cout << " " << row + 1 << " ";
		} else {
			cout << row + 1 << " ";
		}
		for (int col = 0; col < NUM_COLS; col++){
			cout << board[row][col] << ' ';
		}
	cout << endl;
	}	
}

// Kellen
/**
 * @brief Converts yes and no to bool
 *
 * @param 				  input which board to display
 **/
bool checkYN(char input){
	if (input == 'Y' || input == 'y'){
		return true;
	} else {
		return false;
	}
}
