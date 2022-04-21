/**
 * @file   hit.cpp
 * @author Zach DeLuca
 * @brief  
 * @date   04-07-2022
 * 
 */

#include "battleship.h"

/**
 * @brief Checks if a shot is valid
 *
 * @param row
 * @param col
 * @param board
 */
bool validShot(int row,int col,char board[][NUM_COLS]){
	if (board[row][col]=='-'){
		return 1; // Suggest changing to explicit bools?
	} else {
	return 0;
	}
}

/**
 * @brief Checks if a shot hit
 *
 * @param row
 * @param col
 * @param board
 */
bool hitDetect(int row,int col,char board[][NUM_COLS]){ // Possibly change to array method?
	if (board[row][col] == 'd' || board[row][col] == 'c' || board[row][col] == 'r'
       || board[row][col] == 'b' || board[row][col] == 's'){
		return 1;
	} else {
		return 0;
	}
}

/**
 * @brief Updates the board
 *
 * @param row
 * @param col
 * @param board
 * @param hitMap
 */
void update(int row, int col, char board[][NUM_COLS],char hitMap[][NUM_COLS]){
	if (board[row][col] != '-'){
		hitMap[row][col] = 'X';
	} else {
		
		hitMap[row][col] = board[row][col];
	}
}
