#include "GameMechs.h"
#include "MacUILib.h"
#include "GameMechs.h"

GameMechs::GameMechs(){
    input = 0;
    exitFlag = false;
    boardSizeX = 20; // default board size
    boardSizeY = 10;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY){
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
}

GameMechs::~GameMechs(){}

void GameMechs::setExitTrue(){
    exitFlag = true;
}

bool GameMechs::getExitFlagStatus(){
    return exitFlag;
}

void GameMechs::setLoseFLag(){
    loseFLag = true;
}

int GameMechs::getScore(){
    return score;
}

void GameMechs::incrementScore(int incrementAmount){
    score+= incrementAmount;
}

//  getting user input
char GameMechs::getInput(){
    if (MacUILib_hasChar()){ 
        input =  MacUILib_getChar(); 
    }
    return input;
}


void GameMechs::setInput(char thisInput){
    input = thisInput;
}

void GameMechs::clearInput(){
    input = '\0';
}

int GameMechs::getBoardSizeX(){
    return boardSizeX;
}

int GameMechs::getBoardSizeY(){
    return boardSizeY;
}

void GameMechs::generateFood(objPos blockOff) {
    food.generateFood(blockOff);
}

void GameMechs::getFoodPos(objPos &returnPos) {
    food.getFoodPos(returnPos);
}
