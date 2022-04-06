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
    char p1board[NUM_ROWS][NUM_COLS];
    char p2board[NUM_ROWS][NUM_COLS];
    buildboard(p1board);
    buildboard(p2board);
    
    char randPlace = 'y';
    
    // Ask if want random or manual placement.
    if (checkYN(randPlace)){
    	// Random placement
    } else {
    	manualplace(p1board);
    }
    for (int i = 0; i < NUM_ROWS; i++){
    	for (int j = 0; j < NUM_COLS; j++){
    		cout << p1board[i][j];
    	}
    	cout << endl;
    }

    char yesno =' ';


     do {
        cout<<"Would you like to play a game of Battleship?";
        cout<<"type 'y' if yes, 'n' if no ";
        cin>>yesno;
        
        if(yesno=='y')
        {
            cout<<"Game in progress";
        }

    }while(yesno =='y');

     cout<<"goodbye";




    return 0;
}
