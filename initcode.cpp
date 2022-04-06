/**
 * @file   initcode.cpp
 * @author Carson Brandt
 * @brief  Initializes the Board and Displays it
 * @date   03-21-2022
 * 
 */

#include "battleship.h"


/**
 * @brief Builds the blank board
 *
 * @param Board		  which board to build
 **/
void buildboard(char board[][NUM_COLS]){
	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int col = 0; col < NUM_COLS; col++)
		{
			board[row][col] = '-';
		}
		
	}
	
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
/**
 * @brief Enters the Manual Placement sequence for ships
 *
 * @param Board which board to place ships on
 **/
void manualplace(char board[][NUM_COLS]){
	int placeX = 0, placeY = 0, placeR = 0;
    bool valid;
	for (int shipnum = 0; shipnum < NUM_SHIPS; shipnum++)
	{

		do {
            valid = true;
            displayboard(board);
	    	//Asks user for coordinates for ship
            do {
	        	cout << "Input Coordinates to begin placing "<<SHIP_NAMES[shipnum]<<" with length of "<<SHIP_SIZES[shipnum]<<", seperated by a space: [COLUMN, ROW]\n";
	        	cin >> placeY; //gets X coord (rows)
				placeY = placeY - 1;
	        	cin >> placeX; //gets Y coord (col)
				placeX = placeX - 1;
            } while ((placeX < 0 || placeX > NUM_ROWS) || (placeY < 0 || placeY > NUM_ROWS));

			do {
	        	cout << "Input direction of rotation [0] for vertical (in Up direction), [1] for horizontal (in left direction)\n";
	        	cin.ignore();
                cin >> placeR;
	        	if (placeR != 0 && placeR != 1) {
	    		    cout << "Invalid Input, Not from above list\n";
		        }
		    } while (placeR != 0 && placeR != 1);
            //INPUT VALIDATION

            //Check if too close to walls
		    if (placeR == 0 && placeX - SHIP_SIZES[shipnum] < -1){
                cout << "To close to top, rotate or change position.\n";
                valid = false;
            }
            if (placeR == 1 && placeY + SHIP_SIZES[shipnum] > 9){
                cout << "To close to side, rotate or change position.\n";
                valid = false;
            }
            //check if overlapping other ship
            if (placeR == 1){
                for (int i = 0; i < SHIP_SIZES[shipnum]; i++){
                    if (board[placeX][placeY + i] != '-'){
                        valid = false;
                        cout << "Invalid, overlaps other ship.\n";
                        break;
                    }
                }
            }
            if (placeR == 0){
                for (int i = 0; i < SHIP_SIZES[shipnum]; i++)
                {
                    if(board[placeX - i][placeY] != '-'){
                        valid = false;
                        cout << "Invalid, overlaps other ship.\n";
                        break;
                    }
                }
                
            }
		} while (valid == false);
		//draw the ships
		if(placeR == 0){
			for (int rows = 0; rows < SHIP_SIZES[shipnum]; rows++)
			{
				board[(placeX - rows)][placeY] = SHIP_SYMBOLS[shipnum];
			}
		}else if (placeR == 1) {
			for (int col = 0; col < SHIP_SIZES[shipnum]; col++)
			{
				board[placeX][(placeY + col)] = SHIP_SYMBOLS[shipnum];
			}
			
		}
		
	}
	cout << "Initialization Complete.\n";
	cout << "This is the Board:\n";
	displayboard(board);

}