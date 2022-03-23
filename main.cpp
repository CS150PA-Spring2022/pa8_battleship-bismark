/**
 * @file   battleship.cpp
 * @author Kellen West
 * @brief  
 * @date   03-21-2022
 * 
 */

#include "battleship.h"

int main(){
	welcomeScreen();
    // Initialize boards
    	// Extra board for computer to keep track of shots? Will update as needed... 
    	// Most likely needed. Not necessary segment, will call if needed.
    // Place ships
    // Begin game
    // Game loop
    for (int i = 0; i < NUM_ROWS; i++){
    	for (int j = 0; j < NUM_COLS; j++){
    		cout << p1board[i][j];
    	}
    	cout << endl;
    }
    return 0;
}
