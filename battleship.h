/**
 * @file   battleship.h
 * @author Kellen West
 * @brief  
 * @date   03-21-2022
 * 
 */
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "logger.h"

// Declare functions
void welcomeScreen();
void buildboard(char board[][NUM_COLS]);
void displayboard(char board[][NUM_COLS]);
void manualplace(char board[][NUM_COLS]);
bool checkYN(char input);
void autoplace(char board[][NUM_COLS]);
bool isSunk(char board[][NUM_COLS], char ship);
bool validShot(int row,int col, char board[][NUM_COLS]);
bool hitDetect(int row,int col, char board[][NUM_COLS]);
void update(int row, int col, char board[][NUM_COLS], char hitMap[][NUM_COLS]);
void attack(char board[][NUM_COLS], char hitMap[][NUM_COLS], Logger &logFile);
bool isWin(char board[][NUM_COLS]);
void computerMove(char board[][NUM_COLS], int thisMove[],char hitMap[][NUM_COLS], Logger &logFile);
bool selectWhoStartsFirst();
bool isComputerWin(char board[][NUM_COLS]);
#endif
