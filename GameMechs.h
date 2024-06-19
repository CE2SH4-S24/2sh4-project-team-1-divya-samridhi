#ifndef GAMEMECHS_H
#define GAMEMECHS_H


#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class GameMechs
{   

    private:
        char input;
        bool exitFlag;
        bool loseFLag;
        int score;
  
        int boardSizeX;
        int boardSizeY;

        Food food; // create food of type Food


    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs();

        
        bool getExitFlagStatus();
        void setExitTrue();

        bool getLoseFlagStatus();
        void setLoseFLag();


        char getInput();
        void setInput(char thisInput);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();

        int getScore();

        void incrementScore(int incrementAmount);

        void generateFood(objPos blockOff); 
        void getFoodPos(objPos &returnPos); 

};

#endif
