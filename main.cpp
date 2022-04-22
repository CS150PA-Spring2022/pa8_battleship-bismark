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
    char hitMap[NUM_ROWS][NUM_COLS];
    char hitMap2[NUM_ROWS][NUM_COLS];
    int thisMove[2];
    buildboard(p1board);
    buildboard(p2board);
    buildboard(hitMap);
    buildboard(hitMap2);

    //creates log after boards initialized - ESJ
    Logger gamelog;
    
    string randPlace = "\0";
    cout << "Would you like to have your ships placed randomly? [Y/N] ";
    cin >> randPlace;
    // Ask if want random or manual placement.
    
    // needed to reference result twice, made storage variable - ESJ
    bool autoChoice = checkYN(randPlace);

    if (autoChoice){
    	autoplace(p1board);
    	cout << "This is the Board:\n";
    	displayboard(p1board);
    } else {
    	manualplace(p1board);
    }

    //logs decision - ESJ
    gamelog.shipsPlaced(autoChoice);

    sleep(1);
    autoplace(p2board);
    
	if(selectWhoStartsFirst()){
		do {
			cout << "Player 1 turn\n";
			attack(p2board,hitMap,gamelog);
            cout<<"Enemy board"<<endl;
			displayboard(hitMap);
			cout << "Player 2 turn\n";
			computerMove(p1board,thisMove,hitMap2,gamelog);
            cout<<"Your board:\n";
			//displayboard(hitMap2);
			displayboard(p1board);
		} while(!isWin(hitMap) && !isComputerWin(hitMap2));
	} else {
		do {
			cout << "Player 2 turn\n";
			computerMove(p1board,thisMove,hitMap2,gamelog);
            cout << "Your board";
			//displayboard(hitMap2);
			displayboard(p1board);
			cout << "Player 1 turn\n";
			attack(p2board,hitMap,gamelog);
            cout << "Enemy board:";
			displayboard(hitMap);
        } while(!isWin(hitMap2) && !isComputerWin(hitMap2));

        //computer moves first
	}
    // closes the game log when the game is over
	gamelog.finish();

	return 0;
}
