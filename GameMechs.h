#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib> //c++ standard librrary
#include <time.h> //c++ <time>, in c++ 

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{   
    // GameMechs is the Game Mechanism class
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:

        char input;
        bool exitFlag;
        bool loseFLag;
        int score;
  
        int boardSizeX;
        int boardSizeY;

        objPos foodPos;


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

        void incrementScore();

void generateFood(objPos blockOff); // Method to generate food
void getFoodPos(objPos &returnPos); // Method to get food position

};

#endif