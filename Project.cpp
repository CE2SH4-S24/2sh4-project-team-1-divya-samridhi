#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"
#include "Food.h"


#define WIDTH 20
#define HEIGHT 10
#define BORDER '#'

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM= nullptr;
Player* myPlayer= nullptr;
Food* myFood;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void){
    Initialize();
    while(myGM->getExitFlagStatus() == false){
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
    
    //create objects on heap
    myGM = new GameMechs(20,10);
    myFood = new Food();
    myPlayer = new Player(myGM, myFood);
 
    objPos blockOff(20,10,'o');
    objPos foodPos;
    myFood->generateFood(blockOff); // Generate initial food

// intializae random food at start
    myFood->generateFood(blockOff); 
    myGM->generateFood(blockOff); 
}

void GetInput() {
    char input;

    if (MacUILib_hasChar()){ //  checking if there was user input
       input =  MacUILib_getChar(); // store character input into variable
        myGM->setInput(input);
    }

    if (myGM->getInput() == 10){ // check for enter key press as signal to close screen
        myGM->setExitTrue();
    }
}


void RunLogic(void){
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    if (myPlayer->checkSelfCollision() == true) {
        myGM->setExitTrue();
        return; 
    }
    
    if (myPlayer->checkFoodConsumption()) {
        DrawScreen();
    }
    myGM->clearInput();
}

void DrawScreen(void){
   
    MacUILib_clearScreen();  
    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;
    objPos foodPos;

    myFood->getFoodPos(foodPos);
    MacUILib_printf("\nWelcome to Divya & Samridhi's Final COMPENG 2SH4 Project :)\n"); 

    int i, j;
    for (i = 0; i < WIDTH; i++) {
        MacUILib_printf("%c", BORDER);
    }
    
    for (i = 0; i < HEIGHT - 2; i++) {
        MacUILib_printf("\n%c", BORDER);


        for (j = 0; j < WIDTH - 2; j++) {
            drawn = false;

            //draw player body
            for (int k = 0; k<playerBody->getSize(); k++){
                playerBody->getElement(tempBody, k);

                if(tempBody.getX() == j && tempBody.getY() ==i){
                    MacUILib_printf("%c", tempBody.getSymbol());
                    drawn = true;
                    break;
                }
            }
            if(drawn == true){ // if player body was drawn dont draw anything below
                continue;
            }

            // Draw food items
            for (int k = 0; k < myFood->getNumFoodBucketElements(); k++) {
                myFood->getFoodBucketElement(foodPos, k);

                if (foodPos.getX() == j && foodPos.getY() == i) {
                    MacUILib_printf("%c", foodPos.getSymbol());
                    drawn = true;
                    break;
                }
            }
            if (!drawn) { // If nothing was drawn at this position
                MacUILib_printf(" ");
            }
        }

        MacUILib_printf("%c", BORDER);
    }  
    MacUILib_printf("\n");
    
    for (i = 0; i < WIDTH; i++) {
        MacUILib_printf("%c", BORDER);
    }
    
    //MacUILib_printf("\nfood pos: %d, %d", foodPos.getX(),foodPos.getY()); // Player's position
    MacUILib_printf("\nScore:%d", myGM->getScore());   
    MacUILib_printf("\n\nPress commands: 'w'-up, 's'-down, 'a'-left, 'd'-right.");   
  

 //   MacUILib_printf("\nBoardSize: %dx%d, Player Pos: (%d,%d) + %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempBody.getX(), tempBody.getY(), tempBody.getSymbol());
    MacUILib_printf("\nPress 'enter' to exit.");
}


void LoopDelay(void){
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void){

    MacUILib_clearScreen();    
    MacUILib_uninit();
//delete all heap members
    delete myGM; 
    myGM = NULL;
    delete myPlayer; 
    myPlayer = NULL;
    delete myFood; 
    myFood = NULL;

}
