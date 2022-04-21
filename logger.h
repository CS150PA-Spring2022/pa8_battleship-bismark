/**
 * @file   logger.h
 * @author Edward S-J
 * @brief  
 * @date   04-20-2022
 * 
 */

#ifndef LOGGER_H
#define LOGGER_H

#include "battleship.h"

/**
 * @brief A class-based logging system
 */

class Logger {
	public:
		void shipsPlaced(bool autoplace);

		void addMove(int row, int col, bool hit, char mark);

		void finish();

		Logger() {
			string fname;
			time_t ref = time(NULL);
			fname = ctime(&ref);
			logFile.open(fname);
			logFile << "Boards initialized at " << fname << "." << endl;
			playerTurn = true;
		};

	private:
		fstream logFile;
		bool playerTurn;
};

#endif