/**
 * @file   global.h
 * @author Kellen West
 * @brief  Definition of all global values.
 * @date   04-20-2022
 * 
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

//#define TESTING

// Global variables and arrays useful in the program
const int NUM_ROWS = 10;  // number of rows of the battleship game board
const int NUM_COLS = 10;  // number of columns of the battleship game board
const int NUM_SHIPS = 5;  // number of ships in the battleship game

// Each of the ships information in 3 arrays (parallel arrays)
const string SHIP_NAMES[] = {"carrier", "battleship", "cruiser", "submarine", "destroyer"};
const char SHIP_SYMBOLS[] = {'c', 'b', 'r', 's', 'd'};
const int SHIP_SIZES[] = {5, 4, 3, 3, 2};

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
