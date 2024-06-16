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


// for debug
playerPosList->insertHead(tempPos);
playerPosList->insertHead(tempPos);
playerPosList->insertHead(tempPos);
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
        if (currHead.y == 0) {
            currHead.y = mainGameMechsRef->getBoardSizeY() - 3;
        } else {
            currHead.y--;
        }
      


        break;
    case DOWN:
        if (currHead.y == mainGameMechsRef->getBoardSizeY() - 3) {
            currHead.y = 0;
        } else {
            currHead.y++;
        }
        break;
    case LEFT:
        if (currHead.x == 0) {
           currHead.x = mainGameMechsRef->getBoardSizeX() - 3;
        } else {
           currHead.x--;
        }
        break;
    case RIGHT:
        if (currHead.x == mainGameMechsRef->getBoardSizeX() - 3) {
            currHead.x = 0;
        } else {
            currHead.x++;
        }
        break;
    case STOP:
        // Do nothing
        break;
}


playerPosList->insertHead(currHead);
playerPosList->removeTail();

}