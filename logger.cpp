/**
 * @file   logger.cpp
 * @author Edward S-J
 * @brief  
 * @date   04-20-2022
 * 
 */

#include "battleship.h"
#include <fstream>
using namespace std;

/**
 * @brief A class-based logging system
 */

class Logger {
	public:
        
        /**
         * @brief Inserts a line to describe how the player's ships were placed.
         * 
         * @param auto If the player placed their ships automatically.
         */
		void shipsPlaced(bool autoplace) {
			logFile << "Player's ships placed ";
			if (autoplace){
				logFile << "automatically.";
			} else {
				logFile << "manually.";
			}
			logFile << endl;
			return;
		}

        /**
         * @brief Logs a shot.
         * 
         * @param row, col: row and column of the shot being logged
         * @param hit: if the shot being logged hit something
         * @param mark: the character that the shot resulted in.
         */
		void addMove(int row, int col, bool hit, char mark) {
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

        // closes file - MUST BE CALLED AT END OF MAIN
		void finish() {
			logFile.close();
			return;
		};

        /**
         * @brief Construct a new Logger object.
         * 
         * @details When creating the object, the filename will be the current time in seconds
         */
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

