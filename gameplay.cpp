
#include "battleship.h"




bool selectWhoStartsFirst(){
	string FirstPlayer="\0";
	cout << "Would you like to go first? [Y/N] ";
	cin >> FirstPlayer;
	if (checkYN(FirstPlayer)) return true;
	else return false;
}


// Lance
/**
 * @brief Uses functions from hit.cpp to allow attacking ships
 *
 * @param board		 	  holds the board being attacked by player
 * @param hitMap		   Board that is displayed to player to be attacked
 */

void attack(char board[][NUM_COLS], char hitMap[][NUM_COLS], Logger &logFile){
	inv:
	char rowChar = '\0';
	int col = 0;
	cout << "Enter the coordinates of the space you would like to attack: ";
	cin >> rowChar;
	cin >> col;

	int row = toupper(rowChar) - 64;
    

	if (validShot(row-1,col-1,hitMap)){
		if (hitDetect(row-1,col-1,board) == 1){
			cout << "Yarr you hit me ship\n";
			update(row-1,col-1,board,hitMap);

			//logs hit - ESJ
			logFile.addMove(row,col,true,board[row][col]);
		} else {
			cout << "Haha you missed me boat\n";
			//logs miss - ESJ
			update(row-1,col-1,board,hitMap);
			logFile.addMove(row,col,false,'-');
		}
	} else {
		cout << "Invalid shot\n";
		goto inv;
	}
}

// Lance
/**
 * @brief              Checks to see if a player has won
 *
 * @param board		 	  the board this function is checking for a winner
 */

bool isWin(char board[][NUM_COLS]){
	int score = 0;
	for (int i = 0; i<NUM_ROWS; i++){
		for (int j = 0; j<NUM_COLS; j++){
			if (board[i][j] == 'X'){
				score++;
			}
		}
	}
	if (score == 16){
		cout << "You win!";
		return true;
	} else return false;
}


bool isComputerWin(char board[][NUM_COLS]){
	int score = 0;
	for (int i = 0; i<NUM_ROWS; i++){
		for (int j = 0; j<NUM_COLS; j++){
			if (board[i][j] == 'X'){
				score++;
			}
		}
	}
	if (score == 16){
		cout << "The Computer Wins!";
		return true;
	} else return false;
}

