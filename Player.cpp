#include "Player.h"
#define row 10
#define colomn 20

 
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included



 playerPos.setObjPos(
        (mainGameMechsRef->getBoardSizeX()) / 2,
        (mainGameMechsRef->getBoardSizeY()) / 2,
        '-'
    );//  starting position middle of board


}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
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
    // Finite State Machine logic for moving the player
 switch (myDir) {
    case UP:
        if (playerPos.y == 0) {
            playerPos.y = mainGameMechsRef->getBoardSizeY() - 1;
        } else {
            playerPos.y--;
        }
        break;
    case DOWN:
        if (playerPos.y == mainGameMechsRef->getBoardSizeY() - 1) {
            playerPos.y = 0;
        } else {
            playerPos.y++;
        }
        break;
    case LEFT:
        if (playerPos.x == 0) {
            playerPos.x = mainGameMechsRef->getBoardSizeX() - 1;
        } else {
            playerPos.x--;
        }
        break;
    case RIGHT:
        if (playerPos.x == mainGameMechsRef->getBoardSizeX() - 1) {
            playerPos.x = 0;
        } else {
            playerPos.x++;
        }
        break;
    case STOP:
        // Do nothing
        break;
}
}