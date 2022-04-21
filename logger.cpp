/**
 * @file   logger.cpp
 * @author Edward S-J
 * @brief  
 * @date   04-20-2022
 * 
 */

#include "battleship.h"

/**
 * @brief A class-based logging system
 */

void Logger::shipsPlaced(bool autoplace){
	logFile << "Player's ships placed ";
	if (autoplace){
		logFile << "automatically.";
	} else {
		logFile << "manually.";
	}
	logFile << endl;
	return;
};

void Logger::addMove(int row, int col, bool hit, char mark){
	char rowRef;
	rowRef = 'A' + row;
	if (playerTurn){
		logFile << "Player shoots: " + rowRef + col << ", ";
	} else {
		logFile << "Computer shot: " + rowRef + col << ", ";
	}
	if (hit){
		logFile << "Hit! " << mark;
	} else {
		logFile << "Miss.";
	}
	logFile << endl;
	playerTurn = !playerTurn;
	return;
};

void Logger::finish(){
	logFile.close();
	return;
};