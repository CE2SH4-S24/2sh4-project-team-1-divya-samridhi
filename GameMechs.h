#ifndef GAMEMECHS_H
#define GAMEMECHS_H



#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

//using namespace std;


class GameMechs
{   

    private:

        char input;
        bool exitFlag;
        bool loseFLag;
        int score;
  
        int boardSizeX;
        int boardSizeY;

            Food food;


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


bool checkFoodConsumption(objPos playerPos, objPos foodPos);

};

#endif