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
	cin.get();
    // Initialize boards
    	// Extra board for computer to keep track of shots? Will update as needed... 
    	// Most likely needed. Not necessary segment, will call if needed.
    // Place ships
    // Begin game
    // Game loop
    char p1board[NUM_ROWS][NUM_COLS];
    char p2board[NUM_ROWS][NUM_COLS];
    buildboard(p1board);
    buildboard(p2board);
    
    char randPlace = '\0';
    cout << "Would you like to have your ships placed randomly? ";
    cin >> randPlace;
    // Ask if want random or manual placement.
    if (checkYN(randPlace)){
    	autoplace(p1board);
    	displayboard(p1board);
    } else {
    	manualplace(p1board);
    }
    sleep(1);
    autoplace(p2board);
    // Unnecessary code?
    /*for (int i = 0; i < NUM_ROWS; i++){
    	for (int j = 0; j < NUM_COLS; j++){
    		cout << p1board[i][j];
    	}
    	cout << endl;
    }*/
    return 0;
}
