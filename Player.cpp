#include "Player.h"
#define row 10
#define colomn 20

 
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included


 objPos tempPos;
 tempPos.setObjPos((mainGameMechsRef->getBoardSizeX()) / 2,
        (mainGameMechsRef->getBoardSizeY()) / 2,
        '*'
    );//  starting position middle of board


    
//playerPos.setObjPos(0,0,'*');//  starting position middle of board



playerPosList = new objPosArrayList();
playerPosList->insertHead(tempPos);



}


Player::~Player()
{
delete playerPosList;

}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  
    
    char input = mainGameMechsRef->getInput();

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

    // Finite State Machine logic for moving the player
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
        playerPosList->getElement(returnPos, 0); // Assuming 0 is the head of the player
    }
}


void Player::increasePlayerLength()

{
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

/*
bool Player::checkFoodConsumption() {
    objPos playerPos;
    objPos foodPos;

    // Get player position
    getPlayerPos(playerPos);

    // Get food position from GameMechs
    mainGameMechsRef->getFoodPos(foodPos);

    // Check if player position matches food position
    if (playerPos.x == foodPos.x && playerPos.y == foodPos.y) {
        return true;
    } else {
        return false;
    }
}
*/