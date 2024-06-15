#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

//#define column 20
//#define row 10


#define WIDTH 20
#define HEIGHT 9
#define BORDER '#'

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void){

    Initialize();

    while(myGM->getExitFlagStatus() == false)  {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
    return 0;

}


void Initialize(void){
    MacUILib_init();
    MacUILib_clearScreen();
    
    myGM = new GameMechs(20,10);
    myPlayer = new Player(myGM);

}


void GetInput() {
    char input;


   // myGM->clearInput();

    if (MacUILib_hasChar()){ //  checking if there was user input
       input =  MacUILib_getChar(); // store character input into variable
        myGM->setInput(input);
    }

    if (myGM->getInput() == 10){
        myGM->setExitTrue();
    }
}


void RunLogic(void){

    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
   
   myGM->clearInput();
}

void DrawScreen(void)
{
   
MacUILib_clearScreen();  

    objPos playerPos;
    myPlayer->getPlayerPos(playerPos);

    int i, j;
    for (i = 0; i < WIDTH; i++) {
        MacUILib_printf("%c", BORDER);
    }
    
    for (i = 0; i < HEIGHT - 2; i++) {
        MacUILib_printf("\n%c",BORDER);

        for (j = 0; j < WIDTH - 2; j++) {
            if (playerPos.x == j && playerPos.y == i) {
                MacUILib_printf("%c", playerPos.symbol); // Player's position
            } else {
                MacUILib_printf(" "); // Empty space
            }
        }

        MacUILib_printf("%c", BORDER);  
    }
    MacUILib_printf("\n");
    
    for (i = 0; i < WIDTH; i++) {
        MacUILib_printf("%c", BORDER);
    }

    MacUILib_printf("\n\nPress commands: 'w'-up, 's'-down, 'a'-left, 'd'-right.");   

    MacUILib_printf("\nBoardSize: %dx%d, Player Pos: (%d,%d) + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), playerPos.x, playerPos.y, playerPos.symbol);
    MacUILib_printf("\n\nPress 'enter' to exit.");
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete myGM; 
    myGM = NULL;
    delete myPlayer; 
    myPlayer = NULL;
}




