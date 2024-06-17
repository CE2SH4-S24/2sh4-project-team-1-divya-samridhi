#include "GameMechs.h"
#include "MacUILib.h"

//where should we see the RNG
//#include "Project.cpp"

#include <ctime>
#include "GameMechs.h"


GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    boardSizeX = 20; // default board size
    boardSizeY = 10;

    score = 0;


  srand(time(NULL));

}

GameMechs::GameMechs(int boardX, int boardY)
{

    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;

    score = 0;
 //srand(time(NULL));
}

// do you need a destructor?
GameMechs::~GameMechs(){

}


// Exit Flag
void GameMechs::setExitTrue(){
    exitFlag = true;
}

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}


// Lose FLag / score
void GameMechs::setLoseFLag(){
    loseFLag = true;
}


int GameMechs::getScore(){
    return score;
}


void GameMechs::incrementScore(){
    score++;
}



// Input


char GameMechs::getInput()
{
     if (MacUILib_hasChar()){ //  checking if there was user input
       input =  MacUILib_getChar(); // store character input into variable
    }

    return input;

}


void GameMechs::setInput(char thisInput){
    input = thisInput;
}

void GameMechs::clearInput()
{
 input = '\0';
}


//board size
int GameMechs::getBoardSizeX()
{

    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
return boardSizeY;
}



void GameMechs::generateFood(objPos blockOff) {
    food.generateFood(blockOff);
}

void GameMechs::getFoodPos(objPos &returnPos) {
    food.getFoodPos(returnPos);
}

// Provide definitions of more member functions as required
// See Project Manual

bool GameMechs::Collision(objPos playerPos, objPos foodPos) {
    if(playerPos.x == foodPos.x && playerPos.y == foodPos.y){
        return true;
    } else{
        return false;
    }
}