/**
 * @file   battleship.cpp
 * @author Kellen West
 * @brief  
 * @date   03-21-2022
 * 
 */

#include "battleship.h"
//#include "logger.cpp"

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
    char hitMap[NUM_ROWS][NUM_COLS];
    char hitMap2[NUM_ROWS][NUM_COLS];
    buildboard(p1board);
    buildboard(p2board);
    buildboard(hitMap);
    buildboard(hitMap2);

    //creates log after boards initialized - ESJ
    Logger gamelog;
    
    char randPlace = '\0';
    cout << "Would you like to have your ships placed randomly? ";
    cin >> randPlace;
    // Ask if want random or manual placement.
    
    // needed to reference result twice, made storage variable - ESJ
    bool autoChoice = checkYN(randPlace);

    if (autoChoice){
    	autoplace(p1board);
    	displayboard(p1board);
    } else {
    	manualplace(p1board);
    }

    //logs decision - ESJ
    gamelog.shipsPlaced(autoChoice);

    sleep(1);
    autoplace(p2board);

    do {
		cout << "Player 1 turn";
		attack(p2board,hitMap);
		displayboard(hitMap);
		computerMove(p1board,hitMap2);
		cout << "Player 2 turn";
		displayboard(hitMap2);
	} while(isWin(hitMap) == 0);
    
    // Unnecessary code?
    /*for (int i = 0; i < NUM_ROWS; i++){
    	for (int j = 0; j < NUM_COLS; j++){
    		cout << p1board[i][j];
    	}
    	cout << endl;
    }*/

    // closes the game log when the game is over
    gamelog.finish();

    return 0;
}
