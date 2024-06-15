#include "GameMechs.h"
#include "MacUILib.h"

//where should we see the RNG
//#include "Project.cpp"


GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    boardSizeX = 20; // default board size
    boardSizeY = 10;

    //loseFlag = false;
    score = 0;

   // foodPos.setPos(-1,-1,'*'); // initialize the game board


}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    
    //loseFlag = false;
    score = 0;

 //   foodPos.setPos(-1,-1,'*');

}

// do you need a destructor?
GameMechs::~GameMechs(){
// nothing in iteration 1 to deallocate
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



 void GameMechs::generateFood(objPos){
    //generate x and y coordinate
    //not on boarder
    //no clash with player (block off)
    //check against the player position
    //in the object position class we have isequal method, use it!!
    //srand in here?
 }


// Provide definitions of more member functions as required
// See Project Manual