/**
 * @file   battleship.h
 * @author Kellen West
 * @brief  
 * @date   03-21-2022
 * 
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define TESTING

// Global variables and arrays useful in the program
const int NUM_ROWS = 10;  // number of rows of the battleship game board
const int NUM_COLS = 10;  // number of columns of the battleship game board
const int NUM_SHIPS = 5;  // number of ships in the battelship game

// Each of the ships information in 3 arrays (parallel arrays)
const string SHIP_NAMES[] = {"carrier", "battleship", "cruiser", "submarine", "destroyer"};
const char SHIP_SYMBOLS[] = {'c', 'b', 'r', 's', 'd'};
const int SHIP_SIZES[] = {5, 4, 3, 3, 2};

// Declare functions
void welcomeScreen();
void computerMove(int thisMove[], int lastMove[], char history[][NUM_COLS], bool liveShips[], int lastHit[]);
void checkSurrounding(int thisMove[], int lastMove[], char history[][NUM_COLS], int lastHit[], char target);
void buildboard(char board[][NUM_COLS]);
void displayboard(char board[][NUM_COLS]);
void manualplace(char board[][NUM_COLS]);

#ifdef TESTING
//Temporarily initialized boards for playtesting until proper setup is configured.
const char p1board[NUM_ROWS][NUM_COLS] = {
'-', '-', 'c', 'c', 'c', 'c', 'c', '-', '-', '-',
'd', 'd', '-', '-', '-', '-', '-', '-', '-', '-',
'-', '-', '-', '-', '-', '-', '-', '-', '-', 's',
'-', '-', '-', '-', 'b', '-', '-', '-', '-', 's',
'-', '-', '-', '-', 'b', '-', '-', '-', '-', 's',
'-', '-', '-', '-', 'b', '-', '-', '-', '-', '-',
'-', '-', '-', '-', 'b', '-', '-', '-', '-', '-',
'-', '-', '-', 'r', 'r', 'r', '-', '-', '-', '-',
'-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'
};

const char p2board[NUM_ROWS][NUM_COLS] = {
'-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
'd', 'd', '-', '-', '-', '-', '-', '-', '-', '-',
'-', '-', '-', '-', '-', '-', 's', 's', 's', '-',
'-', 'r', '-', '-', '-', '-', '-', '-', '-', '-',
'-', 'r', '-', '-', '-', '-', '-', '-', '-', '-',
'-', 'r', '-', '-', '-', '-', '-', '-', '-', '-',
'-', 'r', '-', '-', '-', '-', 'b', 'b', 'b', 'b',
'-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
'-', '-', '-', 'c', 'c', 'c', 'c', 'c', '-', '-',
'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'
};
#endif

#endif
