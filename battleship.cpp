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

	cout << " Battleship is a game of naval warfare\n";
	cout << "1. Place your ships on the coordinate grid either horizontally or vertically and the AI player will do likewise";
	cout << endl;
	cout << "2. Each player will type in a capital letter and a number representing a space on the grid";
	cout << "3. If that space overlaps with a ship,you have hit that ship, when all spaces are hit that ship is sunk" << endl;
	cout << "4. When all ships have been sunk then either you or the opponent will win." << endl;
	
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

// Kellen
/**
 * @brief Converts yes and no to bool
 *
 * @param input				  Input to convert
 **/
/*bool checkYN(char input){
	if (input == 'Y' || input == 'y'){
		return true;
	} else {
		return false;
	}
}*/

bool checkYN(string input){
	if (!strcasecmp(input.c_str(),"yes") || !strcasecmp(input.c_str(),"Y")) return true;
	else return false;
}
