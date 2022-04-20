#include "battleship.h"

// Lance
/**
 * @brief Uses functions from hit.cpp to allow attacking ships
 *
 * @param board		 	  holds the board being attacked by player
 * @param hitMap		   Board that is displayed to player to be attacked
 */

void attack(char board[][NUM_COLS],char hitMap[][NUM_COLS])
{
    char rowChar;
    int col;
    cout<<"Enter the coordiantes of the space you would like to attack";
    cin>>rowChar;
        cin>>col;

      int row =rowChar-64;
    

   if (validShot(row-1,col-1,hitMap))
   {
     if(hitDetect(row-1,col-1,board)==1)
     {
         cout<<"Yarr you hit me ship";
         update(row-1,col-1,board,hitMap);
     }
     else
     {
         cout<<"Haha you missed me boat";
     }
   }

   else{
       cout<<"invalid shot\n";
   }
}