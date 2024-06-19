#include "Player.h"
#include "Food.h"
#include "GameMechs.h"

#define row 10
#define colomn 20

extern GameMechs* myGM; // Declare myGM as an external variable

Player::Player(GameMechs* thisGMRef, Food* foodRef){
    mainGameMechsRef = thisGMRef;
    myFood = foodRef; // this is to link the food with player, the same as how gamemechanics was linked with player
    myDir = STOP;
  
    objPos tempPos;
    tempPos.setObjPos((mainGameMechsRef->getBoardSizeX()-1) / 2,(mainGameMechsRef->getBoardSizeY()-1) / 2, '*');//  starting position middle of board

    playerPosList = new objPosArrayList(); // create objarray list for player
    playerPosList->insertHead(tempPos); // add initial head element
}

Player::~Player(){
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos(){
    return playerPosList; // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir(){ 
    char input = mainGameMechsRef->getInput(); // get input from user from game mechanics

    switch (input) {
        case 'w': // go up
            if (myDir != DOWN) {
                myDir = UP;
            }
            break;

        case 'a': // go left
            if (myDir != RIGHT) {
                myDir = LEFT;
            }
            break;

        case 's': // go down
            if (myDir != UP) {
                myDir = DOWN;
            }
            break;

        case 'd': // go right
            if (myDir != LEFT) {
                myDir = RIGHT;
            }
            break;
    }
}

void Player::movePlayer() {
    objPos currHead;
    playerPosList->getHeadElement(currHead);  

    // Finite State Machine logic for moving the player (turning logic)
    switch (myDir) {
        case UP:
            if (currHead.getY() == 0) {
                currHead.setObjPos(currHead.getX(), mainGameMechsRef->getBoardSizeY() - 3, currHead.getSymbol());
            } else {
                currHead.setObjPos(currHead.getX(), currHead.getY() - 1, currHead.getSymbol());
            }
            break;

        case DOWN:
            if (currHead.getY() == mainGameMechsRef->getBoardSizeY() - 3) { 
                currHead.setObjPos(currHead.getX(), 0, currHead.getSymbol());
            } else {
                currHead.setObjPos(currHead.getX(), currHead.getY() + 1, currHead.getSymbol());
            }
            break;
        case LEFT:
            if (currHead.getX() == 0) {
                currHead.setObjPos(mainGameMechsRef->getBoardSizeX() - 3, currHead.getY(), currHead.getSymbol());
            } else {
                currHead.setObjPos(currHead.getX() - 1, currHead.getY(), currHead.getSymbol());
            }
            break;
        case RIGHT:
            if (currHead.getX() == mainGameMechsRef->getBoardSizeX() - 3) {
                currHead.setObjPos(0, currHead.getY(), currHead.getSymbol());
            } else {
                currHead.setObjPos(currHead.getX() + 1, currHead.getY(), currHead.getSymbol());
            }
            break;
        case STOP:
            // Do nothing
            break;
    }
    playerPosList->insertHead(currHead);
    playerPosList->removeTail();
}

void Player::getPlayerPos(objPos &returnPos) {
    if (playerPosList->getSize() > 0) {
        playerPosList->getElement(returnPos, 0); // poisiton of head
    }
}

void Player::increasePlayerLength(){
    objPos tail;
    playerPosList->getTailElement(tail);
    playerPosList->insertTail(tail); 
}

bool Player:: checkSelfCollision(){
    objPos head;
    playerPosList->getHeadElement(head);

    for (int i = 1; i < playerPosList->getSize(); i++) {
        objPos body;
        playerPosList->getElement(body, i);
        
        if (head.getX() == body.getX() && head.getY() == body.getY()) {
            return true;
        }
    }
    return false; 
}


bool Player::checkFoodConsumption() {
    objPos head;
    playerPosList->getHeadElement(head); 

        
    //check for collision between Player's head and food
     for (int i = 0; i < myFood->getNumFoodBucketElements(); ++i) {
        objPos currentFood;
        myFood->getFoodBucketElement(currentFood, i);

        if (head.getX() == currentFood.getX() && head.getY() == currentFood.getY()) {
            // Check if the current food is special
            if (myFood->isSpecialFood(i)) {
                myGM->incrementScore(50); // Example: Score 50 points for special food
                increasePlayerLength();   // Increase player's length for special food
            } else {
                myGM->incrementScore(10); // Example: Score 10 points for normal food
                increasePlayerLength();   // Increase player's length for normal food
            }

            // Remove consumed food from the bucket
            myFood->removeFoodBucketElement(i);
           

            // Generate new food items
            objPos blockOff(20, 10, 'o');
            myFood->generateFood(blockOff);

            return true;
        }
    }
    return false; //no collision
}

    

        

        